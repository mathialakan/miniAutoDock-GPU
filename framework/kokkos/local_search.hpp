#ifndef LOCAL_SEARCH_HPP
#define LOCAL_SEARCH_HPP

template<class Device>
void solis_wets(Generation<Device>& next, Dockpars* mypars,DockingParams<Device>& docking_params,Constants<Device>& consts);

#include "local_search.tpp"

#endif
