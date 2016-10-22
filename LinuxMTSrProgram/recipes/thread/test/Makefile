.PHONY: cleanall cleanobj

ALL_PROGRAM=Observer

all: ${ALL_PROGRAM}

# which compiler
CC = gcc

#where are include 
INCLUDE = .

#options for development
CFLAGS = -g -Wall -ansi

#options for release
#CFLAGS = -O -Wall -ansi

.cc.o:
	${CC} -I${INCLUDE} ${CFLAGS} -c $<

Observer.o: Observer.cc

Observer: Observer.o
	${CC} -o Observer Observer.o

cleanall: cleanobj
	rm -rf ${ALL_PROGRAM}

cleanobj: 
	rm -Rf *.o