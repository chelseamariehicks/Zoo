
#Variables
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -g
HEADERS = Zoo.hpp Animal.hpp Tiger.hpp Penguin.hpp Turtle.hpp
SRCS = Zoo.cpp Animal.cpp Tiger.cpp Penguin.cpp Turtle.cpp zooTycoonMain.cpp
OBJS = zooTycoonMain.o Zoo.o Animal.o Tiger.o Penguin.o Turtle.o

#Targets
zooTycoon: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o zooTycoon

zooTycoonMain.o: zooTycoonMain.cpp Zoo.hpp
	${CXX} ${CXXFLAGS} -c zooTycoonMain.cpp

Zoo.o: Zoo.cpp Zoo.hpp Animal.hpp Tiger.hpp Penguin.hpp Turtle.hpp
	${CXX} ${CXXFLAGS} -c Zoo.cpp

Animal.o: Animal.cpp Animal.hpp
	${CXX} ${CXXFLAGS} -c Animal.cpp

Tiger.o: Tiger.cpp Tiger.hpp Animal.hpp
	${CXX} ${CXXFLAGS} -c Tiger.cpp

Penguin.o: Penguin.cpp Penguin.hpp Animal.hpp
	${CXX} ${CXXFLAGS} -c Penguin.cpp

Turtle.o: Turtle.cpp Turtle.hpp Animal.hpp
	${CXX} ${CXXFLAGS} -c Turtle.cpp

clean:
	rm *.o zooTycoon
