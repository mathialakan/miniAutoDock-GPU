#ifndef INIT_POP_HPP
#define INIT_POP_HPP

template<class Device>
void calc_init_pop(Generation<Device>& current, Dockpars* mypars,DockingParams<Device>& docking_params,Constants<Device>& consts);

#include "init_pop.tpp"

#endif
