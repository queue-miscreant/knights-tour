#include "board.h"

Board::Board(int maxx, int maxy, int delay) {
	m_size = maxx*maxy;
	m_board = new int[m_size];
	for (int i = 0; i < m_size; i++) {
		m_board[i] = -1;
	}
	m_maxx = maxx;
	m_maxy = maxy;
	//usleep is microseconds
	m_delay = delay*1000;
}

Board::Board(int maxx, int maxy) {
	Board(maxx, maxy, 500);
}

Board::~Board() {
	delete [] m_board;
}

bool Board::animateSolve(int x, int y, int moveNumber) {
	if (not canMove(x,y))
		return false;
	m_board[x+m_maxx*y] = moveNumber;
	//show moving here
	printOver();
	if (moveNumber == m_size - 1) {
		print();		//we don't need to print over it
		return true;
	}
	
	for (int i = -2; i < 3; i++) {
		for (int j = -2; j < 3; j++) {
			//correct knight movement only
			if (i ==j || i == -j || i == 0 || j == 0)
				continue;
			//if we can move here
			if (animateSolve(x+i,y+j,moveNumber+1))
				return true;
		}
	}
	printOver();
	m_board[x+m_maxx*y] = -1;
	return false;
}

bool Board::animateSolve(int x, int y) {
	if (not animateSolve(x,y,0)) {
		print();
		return false;
	}
	return true;
}

bool Board::canMove(int x, int y) {
	return (x >= 0 && y >= 0 && x < m_maxx && y < m_maxy && m_board[x+m_maxx*y] == -1);
}

void Board::print() {
	//iterate over positions
	for (int i = 0; i < m_size; i++) {
		//iterate over stack
		int find = m_board[i];
		int color = 7;
		if (not find)
			color = 1;	//red
		else if (find+1 == m_size)
			color = 2;	//green
		if (find != -1)
			std::printf("[\x1b[3%dm%3d\x1b[m]", color, find+1);
		else 
			std::printf("[   ]");

		if (i % m_maxx == m_maxx-1)
			std::printf("\n\n");
	}
}

void Board::printOver() {
	print();
	usleep(m_delay);
	std::printf("\x1b[%dA",m_maxy*2);
}
