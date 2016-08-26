tour: main.o board.o
	g++ -std=c++11 -g -Wall main.o board.o -o tour

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

board.o: board.cpp board.h
	g++ -std=c++11 -g -Wall -c board.cpp

clean:
	rm *.o tour
	echo clean done
