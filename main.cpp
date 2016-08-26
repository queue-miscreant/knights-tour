/**
*	@file : main.cpp
*	@author :  Ben Conner
*	@date : 2016.02.10
*	Purpose: Main execution file of the code.
*/
#include <iostream>
#include "board.h"

int main(int argc, char* argv[])
{
	if (argc < 5 or argc > 7) {
		std::cout << "Invalid number of arguments" << std::endl;
		return -1;
	}
	
	int maxx = std::atoi(argv[1]);
	int maxy = std::atoi(argv[2]);
	int x = std::atoi(argv[3]);
	int y = std::atoi(argv[4]);
	int delay = 500;
	if (argc == 6) 
		 delay = std::atoi(argv[5]);
	
	if (maxx < 0 || maxy < 0) {
		std::cout << "Invalid board size" << std::endl;
		return -2;
	}
	
	if (x < 0 || x >= maxx || y < 0 || y >= maxy) {
		std::cout << "Invalid starting position" << std::endl;
		return -3;
	}
	
	Board tour (maxx,maxy,delay);
	if (tour.animateSolve(x,y))
		std::printf("Solved!\n");
	else
		std::printf("No solution found.\n");
}
