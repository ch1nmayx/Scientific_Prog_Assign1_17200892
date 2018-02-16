CC = cc
FC = gfortran
FFLAGS = -fno-underscoring
CODES = SimpsonsRule.c

# EXTRA_FLAGS is specific to opt. It will then be used for all prerequisites
opt: EXTRA_FLAGS += -O3


SimpsonsRule: SimpsonsRule.c
	$(CC) $(EXTRA_FLAGS) -o $@ SimpsonsRule.c -lm

clean:
	/bin/rm -f *.o $(CODES)

