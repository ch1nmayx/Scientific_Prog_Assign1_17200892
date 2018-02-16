CC = cc
FC = gfortran
FFLAGS = -fno-underscoring
CODES = Determinant

# EXTRA_FLAGS is specific to opt. It will then be used for all prerequisites
opt: EXTRA_FLAGS += -O3


Determinant: Determinant.c
	$(CC) $(EXTRA_FLAGS) -o $@ Determinant.c

clean:
	/bin/rm -f *.o $(CODES)

