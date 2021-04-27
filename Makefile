monopoly.out:main.o print.o gf.o jail.o binfo.o save.o
	g++ -pedantic-errors -std=c++11 -o monopoly.out main.o print.o gf.o jail.o binfo.o save.o
main.o:main.cpp GameFunction.h print.h
	g++ -pedantic-errors -std=c++11 -c main.cpp
print.o:print.cpp main.h board_information.h GameFunction.h file_save.h print.h
	g++ -pedantic-errors -std=c++11 -c print.cpp
gf.o:GameFunction.cpp GameFunction.h board_information.h jail.h print.h
	g++ -pedantic-errors -std=c++11 -c GameFunction.cpp
jail.o:jail.cpp jail.h GameFunction.h print.h
	g++ -pedantic-errors -std=c++11 -c jail.cpp
binfo.o:board_information.cpp board_information.h
	g++ -pedantic-errors -std=c++11 -c board_information.cpp
save.o:file_save.cpp file_save.h GameFunction.h
	g++ -pedantic-errors -std=c++11 -c file_save.cpp
.Phony:clean
clean:
	rm *.o
