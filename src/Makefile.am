@SET_MAKE@

AUTOMAKE_OPTIONS = foreign no-dependencies
NVCC = @CUDA_CC@
NVCC_FLAGS = @CUDA_CFLAGS@

OCCBUILD = @OCCBUILD@

EXTRA_DIST = gpuboids.occ \
		gpuboids_cuda.inc \
		gpuboids_params.inc \
		occoids_cuda.cu

if BUILD_CUDA
cuda_progs = \
	gpuboids
endif

examples = $(cuda_progs)

all-local: $(examples)

clean-local:
	$(OCCBUILD) --clean $(examples) occoids_cuda.o

gpuboids: gpuboids.occ gpuboids_params.inc gpuboids_cuda.inc occoids_cuda.o
	$(OCCBUILD) --program $(srcdir)/gpuboids.occ occoids_cuda.o

SUFFIXES = .occ .cu

.occ:
	$(OCCBUILD) --program $<

.cu.o:
	$(NVCC) $(NVCC_FLAGS) -c $<

