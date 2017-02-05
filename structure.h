#ifndef STRUCTURE_H
#define STRUCTURE_H
#include "header.h"
#include "brick.h"
class STRUCTURE
{
	public:
		STRUCTURE();
		void drawName(int x, int y, string name);
		void drawTime(int x, int y, int time);
		void drawScore(int x, int y, int score);	
		void drawBrick(int x, int y,BRICK brick);
		void undrawBrick(int x, int y,BRICK brick);
		void drawTable(COORD coord);
		void drawTable(int x, int y);
	private:
		int int_brick;
};
#include "structure.cpp"
#endif
