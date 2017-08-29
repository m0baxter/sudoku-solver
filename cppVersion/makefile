
COMP = g++
FLAGS = -std=c++11 -Wall -pedantic -Ofast -funroll-loops -march=native
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
DPND = $(SRC:.cpp=.d)

sudokuSolver : $(OBJ)
	$(COMP) $(FLAGS) $^ -o $@
	
%.o: %.cpp
	$(COMP) $(FLAGS) -MMD -MP -c $< -o $@

sudokuSolver.o : .cpp wavefunction.hpp makefile
	        $(COMP) -c $(FLAGS) main.cpp
clean:
	rm  *.d *.o
	
cleanall:
	rm  *.d *.o main
	
-include $(DPND)

