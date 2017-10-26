
COMP = g++
FLAGS = -std=c++11 -Wall -pedantic -Ofast -funroll-loops -march=native
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
DPND = $(SRC:.cpp=.d)

sudokuSolver : $(OBJ)
	$(COMP) $(FLAGS) $^ -o $@
	
%.o: %.cpp
	$(COMP) $(FLAGS) -MMD -MP -c $< -o $@

clean:
	rm  *.d *.o
	
cleanall:
	rm  *.d *.o sudokuSolver
	
-include $(DPND)

