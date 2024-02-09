CC = g++
FLAGS = -O3
SRC = src/
INCLUDE = src/include/
#OBJ = obj/
#ALLOBJ = $(wildcard ${OBJ}*.o)

all: main.o func.o
	${CC} ${FLAGS} $^ -o final.run

clear: 
	rm *.o final.run

main.o: ${SRC}main.cpp
	${CC} ${FLAGS} -c $^ -o $@

func.o: ${INCLUDE}func.cpp 
	${CC} ${FLAGS} -c $^ -o $@

