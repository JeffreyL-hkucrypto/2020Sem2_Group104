monopoly.out:main.o print.o GameFunction.o board_information.o get_players.o
	g++ -pedantic-errors -std=c++11 -o monopoly.out main.o print.o GameFunction.o board_information.o get_players.o
main.o:main.cpp print.h
	g++ -pedantic-errors -std=c++11 -c main.cpp
print.o:print.cpp GameFunction.h print.h
	g++ -pedantic-errors -std=c++11 -c print.cpp
GameFunction.o:GameFunction.cpp GameFunction.h board_information.h get_players.h
	g++ -pedantic-errors -std=c++11 -c GameFunction.cpp
board_information.o:board_information.cpp board_information.h
	g++ -pedantic-errors -std=c++11 -c board_information.cpp
get_players.o:get_players.cpp get_players.h
	g++ -pedantic-errors -std=c++11 -c get_players.cpp
.Phony:clean
clean:
	rm *.o
