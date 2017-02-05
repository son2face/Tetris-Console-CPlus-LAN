ENGINE::ENGINE(string input)
{
	toado.X = 2;
	toado.Y = 0;
	MY_PORT = 4567;
	name = input;
	time = 0;
	score = 0;
	speed = 7;
	n_connect = 0;
	prival = 100;
    gethostname(lpName,sizeof(lpName));
    hostent* pMyServer = gethostbyname(lpName);
    IPthisPC = *(int*)pMyServer->h_addr_list[0];
	for(int i = 0; i <22; i++)
		for (int j = 0; j < 10; j++)
		{
			broad[i][j] = 0;
		}
		sizeManhinh = getsizeManHinh();
	slngang = sizeManhinh.X /21;
	sldoc = 2;
	kcngang = (sizeManhinh.X-slngang*21)/(slngang-1);
	kcdoc = 0;	
}
void ENGINE::listen()
{
	sockaddr_in pAddr;
    pAddr.sin_family = AF_INET;
    pAddr.sin_port = htons(MY_PORT);
    pAddr.sin_addr.S_un.S_addr = ADDR_ANY;
   	SOCKET sock = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
    int nResult = bind(sock,(sockaddr*)&pAddr,sizeof(pAddr));
    if (nResult == -1){
        setXY(1,45);cout << "Loi thiet lap IP va PORT\n";
    }
    int nAddrLen;
    int nRevc;
    int nSend;
    sockaddr_in IPClient;
    char buff[512]={0};    
    while (1){
 
        // Nh?n k?t n?i t? CLIENT
        nAddrLen = sizeof(sockaddr_in);                
        nRevc = recvfrom(sock,buff,sizeof(buff),0, (sockaddr*)&IPClient,&nAddrLen);
       int _IP = IPClient.sin_addr.s_addr;
	    if (_IP == IPthisPC) continue;
		else 
	    {
	    	int __check = 1, stt_IP;
	    	for (int i = 0; i < n_connect; i++)
	    	{
	    		if(IP[i] == _IP)
	    		{
	    			stt_IP = i;
	    			__check = 0;
					break;
				}
			}
			if (__check==1)
			{
				 stt_IP = n_connect;
				 IP.push_back(_IP);
				 IP_name.push_back("");
				 IP_time.push_back(0);
				 IP_score.push_back(0);
				 IP_x_brick.push_back(0);
				 IP_y_brick.push_back(0);
				 IP_brickStatus.push_back(0);
				 IP_over.push_back(0);
				 n_connect ++;
			}			
		   	if (buff[0] == '.') IP_over[stt_IP] = 1;
			else 
			{
				int j = 1;
				string __temp;
				while(buff[j]!='"')
				{
					__temp.push_back(buff[j]);
					j++;
				}
				IP_name[stt_IP] = __temp;
				j++;
			    char buff1[100];
			    int rtyu = 0;
			    while(buff[j]!=' ')
			    {
			    	buff1[rtyu] = buff[j];
			    	j++;
				}
				j++;
				buff1[rtyu] = 0;
				rtyu = 0;
			    IP_time[stt_IP] = atoi(buff1);
			    while(buff[j]!=' ')
			    {
			    	buff1[rtyu] = buff[j];
			    	j++;
				}
				j++;
				buff1[rtyu] = 0;
				rtyu = 0;
			    IP_score[stt_IP] = atoi(buff1);
				 while(buff[j]!=' ')
			   {
			    	buff1[rtyu] = buff[j];
			    	j++;
				}
				j++;
				buff1[rtyu] = 0;
				rtyu = 0;
			    IP_x_brick[stt_IP] = atoi(buff1);
			     while(buff[j]!=' ')
			    {
			    	buff1[rtyu] = buff[j];
			    	j++;
				}
				j++;
				buff1[rtyu] = 0;
				rtyu = 0;
			    IP_y_brick[stt_IP] = atoi(buff1);
			     while(buff[j]!=' ')
			    {
			    	buff1[rtyu] = buff[j];
			    	j++;
				}
				j++;
				buff1[rtyu] = 0;
				rtyu = 0;
			    IP_brickStatus[stt_IP] = atoi(buff1);
			    for(int poiu = 0; poiu < 22; poiu++)
			    {
			    	for (int poi = 0; poi < 10; poi++)
			    	{
			    		IP_broad[stt_IP][poiu][poi] = buff[j] - '0';
			    		j++;
					}
				}
			}
		}
    }
}
void ENGINE::broadcast()
{
	SOCKET sock = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
	sockaddr_in pServerAddr;
    BOOL bSockBroadcast=true;
    setsockopt(sock,SOL_SOCKET,SO_BROADCAST,(char*)&bSockBroadcast,sizeof(BOOL));
    pServerAddr.sin_family = AF_INET;
    pServerAddr.sin_port = htons(MY_PORT);
    pServerAddr.sin_addr.S_un.S_addr = inet_addr("255.255.255.255"); // �?a ch? d�ch l� MULTICAST
    int nSend;
    int nRevc;
    int nAddrLen;   
	for(;;)
	{
		if(over == 1)
		{
			char buff[] = "."; // Th�ng tin g?i t?i m�y ch?
	        nSend = sendto(sock,buff,sizeof(buff),0,(sockaddr*)&pServerAddr,sizeof(sockaddr_in));	
	  		break;
		}
		Sleep(200);
	    stringstream out;
	    out << '"' << name << '"' << time << ' ' << score << ' ' <<  x_brick << ' ' << y_brick << ' ';
	    out << Brick.status << ' ';
	   	for(int i = 0; i <22; i++)
			for (int j = 0; j < 10; j++)
			{
				out << broad[i][j];
			}
        string qwe = out.str();
		char buff[qwe.size()+1]; // Th�ng tin g?i t?i m�y ch?
		copy(qwe.begin(),qwe.end(),buff); 
        nSend = sendto(sock,buff,sizeof(buff),0,(sockaddr*)&pServerAddr,sizeof(sockaddr_in));
	 } 
}

void ENGINE::play()
{
	structure.drawTable(toado.X,toado.Y+2);
	thread _broadcast(&ENGINE::broadcast,this);
	_broadcast.detach();
	thread _listen(&ENGINE::listen,this);
	_listen.detach();
	Start();
	drawName();
	structure.drawTable(toado.X,toado.Y+2);
	drawScore();
	drawTime();
	num_Brick2 = rand()%28;
	base_Brick2 = num_Brick2/4*4;
	Brick_next = num_Brick2+1;
	for(;;)
	{
		prival = 100;
		kt = 0;
		count = 0;
		num_Brick = num_Brick2;
		base_Brick = base_Brick2;
		Brick = num_Brick+1;
		num_Brick2 = rand()%28;
		base_Brick2 = num_Brick2/4*4;
		Brick_next = num_Brick2+1;
		x_brick = 4;
		y_brick = 0;
		for (int e = 0; e < Brick.x; e++)
		{
			if (Brick.brick[Brick.y-1][e] == 0)
			{
				if (broad[0][e+x_brick] == 1)
				{
					setXY(toado.X+2,toado.Y+12);
					cout << "GAME OVER";
					over = 1;
					Sleep(1000);
					break;
				}
			}
		}
		if (over == 1) break;
		structure.undrawBrick(toado.X+15,toado.Y+4, Brick);
		structure.drawBrick(toado.X+15,toado.Y+4, Brick_next);
		structure.drawBrick(x_brick+toado.X+1,y_brick+toado.Y+3,Brick);
		opera();
		UPDATE();
	}
}

void ENGINE::drawName()
{
	int a = (12-name.size())/2;
	setXY(toado.X+a,toado.Y);
	cout << name;
}

void ENGINE::Start()
{
	setXY(toado.X+4,toado.Y+12);
	cout << "START";
	setXY(toado.X,toado.Y+24);
	cout << "Press any key to start!";
	getch();
	setXY(toado.X+4,toado.Y+12);
	cout << "     ";
	setXY(toado.X,toado.Y+24);
	cout << "                       ";
}

void ENGINE::drawScore()
{
	setXY(toado.X+1,toado.Y+24);
	cout << "Score: " << score;
}

void ENGINE::drawTime()
{
	setXY(toado.X+1,toado.Y+26);
	cout << "Time: " << time << 's';
}

bool ENGINE::check_trai(int x, int y, BRICK& iBrick)
{
	if (x<1) return false;
	for(int i = 0; i < iBrick.y; i++)
	{
		for(int j = 0; j < iBrick.x; j++)
		{
			if (iBrick.brick[i][j] == 0)
			{
				if (broad[y+i][x+j-1] == 0) break;
				else return false;
			}
		}
	}
	return true;
}

bool ENGINE::check_phai(int x, int y, BRICK& iBrick)
{
	if (x>9-iBrick.x) return false;
	for(int i = 0; i < iBrick.y; i++)
	{
		for(int j = 0; j < iBrick.x; j++)
		{
			if (iBrick.brick[i][j] == 0)
			{
				if (broad[y+i][x+j+1] == true) return false;
			}
		}
	}
	return true;
}

bool ENGINE::check_duoi(int x, int y, BRICK& iBrick)
{
	if (y > 17-iBrick.y) return false;
	for(int i = 0; i < iBrick.y; i++)
	{
		for(int j = 0; j < iBrick.x; j++)
		{
			if (iBrick.brick[i][j] == 0)
			{
				if (broad[y+i+1][x+j] == 0);
				else return false;
			}
		}
	}
	return true;
}

bool ENGINE::check_tren(int x, int y, BRICK& iBrick)
{
	if( iBrick.y + y > 17) return false;
	for(int i = iBrick.y-1; i > -1; i--)
	{
		for(int j = 0; j < iBrick.x; j++)
		{
			if (iBrick.brick[i][j] == 0)
			{
				if(broad[y_brick+i][x_brick+j] == 1) return false;
			}
		}
	}
	return true;
}

void ENGINE::LEFT(int& x, int& y, BRICK& iBrick)
{
	structure.undrawBrick(x+toado.X+1,y+toado.Y+3,iBrick);
	x = x-1;
	structure.drawBrick(x+toado.X+1,y+toado.Y+3,iBrick);
}

void ENGINE::RIGHT(int& x, int& y, BRICK& iBrick)
{
	structure.undrawBrick(x+toado.X+1,y+toado.Y+3,iBrick);
	x++;
	structure.drawBrick(x+toado.X+1,y+toado.Y+3,iBrick);
}

void ENGINE::DOWN(int& x, int& y, BRICK& iBrick)
{
	structure.undrawBrick(x+toado.X+1,y+toado.Y+3,iBrick);
	y++;
	structure.drawBrick(x+toado.X+1,y+toado.Y+3,iBrick);
}

int ENGINE::opera()
{
	for(;;)
	{
		while (!kbhit())
	    {
	        Sleep(prival);
	        time+=prival;
	        if ((time-prival)/1000 < time/1000)
	        {
	        	setXY(toado.X+7,toado.Y+26);
				cout << time/1000 << 's';
			}
			count++;
			if ((count%speed) == 0)
			{
				if(check_duoi(x_brick,y_brick,Brick) == true) 
				{
					DOWN(x_brick,y_brick,Brick);
				}
				else
				{
					kt = 1;
					break;
				}
			}
	    }
	    if (kt == 1) break;
	    key = getch();
	    int temp2 = 1;
	    switch (key)
	    {
	    	case 'a':
	    		if(check_trai(x_brick,y_brick,Brick) == true) LEFT(x_brick,y_brick,Brick);
	    		break;
	    	case 's':
	    		prival /= 5;
	    		break;
	    	case 'w':
	    		num_Brick++;
	    		temp = x_brick;
				structure.undrawBrick(x_brick+toado.X+1,y_brick+toado.Y+3,Brick);
				temp3 = Brick.x;
	    		Brick = num_Brick%4+base_Brick+1;
	    		if(check_phai(x_brick-1,y_brick,Brick) == false)
				{
					x_brick = x_brick + temp3 - Brick.x;
					temp2 = 0;
					if(check_trai(x_brick+1,y_brick,Brick) == false)
					{
						num_Brick--;
						x_brick = temp;
						temp2 = 2;
						Brick = num_Brick%4+base_Brick+1;
					}
				}
				if (temp2 == 2);
		    	else if(check_tren(x_brick,y_brick,Brick) == false)
	    		{
	    			num_Brick--;
	    			if (temp2 == 0)
					{
						x_brick = temp;
					}
	    			Brick = num_Brick%4+base_Brick+1;
				}
				structure.drawBrick(x_brick+toado.X+1,y_brick+toado.Y+3,Brick);
				break;
	    	case 'd':
	    		if(check_phai(x_brick,y_brick,Brick) == true) RIGHT(x_brick,y_brick,Brick);
				break;
	    	default:
	    		break;
		}
	}
}

void ENGINE::UPDATE1()
{
	int plus = 0,pp = 0;
	for(int i = Brick.y-1; i > -1; i--)
	{
		for(int j = 0; j < Brick.x; j++)
		{
			if (Brick.brick[i][j] == 0)
			{
				broad[y_brick+i+plus][x_brick+j] = 1;
			}
		}
		for(int j = 0; j < 10; j++)
		{
			if (broad[y_brick+i+plus][j] == 1) pp = 1;
			else
			{
				pp = 0;
				break;
			}
		}
		if (pp == 1)
		{
			// lam mau`
			for (int j = y_brick+i+plus; j > 0; j--)
				for (int k = 0; k < 10; k++)
				{
					broad[j][k] =broad[j-1][k];
				}
			for (int k = 0; k < 10; k++)
			{
				broad[0][k] = 0;
			}
			plus++;
			score++;
			setXY(toado.X+8,toado.Y+24);
			cout << score;
		}
	}
}

void ENGINE::UPDATE()
{
	int plus = 0,pp = 0;
	for(int i = Brick.y-1; i > -1; i--)  // made update
	{
		for(int j = 0; j < Brick.x; j++)
		{
			if (Brick.brick[i][j] == 0)
			{
				broad[y_brick+i+plus][x_brick+j] = 1;
			}
		}
		for(int j = 0; j < 10; j++)
		{
			if (broad[y_brick+i+plus][j] == 1) pp = 1;
			else
			{
				pp = 0;
				break;
			}
		}
		if (pp == 1)
		{
			// lam mau`
			setXY(toado.X+1,toado.Y+3+y_brick+i+plus); // animation hide
			for (int k = 0; k < 10; k++)
			{
				cout << (char)176;
				Sleep(50);
			}
			for (int j = y_brick+i+plus; j > 0; j--)   // update data table
				for (int k = 0; k < 10; k++)
				{
					broad[j][k] =broad[j-1][k];
				}
			for (int k = 0; k < 10; k++)
			{
				broad[0][k] = 0;
			}
			for (int q = 0; q < y_brick+i+plus+1; q++) // update table
			{
				setXY(toado.X+1,toado.Y+3+q);
				for (int w = 0; w < 10; w++)
				{
					if(broad[q][w] == true) cout << (char)2;
					else cout << ' ';
				}
			}
			plus++;
			for (int q = 0; q < i; q++)
			{
				for (int k = 0; k < Brick.x; k++)
				{
					if (Brick.brick[q][k] == 0)
					{
						setXY(x_brick+toado.X+k+1,y_brick+toado.Y+q+3+plus);//	x_brick+toado.X+1,y_brick+toado.Y+3
						cout << (char)2;
					}
				}
			}
			score+=plus;
			setXY(toado.X+8,toado.Y+24);
			cout << score;
		}
	}
	// check overgame

}
