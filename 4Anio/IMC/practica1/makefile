CXXFLAGS += -Wall -Wextra -O3
DEBUG += -g

all: practica1IMC

clean:
	rm -rf *.o practica1IMC

PerceptronMulticapa.o: PerceptronMulticapa.cpp PerceptronMulticapa.h
		$(CXX) $(CXXFLAGS) -c PerceptronMulticapa.cpp

practica1IMC: PerceptronMulticapa.o practica1.hpp practica1.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@
	rm -rf *.o
