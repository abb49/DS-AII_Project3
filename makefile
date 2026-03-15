CXX = g++
CXXFLAGS = -std=c++11

OBJS = main.o Genetic.o Tours.o BruteForce.o matrix.o

p :	${OBJS}
	${CXX} $(CXXFLAGS) -o $@ ${OBJS}

main.o : main.cpp matrix.hpp time.hpp Tours.hpp Genetic.hpp BruteForce.hpp
	${CXX} ${CXXFLAGS} -c main.cpp

matrix.o : matrix.hpp
	${CXX} ${CXXFLAGS} -c matrix.cpp
time.o : time.hpp
	${CXX} ${CXXFLAGS} -c time.hpp
Tours.o : Tours.hpp
	${CXX} ${CXXFLAGS} -c Tours.cpp
Genetic.o : Genetic.hpp Tours.hpp time.hpp matrix.hpp
	${CXX} ${CXXFLAGS} -c Genetic.cpp
BruteForce.o : BruteForce.hpp Tours.hpp time.hpp matrix.hpp
	${CXX} ${CXXFLAGS} -c BruteForce.cpp


clean: 
	rm -f *.o