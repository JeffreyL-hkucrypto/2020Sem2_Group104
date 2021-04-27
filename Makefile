monopoly:main.o  GameFunction.o
	g++ -pedantic-errors -std=c++11 main.o GameFunction.o -o monopoly
main.o:main.cpp GameFunction.cpp
	g++ -pedantic-errors -std=c++11 -c main.cpp
GameFunction.o:GameFunction.cpp GameFunction.h
	g++ -pedantic-errors -std=c++11 -c GameFunction.cpp
.Phony:clean
clean:
	rm *.o
