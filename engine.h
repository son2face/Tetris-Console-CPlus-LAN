#ifndef ENGINE_H
#define ENGINE_H
#include "header.h"
#include "brick.h"
#include "structure.h"
class ENGINE
{
	public:
		ENGINE();
		ENGINE(string input);
		void play();	
		bool check_trai(int x, int y, BRICK& iBrick);
		bool check_phai(int x, int y, BRICK& iBrick);
		bool check_duoi(int x, int y, BRICK& iBrick);
		bool check_tren(int x, int y, BRICK& iBrick);
		void LEFT(int& x, int& y, BRICK& iBrick);
		void RIGHT(int& x, int& y, BRICK& iBrick);
		void DOWN(int& x, int& y, BRICK& iBrick);
		void UPDATE1();
		void makeClient();
		void UPDATE();
		void setmode(int ggg);
		void clear();
		void broadcast();
		void listen();
		int score;
		int opera();
	private:
		char key;
		int MY_PORT;
  		char lpName[100];
		int broad[22][10];
		int MODE;
		COORD toado;
		void drawName();
		void drawScore();
		void drawTime();
		void Start();
		int temp,temp3;
		COORD sizeManhinh;
		int kcngang, kcdoc,slngang,sldoc;
		int time;
		int speed, prival;
		int x_brick,y_brick;
		int base_Brick,base_Brick2, num_Brick,num_Brick2;
		BRICK Brick,Brick_next;
		string name;
		int count;
		int kt;
		mutex _mutex;
		vector <int> IP;
		vector <int> IP_check;
		vector <string> IP_name;
		vector <int> IP_time;
		vector <int> IP_score;
		vector <int> IP_x_brick;
		vector <int> IP_y_brick;
		vector <int> IP_brickStatus;
		vector <int> IP_next;
		vector <int> IP_first;
		int IP_broad[20][22][10];
		vector <int> IP_over;
		int n_connect;
		int IPthisPC;
		int over = 0;
		int end = 0;
		STRUCTURE structure;
};
#include "engine.cpp"
#endif
