# Program name: Project4_Anderson_Jacob
# Author: Jacob Anderson
# Date: 10/16/18
# Description: Simulates the video game zoo tycoon where the user
# owns a zoo. The zoo spends money to feed the animals, gets a payoff
# from attendance based on the animals, lets the user buy new animals,
# and deals with random zoo events like sickness, births, and
# attendance booms.

# This makefile is inspired by the example makefile from Oregon State.
# Available at: https://oregonstate.instructure.com/courses/1692879/files/71792854

# Which compiler to use
CXX = g++

# Which flags to pas to compiler
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors

# Variable name for my objects
OBJS = Animal.o inputValidation.o Main.o Penguin.o Tiger.o Turtle.o Zoo.o

# Variable name for my sources (.cpp)
SRCS = Animal.cpp inputValidation.cpp Main.cpp Penguin.cpp Tiger.cpp Turtle.cpp Zoo.cpp
# Variable name for my headers (.hpp)
HEADERS = Animal.hpp inputValidation.hpp Penguin.hpp Tiger.hpp Turtle.hpp Zoo.hpp

# Command to compile my executable from my objects
Project2_Anderson_Jacob: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o zooTycoon.exe

# Command to compile my objects from my sources
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

# Command to clean the files
clean:
	rm ${OBJS} zooTycoon.exe
