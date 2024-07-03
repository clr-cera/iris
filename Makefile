all: main
	g++  *.o -o main
	rm *.o

main: graphics
	g++ -c ./src/*.cpp

graphics:
	g++ -c ./src/Graphics/*.cpp
