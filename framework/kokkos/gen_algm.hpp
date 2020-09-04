#ifndef GEN_ALGM_HPP
#define GEN_ALGM_HPP

template<class Device>
KOKKOS_INLINE_FUNCTION void perform_elitist_selection(const member_type& team_member, const Generation<Device>& current, const Generation<Device>& next, const DockingParams<Device>& docking_params);

template<class Device>
KOKKOS_INLINE_FUNCTION void crossover(const member_type& team_member, const Generation<Device>& current, const DockingParams<Device>& docking_params, const GeneticParams& genetic_params, const int run_id, TenFloat randnums, TwoInt parents, Genotype offspring_genotype);

template<class Device>
KOKKOS_INLINE_FUNCTION void mutation(const member_type& team_member, const DockingParams<Device>& docking_params, const GeneticParams& genetic_params, Genotype offspring_genotype);

template<class Device>
void gen_alg_eval_new(Generation<Device>& current, Generation<Device>& next, Dockpars* mypars,DockingParams<Device>& docking_params,GeneticParams& genetic_params,Constants<Device>& consts);


#include "gen_algm.tpp"

#endif
