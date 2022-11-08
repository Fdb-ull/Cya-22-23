# Usage
# make 		# Compile all binary
# make clean 		# Remove ALL binaries and objects
CXXFLAGS = -g

CXX = g++
OBJS = $(TARGET).o automata.o estado.o transicion.o alfabeto.o cadena.o simbolo.o
TARGET = cya-P06_fa_simulator
NAME = p06_automata_simulator

$(TARGET): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(TARGET).o: $(TARGET).cc
	@$(CXX) -c $(CXXFLAGS) $(TARGET).cc

main.o : main.cc main.h
	@$(CXX) -c $(CXXFLAGS) main.cc

automata.o : automata.cc automata.h
	@$(CXX) -c $(CXXFLAGS) automata.cc

estado.o : estado.cc estado.h
	@$(CXX) -c $(CXXFLAGS) estado.cc

transicion.o : transicion.cc transicion.h
	@$(CXX) -c $(CXXFLAGS) transicion.cc

alfabeto.o : alfabeto.cc alfabeto.h
	@$(CXX) -c $(CXXFLAGS) alfabeto.cc

cadena.o : cadena.cc cadena.h
	@$(CXX) -c $(CXXFLAGS) cadena.cc
	
simbolo.o : simbolo.cc simbolo.h
	@$(CXX) -c $(CXXFLAGS) simbolo.cc

.PHONY: clean

clean: 
	rm -rvf main.o main
	clear

run:
	clear 
	./$(NAME) input.fa input.txt