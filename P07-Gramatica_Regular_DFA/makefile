# Usage
# make 		# Compile all binary
# make clean 		# Remove ALL binaries and objects
CXXFLAGS = -g

CXX = g++
OBJS = $(TARGET).o simbolo.o cadena.o alfabeto.o transicion.o estado.o grammar.o automata.o production.o
TARGET = cya-P07_dfa2grammar
NAME = p07_dfa2grammar

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(TARGET).o: $(TARGET).cc
	$(CXX) -c $(CXXFLAGS) $(TARGET).cc

automata.o : automata.cc automata.h 
	$(CXX) -c $(CXXFLAGS) automata.cc

grammar.o: grammar.cc grammar.h
	$(CXX) -c $(CXXFLAGS) grammar.cc

production.o: production.cc production.h
	$(CXX) -c $(CXXFLAGS) production.cc

estado.o : estado.cc estado.h
	$(CXX) -c $(CXXFLAGS) estado.cc

transicion.o : transicion.cc transicion.h
	$(CXX) -c $(CXXFLAGS) transicion.cc

alfabeto.o : alfabeto.cc alfabeto.h
	$(CXX) -c $(CXXFLAGS) alfabeto.cc

cadena.o : cadena.cc cadena.h
	$(CXX) -c $(CXXFLAGS) cadena.cc
	
simbolo.o : simbolo.cc simbolo.h
	$(CXX) -c $(CXXFLAGS) simbolo.cc

.PHONY:

clean: 
	rm -f $(OBJS) $(NAME)

run:
	clear 
	./$(NAME) inputdfa.fa output.gra
