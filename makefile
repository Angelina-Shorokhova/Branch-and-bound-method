all: main

main: main.o Parser.o Solver.o
	g++ main.o Parser.o Solver.o -o main

main.o: main.cpp
	g++ -c main.cpp

Parser.o: Parser.h
	g++ -c Parser.h

Solver.o: Solver.h
	g++ -c Solver.h

clean:
	rm -rf *.o main