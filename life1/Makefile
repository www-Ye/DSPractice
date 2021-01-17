life1: main.o life.o utility.o
	g++ -g -o life1 main.o life.o utility.o

main.o: main.cc life.h utility.h
	g++ -c main.cc

life.o: life.cc life.h utility.h
	g++ -c life.cc

utility.o: utility.cc utility.h
	g++ -c utility.cc

clean:
	rm life1 main.o life.o utility.o
