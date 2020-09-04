#ifndef EVALS_HPP
#define EVALS_HPP

template<class Device>
void evals(Dockpars* mypars,DockingParams<Device>& docking_params,Kokkos::View<int*,DeviceType> evals_of_runs);

#include "evals.tpp"

#endif
