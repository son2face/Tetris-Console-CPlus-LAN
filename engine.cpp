void ENGINE::setmode(int ggg)
{
	MODE = ggg;
}
ENGINE::ENGINE()
{
	
}

ENGINE::ENGINE(string input)
{
	toado.X = 2;
	toado.Y = 0;
	MY_PORT = 4567;
	name = input;
	time = 0;
	score = 0;
	speed = 6;
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
	slngang = (sizeManhinh.X-2) /21;
	sldoc = 2;
	kcngang = (sizeManhinh.X-2-slngang*21)/(slngang-1);
	kcdoc = 0;	
}
void ENGINE::listen()
{
	sockaddr_in pAddr;
    pAddr.sin_family = AF_INET;
    pAddr.sin_port = htons(MY_PORT);
    pAddr.sin_addr.s_addr = inet_addr ("42.113.126.132");
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
    while (end == 0)
	{
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
				 IP_check.push_back(1);
				 IP_x_brick.push_back(0);
				 IP_y_brick.push_back(0);
				 IP_brickStatus.push_back(0);
				 IP_next.push_back(0);
				 IP_over.push_back(0);
				 IP_first.push_back(1);
				 n_connect ++;
			}			
		   	if (buff[0] == '.') IP_over[stt_IP] = 1;
			else 
			{
				int j = 1;
				IP_over[stt_IP] = 0;
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
			    	rtyu++;
				}
				j++;
				buff1[rtyu] = 0;
				rtyu = 0;
			    IP_time[stt_IP] = atoi(buff1)/1000;
			    while(buff[j]!=' ')
			    {
			    	buff1[rtyu] = buff[j];
			    	j++;rtyu++;
				}
				j++;
				buff1[rtyu] = 0;
				rtyu = 0;
			    IP_score[stt_IP] = atoi(buff1);
				 while(buff[j]!=' ')
			   {
			    	buff1[rtyu] = buff[j];
			    	j++;rtyu++;
				}
				j++;
				buff1[rtyu] = 0;
				rtyu = 0;
			    IP_x_brick[stt_IP] = atoi(buff1);
			     while(buff[j]!=' ')
			    {
			    	buff1[rtyu] = buff[j];
			    	j++;rtyu++;
				}
				j++;
				buff1[rtyu] = 0;
				rtyu = 0;
			    IP_y_brick[stt_IP] = atoi(buff1);
			     while(buff[j]!=' ')
			    {
			    	buff1[rtyu] = buff[j];
			    	j++;rtyu++;
				}
				j++;
				buff1[rtyu] = 0;
				rtyu = 0;
			    IP_brickStatus[stt_IP] = atoi(buff1);
			     while(buff[j]!=' ')
			    {
			    	buff1[rtyu] = buff[j];
			    	j++;rtyu++;
				}
				j++;
				buff1[rtyu] = 0;
				rtyu = 0;
			    IP_next[stt_IP] = atoi(buff1);
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
    closesocket(sock);
    end++;
}

void ENGINE::broadcast()
{
	SOCKET sock = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
	sockaddr_in pServerAddr;
    BOOL bSockBroadcast=true;
    setsockopt(sock,SOL_SOCKET,SO_BROADCAST,(char*)&bSockBroadcast,sizeof(BOOL));
    pServerAddr.sin_family = AF_INET;
    pServerAddr.sin_port = htons(MY_PORT);    
    pServerAddr.sin_addr.s_addr = inet_addr ("thanhsonuet.tk"); // Ð?a ch? dích là MULTICAST
    int nSend;
    int nRevc;
    int nAddrLen; 
	for(;;)
	{
		if(over == 1)
		{
			char buff[] = "."; // Thông tin g?i t?i máy ch?
	        nSend = sendto(sock,buff,sizeof(buff),0,(sockaddr*)&pServerAddr,sizeof(sockaddr_in));	
		}
		if(end == 2) break;
		Sleep(200);
	    stringstream out;
	    out << '"' << name << '"' << time << ' ' << score << ' ' <<  x_brick << ' ' << y_brick << ' ';
	    out << Brick.status << ' ' << Brick_next.status << ' ';
	   	for(int i = 0; i <22; i++)
			for (int j = 0; j < 10; j++)
			{
				out << broad[i][j];
			}
        string qwe = out.str();
		char buff[qwe.size()+1]; // Thông tin g?i t?i máy ch?
		copy(qwe.begin(),qwe.end(),buff); 
        nSend = sendto(sock,buff,sizeof(buff),0,(sockaddr*)&pServerAddr,sizeof(sockaddr_in));
	 } 
	 closesocket(sock);
	 end = 0;
}

void ENGINE::play()
{
	clrscr();
	structure.drawTable(toado.X,toado.Y+2);
	Start();
	drawName();
	structure.drawTable(toado.X,toado.Y+2);
	drawScore();
	drawTime();
	num_Brick2 = rand()%28;
	base_Brick2 = num_Brick2/4*4;
	Brick_next = num_Brick2+1;
	if (MODE == 1)
	{
		thread _broadcast(&ENGINE::broadcast,this);
	 	thread _listen(&ENGINE::listen,this);	
		thread _cli(&ENGINE::makeClient,this);
		_broadcast.detach();
		_listen.detach();
		_cli.detach();
	}
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
					_mutex.lock();
					setXY(toado.X+2,toado.Y+12);
					cout << "GAME OVER";
					_mutex.unlock();
					over = 1;
					Sleep(200);
					getch();
					if (MODE ==  1) end = 1;
					break;
				}
			}
		}
		if (over == 1) break;
		_mutex.lock();
		structure.undrawBrick(toado.X+15,toado.Y+4, Brick);
		structure.drawBrick(toado.X+15,toado.Y+4, Brick_next);
		structure.drawBrick(x_brick+toado.X+1,y_brick+toado.Y+3,Brick);
		_mutex.unlock();
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
	        _mutex.lock();
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
					_mutex.unlock();
					break;
				}
			}
			_mutex.unlock();
	    }
	    if (kt == 1) break;
	    key = getch();
	    int temp2 = 1;
	    _mutex.lock();
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
		_mutex.unlock();
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
			_mutex.lock();
			setXY(toado.X+1,toado.Y+3+y_brick+i+plus); // animation hide
			for (int k = 0; k < 10; k++)
			{
				cout << (char)176;
				Sleep(50);
			}
			_mutex.unlock();
			for (int j = y_brick+i+plus; j > 0; j--)   // update data table
				for (int k = 0; k < 10; k++)
				{
					broad[j][k] =broad[j-1][k];
				}
			for (int k = 0; k < 10; k++)
			{
				broad[0][k] = 0;
			}
			_mutex.lock();
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
			_mutex.unlock();
		}
	}
	// check overgame

}

void ENGINE::makeClient()
{
	while (end == 0)
	{
 	 for(int i = 0; i < n_connect; i++)
	{
		int __x_,__y_;
		if (i < slngang-1)
		{
		      __x_ = 2+21*(i+1) + kcngang*(i);
			  __y_ = 0;	
		}
		else
		{
			__x_ = 2+21*(i-slngang) + kcngang*(i-slngang);
			__y_ = 27;
		}
		if (IP_over[i] == 0)
		{

    	
    	if (IP_first[i] == 1)
    	{
    		
    		int a = (12-IP_name[i].size())/2;
			_mutex.lock();
	    	setXY(__x_+a,__y_);
	    	cout << IP_name[i];
	    	_mutex.unlock();
	    	_mutex.lock();	
			structure.drawTable(__x_,__y_+2);
			_mutex.unlock();
			IP_first[i] = 0;	
		}
			for(int op = 0; op <18; op++)
			{
				_mutex.lock();
				setXY(__x_+1,__y_+3+op);
 		        for (int iop = 0; iop < 10; iop++)
				{
					if(IP_broad[i][op][iop] == 1) cout << (char)2;
					else cout << ' ';
				}	
				_mutex.unlock();
			}
			BRICK zxcv(IP_brickStatus[i]);
			_mutex.lock();
			structure.drawBrick(__x_+1+IP_x_brick[i],__y_+3+IP_y_brick[i],zxcv);
			BRICK ghjk(IP_next[i]);
			setXY(__x_+15,__y_+4);
			cout << "    ";
			setXY(__x_+15,__y_+5);
			cout << "   ";
			setXY(__x_+15,__y_+6);
			cout << "   ";
			setXY(__x_+15,__y_+7);
			cout << " ";
			structure.drawBrick(__x_+15,__y_+4,ghjk);
			_mutex.unlock();
		}
		else 
		{
			_mutex.lock();
			setXY(__x_+2,__y_+12);
			cout << "GAME OVER";
			_mutex.unlock();	
		}
		_mutex.lock();
		setXY(__x_+1,__y_+24);
		cout << "Score: " << IP_score[i];
		_mutex.unlock();
		_mutex.lock();
		setXY(__x_+1,__y_+26);
		cout << "Time: " << IP_time[i] << 's';
		_mutex.unlock();	
	}	
}
}
void ENGINE::clear()
{
	time = 0;
	score = 0;
	speed = 6;
	prival = 100;
	over = 0;
	for(int i = 0; i < n_connect; i++)
	{
		IP_first[i] = 1;
	}
	for(int i = 0; i <22; i++)
		for (int j = 0; j < 10; j++)
		{
			broad[i][j] = 0;
		}
}
