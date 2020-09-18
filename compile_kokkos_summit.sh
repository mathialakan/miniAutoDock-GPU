#!/bin/bash


 module load pgi/19.9 cuda/10.1.243

 export KOKKOS_SRC_DIR=/ccs/home/mathit/kokkos
 export KOKKOS_INC_PATH=/ccs/home/mathit/kokkos/install/include/
 export KOKKOS_LIB_PATH=/ccs/home/mathit/kokkos/install/lib/

# export KOKKOS_SRC_DIR=/autofs/nccs-svm1_sw/summit/.swci/1-compute/opt/spack/20180914/linux-rhel7-ppc64le/xl-16.1.1-5/kokkos-3.0.00-5uh3tul7pohep6k3jouxqyb5atitwhzh
# export KOKKOS_INC_PATH=/autofs/nccs-svm1_sw/summit/.swci/1-compute/opt/spack/20180914/linux-rhel7-ppc64le/xl-16.1.1-5/kokkos-3.0.00-5uh3tul7pohep6k3jouxqyb5atitwhzh/include
# export KOKKOS_LIB_PATH=/autofs/nccs-svm1_sw/summit/.swci/1-compute/opt/spack/20180914/linux-rhel7-ppc64le/xl-16.1.1-5/kokkos-3.0.00-5uh3tul7pohep6k3jouxqyb5atitwhzh/lib64

 make API=KOKKOS DEVICE=GPU CARD=NVIDIA

