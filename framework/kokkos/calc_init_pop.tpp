#include "calcenergy.hpp"
#include "genotype_funcs.hpp"

// TODO - templatize ExSpace - ALS
template<class Device>
void calc_init_pop(Generation<Device>& current, Dockpars* mypars,DockingParams<Device>& docking_params,Constants<Device>& consts)
{
	// Outer loop over mypars->pop_size * mypars->num_of_runs
        int league_size = mypars->pop_size * mypars->num_of_runs;

	// Get the size of the shared memory allocation
	size_t shmem_size = Coordinates::shmem_size(docking_params.num_of_atoms) + Genotype::shmem_size(docking_params.num_of_genes);
        Kokkos::parallel_for (Kokkos::TeamPolicy<ExSpace> (league_size, NUM_OF_THREADS_PER_BLOCK ).
                              set_scratch_size(KOKKOS_TEAM_SCRATCH_OPT,Kokkos::PerTeam(shmem_size)),
                              KOKKOS_LAMBDA (member_type team_member)
        {
                // Get team and league ranks
                int tidx = team_member.team_rank();
                int lidx = team_member.league_rank();

		// Determine which run this team is doing - note this is a floor since integer division
		int run_id = lidx/docking_params.pop_size;

		// Have to declare this outside calc_energy since Solis-Wets has energy calc in a loop
		Coordinates calc_coords(team_member.team_scratch(KOKKOS_TEAM_SCRATCH_OPT),docking_params.num_of_atoms);
		
		Genotype genotype(team_member.team_scratch(KOKKOS_TEAM_SCRATCH_OPT),docking_params.num_of_genes);
		copy_genotype(team_member, docking_params.num_of_genes, genotype, current, lidx);
	//	deep_copy(current.conformations, genotype);

		team_member.team_barrier();

		// Get the current energy for each run
		float energy = calc_energy(team_member, docking_params, consts, calc_coords, genotype, run_id);

		// Copy to global views
                if( tidx == 0 ) {
                        current.energies(lidx) = energy;
                        docking_params.evals_of_new_entities(lidx) = 1;
                }
        });
}
