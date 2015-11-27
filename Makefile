# Makefile for Binary Differential Evolution for Pedsim
#
# ************************************************************
# Parameters to control Makefile operation

CXX = g++
CXXFLAGS =

# ************************************************************
# Entries to bring the executable up to date

test: test.o population.o individual.o base.o randpack.o
	$(CXX) $(CXXFLAGS) -o test test.o population.o individual.o base.o randpack.o

test.o: randpack.h base.h individual.h population.h

population.o: population.h individual.h base.h randpack.h

individual.o: individual.h base.h randpack.h

base.o: base.h

randpack.o: randpack.h


# ************************************************************
# Make Clean
clean:
	rm *.o 
