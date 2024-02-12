CC = g++
FLAGS = -O3 -lncurses
SRC = src/
INCLUDE = src/include/
#OBJ = obj/
#ALLOBJ = $(wildcard ${OBJ}*.o)

all: main.o func.o debug.o
	${CC} ${FLAGS} $^ -o $@

clear: 
	rm *.o all

main.o: ${SRC}main.cpp
	${CC} ${FLAGS} -c $^ -o $@

func.o: ${INCLUDE}func.cpp 
	${CC} ${FLAGS} -c $^ -o $@

debug.o: ${INCLUDE}debug.cpp
	${CC} ${FLAGS} -c $^ -o $@
