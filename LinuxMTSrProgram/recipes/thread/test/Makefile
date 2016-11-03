.PHONY: cleanall cleanobj

ALL_PROGRAM=Observer Observer_safe

all: ${ALL_PROGRAM}

# which compiler
CC = g++

#where are include 
MY_INCLUDE = -I. -I.. -I/usr/local//Cellar/boost/1.62.0/include

#options for development
CFLAGS = -g -Wall -ansi

#options for release
#CFLAGS = -O -Wall -ansi

.cc.o:
	${CC} ${INCLUDE} ${CFLAGS} -c $<

Observer.o: Observer.cc

Observer: Observer.o
	${CC} -o Observer Observer.o

Observer_safe: Observer_safe.o
	${CC} -o Observer_safe Observer_safe.o -lpthread

cleanall: cleanobj
	rm -rf ${ALL_PROGRAM}

cleanobj: 
	rm -Rf *.o