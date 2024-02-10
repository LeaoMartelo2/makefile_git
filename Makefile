CC = g++
FLAGS = -O3 -lncurses
SRC = src/
INCLUDE = src/include/
#OBJ = obj/
#ALLOBJ = $(wildcard ${OBJ}*.o)

all: main.o func.o
	${CC} ${FLAGS} $^ -o all

clear: 
	rm *.o final

main.o: ${SRC}main.cpp
	${CC} ${FLAGS} -c $^ -o $@

func.o: ${INCLUDE}func.cpp 
	${CC} ${FLAGS} -c $^ -o $@

