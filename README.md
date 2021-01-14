# miniAutoDock-GPU 

 A miniapp based on AutoDock-GPU https://github.com/ccsb-scripps/AutoDock-GPU 

This app mainly focuses the performance portability and targets NVIDIA and AMD GPUs 

# Programming Base (API/ Model) 

* CUDA 
* HIP 
* Kokkos  

# Compilation in General

```zsh 
make DEVICE=<TYPE> API=<SUPPORT> CARD=<VENDOR> NUMWI=<NWI>  
``` 
|  Prameters | Description            | Values                                             |
|:----------:|:----------------------:|:--------------------------------------------------:|
| `<TYPE>`   | Accelerator chosen     | `CPU`, `GPU`                                       |
| `<SUPPORT>`   | API chosen     | `CUDA`, `HIP`, `KOKKOS`                                       |
| `<VENDOR>`   | GPU vendor/type         | `NVIDIA`, `AMD`                                    |
| `<NWI>`    | work-group size | `1`, `2`, `4`, `8`, `16`, `32`, `64`, `128`, `256` |


After successful compilation, the host binary **autodock_&lt;type&gt;_&lt;N&gt;wi** is placed under [bin](./bin).

| Binary-name portion | Description            | Values                                            |
|:-------------------:|:----------------------:|:-------------------------------------------------:|
| **&lt;type&gt;**    | Accelerator chosen     | `gpu`                                      |
| **&lt;N&gt;**       | work-group size | `1`, `2`, `4`, `8`,`16`, `32`, `64`, `128`, `256` |


# Build
+ CUDA version
  Prerequisites: cuda and gcc 
  Build: define the environment varables GPU_LIBRARY_PATH and GPU_INCLUDE_PATH 
         make API=CUDA 
  Example: build on summit 
  ```zsh
  module load cuda 
  export GPU_LIBRARY_PATH=/sw/summit/cuda/10.1.243/lib64 
  export GPU_INCLUDE_PATH=/sw/summit/cuda/10.1.243/include 
  make API=CUDA 
  ```
* HIP version
  Prerequisites: rocm, cuda, and gcc 
  Build: define the environment varables HIP_PLATFORM, GPU_LIBRARY_PATH and GPU_INCLUDE_PATH 
         make API=HIP CARD=AMD 
  Example: build on CoE 
  ```zsh
  ROCMV=3.7.0 
  PLATFORM=hcc 
  module load rocm/${ROCMV} cuda10.2/toolkit 
  export HIP_PLATFORM=${PLATFORM} 
  export GPU_LIBRARY_PATH=/opt/rocm-${ROCMV}/lib 
  export GPU_INCLUDE_PATH=/opt/rocm-${ROCMV}/include 
  make API=HIP CARD=AMD 
  ```
@ Kokkos version
  Prerequisites: built kokkos, rocm, cuda, and gcc 
  Build: define the environment varables KOKKOS_SRC_DIR, KOKKOS_LIB_PATH and KOKKOS_INC_PATH 
         make API=KOKKOS DEVICE=GPU  CARD=AMD 
  Example: build kokkos with HIP backend version on CoE 
  ```zsh
  ROCMV=3.7.0 
  module load rocm/${ROCMV} cuda10.2/toolkit 
  export KOKKOS_SRC_DIR=/home/users/coe0179/kokkos 
  export KOKKOS_INC_PATH=/home/users/coe0179/kokkos/include/ 
  export KOKKOS_LIB_PATH=/home/users/coe0179/kokkos/lib64/ 
  make API=KOKKOS DEVICE=GPU  CARD=AMD
  ```

## Basic command 

```zsh 
./bin/autodock_<type>_<N>wi \ 
-lfile <ligand>.pdbqt \ 
-nrun <nruns> 
``` 

| Mandatory options | Description   | Value                     |
|:-----------------:|:-------------:|:-------------------------:|
| -lfile            |Ligand file    |&lt;ligand&gt;.pdbqt       |
| -nrun		    | # LGA runs    |&lt;nruns&gt;              |	

## Example 

```zsh 
./bin/autodock_gpu_64wi \ 
-lfile ./input/7cpa/7cpa_ligand.pdbqt  \ 
-nrun 10 
``` 

 

 
