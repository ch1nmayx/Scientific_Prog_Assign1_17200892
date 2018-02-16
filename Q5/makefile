CC = cc
FC = gfortran
FFLAGS = -fno-underscoring
DEPS = integration_include.h
CODES = numericalIntegration.c degtorad.c Gaussian_Quad.c SimpsonsFunction.c Trapez.c

# EXTRA_FLAGS is specific to opt. It will then be used for all prerequisites
opt: EXTRA_FLAGS += -O3


cprogCfunc: numericalIntegration.c degtorad.c Gaussian_Quad.c SimpsonsFunction.c Trapez.c
	$(CC) -c numericalIntegration.c; $(CC) -c degtorad.c Gaussian_Quad.c SimpsonsFunction.c Trapez.c; \
	$(CC) -o $@ numericalIntegration.o degtorad.o Gaussian_Quad.o SimpsonsFunction.o Trapez.o

clean:
	/bin/rm -f *.o $(CODES)

