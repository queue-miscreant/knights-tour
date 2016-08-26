#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <cmath>
#include <stdexcept>
#include <unistd.h>

class Board {
private:
	int* m_board;
	int m_maxx;
	int m_maxy;
	int m_size;

	int m_delay;

	bool animateSolve(int x, int y, int moveNumber);
	bool canMove(int x, int y);
	void printOver();
	
public:
	Board(int maxx, int maxy);
	Board(int maxx, int maxy, int delay);
	~Board();
	bool animateSolve(int x, int y);
	void print();
};

#endif
