# miniAutoDock-GPU 
# ================ 

 A miniapp based on AutoDock-GPU https://github.com/ccsb-scripps/AutoDock-GPU\ 

This app mainly focuses the performance portability and targets NVIDIA and AMD GPUs 
 

# Programming Base (API/ Model) 

* CUDA 
* HIP 
* Kokkos 

 

# Compilation 

```zsh 
make DEVICE=<TYPE> NUMWI=<NWI> CARD=<VENDOR> 
``` 
|  Prameters | Description            | Values                                             |
|:----------:|:----------------------:|:--------------------------------------------------:|
| `<TYPE>`   | Accelerator chosen     | `CPU`, `GPU`                                       |
| `<NWI>`    | OpenCL work-group size | `1`, `2`, `4`, `8`, `16`, `32`, `64`, `128`, `256` |
| `<CARD>`   | GPU vendor/typ         | `NVIDIA`, `AMD`                                    |


After successful compilation, the host binary **autodock_&lt;type&gt;_&lt;N&gt;wi** is placed under [bin](./bin).

| Binary-name portion | Description            | Values                                            |
|:-------------------:|:----------------------:|:-------------------------------------------------:|
| **&lt;type&gt;**    | Accelerator chosen     | `gpu`                                      |
| **&lt;N&gt;**       | OpenCL work-group size | `1`, `2`, `4`, `8`,`16`, `32`, `64`, `128`, `256` |



## Basic command 

```zsh 
./bin/autodock_<type>_<N>wi \ 
-ffile <protein>.maps.fld \ 
-lfile <ligand>.pdbqt \ 
-nrun <nruns> 
``` 

| Mandatory options | Description   | Value                     |
|:-----------------:|:-------------:|:-------------------------:|
| -ffile            |Protein file   |&lt;protein&gt;.maps.fld   |
| -lfile            |Ligand file    |&lt;ligand&gt;.pdbqt       |
| -nrun		    |               |                           |	

## Example 

```zsh 
./bin/autodock_gpu_64wi \ 
-ffile ./input/1stp/derived/1stp_protein.maps.fld \ 
-lfile ./input/1stp/derived/1stp_ligand.pdbqt \ 
-nrun 10 
``` 

 

 
