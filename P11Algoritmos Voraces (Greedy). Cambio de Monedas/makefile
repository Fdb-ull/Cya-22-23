# Usage
# make 		# Compile all binary
# make clean 		# Remove ALL binaries and objects
CXXFLAGS = -g -std=c++11 

CXX = g++
OBJS = $(TARGET).o cambioMonedas.o
TARGET = mainGreedy
NAME = mainGreedy

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(TARGET).o: $(TARGET).cc
	$(CXX) -c $(CXXFLAGS) $(TARGET).cc

cambioMonedas.o : cambioMonedas.cc cambioMonedas.h
	$(CXX) -c $(CXXFLAGS) cambioMonedas.cc

.PHONY:

clean: 
	rm -f $(OBJS) $(NAME)

run:
	clear 
	./$(NAME) 5.54
