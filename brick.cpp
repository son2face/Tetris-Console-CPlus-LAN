BRICK::BRICK(int stts)
{
	status = stts;
	init();
} 

BRICK::BRICK()
{
	status = 1;
	init();
} 



void BRICK::init()
{
	switch (status)
	{
		case 1:   // 4x1
			x = 1;
			y = 4;
			brick = new int*[y];
			for (int i = 0; i < y; i++) brick[i] = new int[x]; 
			brick[0][0] = 0;
			brick[1][0] = 0;
			brick[2][0] = 0;
			brick[3][0] = 0;
			break;
		case 2:   // 1x4 
			x = 4;
			y = 1;
			brick = new int*[y];
			for (int i = 0; i < y; i++) brick[i] = new int[x]; 
			brick[0][0] = 0;
			brick[0][1] = 0;
			brick[0][2] = 0;
			brick[0][3] = 0;
			break;
		case 3:   // 4x1
			x = 1;
			y = 4;
			brick = new int*[y];
			for (int i = 0; i < y; i++) brick[i] = new int[x]; 
			brick[0][0] = 0;
			brick[1][0] = 0;
			brick[2][0] = 0;
			brick[3][0] = 0;
			break;
		case 4:   // 1x4 
			x = 4;
			y = 1;
			brick = new int*[y];
			for (int i = 0; i < y; i++) brick[i] = new int[x];  
			brick[0][0] = 0;
			brick[0][1] = 0;
			brick[0][2] = 0;
			brick[0][3] = 0;
			break;
		case 5:  // 2x2
			x = 2;
			y = 2;
			brick = new int*[y];
			for (int i = 0; i < y; i++) brick[i] = new int[x]; 
			brick[0][0] = 0;
			brick[0][1] = 0;
			brick[1][0] = 0;
			brick[1][1] = 0;	
			break;	
		case 6:  // 2x2
			x = 2;
			y = 2;
			brick = new int*[y];
			for (int i = 0; i < y; i++) brick[i] = new int[x]; 
			brick[0][0] = 0;
			brick[0][1] = 0;
			brick[1][0] = 0;
			brick[1][1] = 0;		
			break;	
		case 7:  // 2x2
			x = 2;
			y = 2;
			brick = new int*[y];
			for (int i = 0; i < y; i++) brick[i] = new int[x]; 
			brick[0][0] = 0;
			brick[0][1] = 0;
			brick[1][0] = 0;
			brick[1][1] = 0;	
			break;	
		case 8:  // 2x2
			x = 2;
			y = 2;
			brick = new int*[y];
			for (int i = 0; i < y; i++) brick[i] = new int[x]; 
			brick[0][0] = 0;
			brick[0][1] = 0;
			brick[1][0] = 0;
			brick[1][1] = 0;	
			break;	
		case 9:  //3x2 L
			x = 2;
			y = 3;
			brick = new int*[y];
			for (int i = 0; i < y; i++) brick[i] = new int[x]; 
			brick[0][0] = 0;
			brick[0][1] = 1;
			brick[1][0] = 0;
			brick[1][1] = 1;
			brick[2][0] = 0;
			brick[2][1] = 0;	
			break;
		case 10:  //2x3 L1
			x = 3;
			y = 2;
			brick = new int*[y];
			for (int i = 0; i < y; i++) brick[i] = new int[x]; 
			brick[0][0] = 0;
			brick[0][1] = 0;
			brick[0][2] = 0;
			brick[1][0] = 0;
			brick[1][1] = 1;
			brick[1][2] = 1;
			break;
		case 11:  //3x2 L2
			x = 2;
			y = 3;
			brick = new int*[y];
			for (int i = 0; i < y; i++) brick[i] = new int[x]; 
			brick[0][0] = 0;
			brick[0][1] = 0;
			brick[1][0] = 1;
			brick[1][1] = 0;
			brick[2][0] = 1;
			brick[2][1] = 0;	
			break;
		case 12:  //2x3 L3
			x = 3;
			y = 2;
			brick = new int*[y];
			for (int i = 0; i < y; i++) brick[i] = new int[x]; 
			brick[0][0] = 1;
			brick[0][1] = 1;
			brick[0][2] = 0;
			brick[1][0] = 0;
			brick[1][1] = 0;
			brick[1][2] = 0;	
			break;		
		case 13:  //3x2 L@
			x = 2;
			y = 3;
			brick = new int*[y];
			for (int i = 0; i < y; i++) brick[i] = new int[x]; 
			brick[0][0] = 1;
			brick[0][1] = 0;
			brick[1][0] = 1;
			brick[1][1] = 0;
			brick[2][0] = 0;
			brick[2][1] = 0;	
			break;
		case 14:  //2x3 L1
			x = 3;
			y = 2;
			brick = new int*[y];
			for (int i = 0; i < y; i++) brick[i] = new int[x]; 
			brick[0][0] = 0;
			brick[0][1] = 1;
			brick[0][2] = 1;
			brick[1][0] = 0;
			brick[1][2] = 0;
			brick[1][1] = 0;
			break;
		case 15:  //3x2 L2
			x = 2;
			y = 3;
			brick = new int*[y];
			for (int i = 0; i < y; i++) brick[i] = new int[x]; 
			brick[0][0] = 0;
			brick[1][1] = 1;
			brick[2][1] = 1;
			brick[0][1] = 0;
			brick[1][0] = 0;
			brick[2][0] = 0;	
			break;
		case 16:  //2x3 L3
			x = 3;
			y = 2;
			brick = new int*[y];
			for (int i = 0; i < y; i++) brick[i] = new int[x]; 
			brick[0][0] = 0;
			brick[0][1] = 0;
			brick[1][0] = 1;
			brick[1][1] = 1;
			brick[0][2] = 0;
			brick[1][2] = 0;	
			break;	
		case 17:  //2x3  W
			x = 3;
			y = 2;
			brick = new int*[y];
			for (int i = 0; i < y; i++) brick[i] = new int[x]; 
			brick[0][1] = 0;
			brick[1][0] = 0;
			brick[0][2] = 1;
			brick[0][0] = 1;
			brick[1][1] = 0;
			brick[1][2] = 0;	
			break;
		case 18:  //3x2 W1
			x = 2;
			y = 3;
			brick = new int*[y];
			for (int i = 0; i < y; i++) brick[i] = new int[x]; 
			brick[0][0] = 0;
			brick[1][0] = 0;
			brick[2][0] = 0;
			brick[1][1] = 0;
			brick[0][1] = 1;
			brick[2][1] = 1;
			break;
		case 19:  //2x3 W2
			x = 3;
			y = 2;
			brick = new int*[y];
			for (int i = 0; i < y; i++) brick[i] = new int[x]; 
			brick[0][0] = 0;
			brick[0][1] = 0;
			brick[0][2] = 0;
			brick[1][1] = 0;
			brick[1][2] = 1;
			brick[1][0] = 1;	
			break;
		case 20:  //3x2 W3
			x = 2;
			y = 3;
			brick = new int*[y];
			for (int i = 0; i < y; i++) brick[i] = new int[x]; 
			brick[0][1] = 0;
			brick[1][0] = 0;
			brick[1][1] = 0;
			brick[2][1] = 0;
			brick[0][0] = 1;
			brick[2][0] = 1;	
			break;	
		case 21:  //2x3  N
			x = 2;
			y = 3;
			brick = new int*[y];
			for (int i = 0; i < y; i++) brick[i] = new int[x]; 
			brick[0][1] = 0;
			brick[1][1] = 0;
			brick[1][0] = 0;
			brick[2][0] = 0;
			brick[0][0] = 1;
			brick[2][1] = 1;	
			break;
		case 22:  //3x2 N1
			x = 3;
			y = 2;
			brick = new int*[y];
			for (int i = 0; i < y; i++) brick[i] = new int[x]; 
			brick[0][0] = 0;
			brick[0][1] = 0;
			brick[1][2] = 0;
			brick[1][1] = 0;
			brick[0][2] = 1;
			brick[1][0] = 1;
			break;
		case 23:  //2x3  N
			x = 2;
			y = 3;
			brick = new int*[y];
			for (int i = 0; i < y; i++) brick[i] = new int[x]; 
			brick[0][1] = 0;
			brick[1][1] = 0;
			brick[1][0] = 0;
			brick[2][0] = 0;
			brick[0][0] = 1;
			brick[2][1] = 1;	
			break;
		case 24:  //3x2 N1
			x = 3;
			y = 2;
			brick = new int*[y];
			for (int i = 0; i < y; i++) brick[i] = new int[x]; 
			brick[0][0] = 0;
			brick[0][1] = 0;
			brick[1][2] = 0;
			brick[1][1] = 0;
			brick[0][2] = 1;
			brick[1][0] = 1;
			break;
		case 25:  //2x3  N@
			x = 2;
			y = 3;
			brick = new int*[y];
			for (int i = 0; i < y; i++) brick[i] = new int[x]; 
			brick[0][0] = 0;
			brick[1][0] = 0;
			brick[1][1] = 0;
			brick[2][1] = 0;
			brick[0][1] = 1;
			brick[2][0] = 1;	
			break;
		case 26:  //3x2 N1
			x = 3;
			y = 2;
			brick = new int*[y];
			for (int i = 0; i < y; i++) brick[i] = new int[x]; 
			brick[1][0] = 0;
			brick[1][1] = 0;
			brick[0][1] = 0;
			brick[1][2] = 1;
			brick[0][0] = 1;
			brick[0][2] = 0;
			break;
		case 27:  //2x3  N@
			x = 2;
			y = 3;
			brick = new int*[y];
			for (int i = 0; i < y; i++) brick[i] = new int[x]; 
			brick[0][0] = 0;
			brick[1][0] = 0;
			brick[1][1] = 0;
			brick[2][1] = 0;
			brick[0][1] = 1;
			brick[2][0] = 1;	
			break;
		case 28:  //3x2 N1
			x = 3;
			y = 2;
			brick = new int*[y];
			for (int i = 0; i < y; i++) brick[i] = new int[x]; 
			brick[1][0] = 0;
			brick[1][1] = 0;
			brick[0][1] = 0;
			brick[0][2] = 0;
			brick[1][2] = 1;
			brick[0][0] = 1;
			break;
	}
}

BRICK& BRICK::operator= (const int x)
{
	status = x;
	init();
}
