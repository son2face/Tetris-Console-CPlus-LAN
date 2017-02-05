void STRUCTURE::drawTable(COORD coord)
{
	setXY(coord.X,coord.Y);
	for (int i = 0; i < 12; i++) cout << (char)219;
	for (int i = 1; i < 19; i++)
	{
		setXY(coord.X,coord.Y+i);
		cout << (char)219;
		setXY(coord.X+11,coord.Y+i);
		cout << (char)219;
	}
	setXY(coord.X,coord.Y+19);
	for (int i = 0; i < 12; i++) cout << (char)219;	
}

void STRUCTURE::drawTable(int x, int y)
{
	setXY(x,y);
	for (int i = 0; i < 12; i++) cout << (char)219;
	for (int i = 1; i < 19; i++)
	{
		setXY(x,y+i);
		cout << (char)219;
		setXY(x+11,y+i);
		cout << (char)219;
	}
	setXY(x,y+19);
	for (int i = 0; i < 12; i++) cout << (char)219;	
}

void STRUCTURE::drawBrick(int x, int y, BRICK brick)
{
	for (int i = 0; i < brick.y; i++)
		for(int j = 0; j < brick.x; j++)
		{
			if(brick.brick[i][j] == 0)
			{
				setXY(x+j,y+i);	
				cout << (char)2;
			}
		}
}

void STRUCTURE::undrawBrick(int x, int y, BRICK brick)
{
	for (int i = 0; i < brick.y; i++)
		for(int j = 0; j < brick.x; j++)
		{
			if(brick.brick[i][j] == 0)
			{
				setXY(x+j,y+i);	
				cout << ' ';
			}
		}
}

STRUCTURE::STRUCTURE()
{
	
} 


