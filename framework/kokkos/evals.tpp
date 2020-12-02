/*

AutoDock-GPU, an OpenCL implementation of AutoDock 4.2 running a Lamarckian Genetic Algorithm
Copyright (C) 2017 TU Darmstadt, Embedded Systems and Applications Group, Germany. All rights reserved.
For some of the code, Copyright (C) 2019 Computational Structural Biology Center, the Scripps Research Institute.

AutoDock is a Trade Mark of the Scripps Research Institute.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

*/
// TODO - templatize ExSpace - ALS
template<class Device>
void sum_evals(Dockpars* mypars,DockingParams<Device>& docking_params,Kokkos::View<int*,DeviceType> evals_of_runs)
{
        // Outer loop over mypars->num_of_runs
        int league_size = mypars->num_of_runs;
        Kokkos::parallel_for (Kokkos::TeamPolicy<ExSpace> (league_size, NUM_OF_THREADS_PER_BLOCK ),
                        KOKKOS_LAMBDA (member_type team_member)
        {
                // Get team and league ranks
                int tidx = team_member.team_rank();
                int lidx = team_member.league_rank();

                // Reduce new_entities
                int sum_evals;
                Kokkos::parallel_reduce (Kokkos::TeamThreadRange (team_member, docking_params.pop_size),
                [=] (int& idx, int& l_evals) {
                        l_evals += docking_params.evals_of_new_entities(lidx*docking_params.pop_size + idx);
                }, sum_evals);

               // team_member.team_barrier();

                // Add to global view
                if( tidx == 0 ) {
                        evals_of_runs(lidx) += sum_evals;
                }
        });
}
