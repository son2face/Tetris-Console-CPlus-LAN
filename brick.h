#ifndef BRICK_H
#define BRICK_H
#include "header.h"
class BRICK
{
	public:
		BRICK(int stts);
		BRICK();
		void init();
		int **brick;
		int x;
		int y;
		int status;
		BRICK& operator= (const int x);
 		
		
};
#include "brick.cpp"
#endif
