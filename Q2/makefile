CC = cc
FC = gfortran
FFLAGS = -fno-underscoring
CODES = Collatz_Conjecture

# EXTRA_FLAGS is specific to opt. It will then be used for all prerequisites
opt: EXTRA_FLAGS += -O3


Collatz_Conjecture: Collatz_Conjecture.c
	$(CC) $(EXTRA_FLAGS) -o $@ Collatz_Conjecture.c

clean:
	/bin/rm -f *.o $(CODES)




