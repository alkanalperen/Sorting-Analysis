hw: sorting.o main.o
	g++ -o hw main.o sorting.o

compile: sorting.cpp main.cpp
	g++ -c main.cpp sorting.cpp

clean: sorting.o main.o
	rm sorting.o main.o