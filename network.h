#ifndef NETWORK_H
#define NETWORK_H
#include "engine.h"
class NETWORK
{
	public:
		void init();
		int **brick;
		int x;
		int y;
		int status;
		BRICK& operator= (const int x);	
	private:
		
};
#include "network.cpp"
#endif
