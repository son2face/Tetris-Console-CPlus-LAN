UI::UI()
{
    setfullscreen();
	ShowConsoleCursor(false);
    NhapMenu();
    NhapHighscore();
    NhapInstrution();
    NhapSetting();
    NhapAboutme();
    LV = 1;
    cclour = 1;
    MODE = 2;
}

void UI::runMENU()
{
    while(kbhit()) getch();
    clrscr();
    setXY(0,getsizeManHinh().Y-2);
    cout << "UI v2.0" << endl << "DESIGNED BY @SON";
    COORD T;
    T.X = menu[0].size();
    T.Y = menu.size();
    T = Center(T);
    for(int i = 0; i < menu.size(); i++)
    {
        setXY(T.X,T.Y+i);
        cout << menu[i];
    }
    ShowConsoleCursor(FALSE);
}

void UI::runINSTRUCTION()
{
    clrscr();
    COORD T;
    T.X = instructition[0].size();
    T.Y = instructition.size();
    T = Center(T);
    for(int i = 0; i < instructition.size()-1; i++)
    {
        setXY(T.X,T.Y+i);
        cout << instructition[i];
    }
    char KEY;
    while ((KEY!=13)&&(KEY!=27)) KEY = getch();
    if (KEY == 13)
    {
        GAME[0].setmode(0);
        GAME[0].play();
        score = GAME[0].score;
        GAME[0].clear();
        UPDATE();
    }
}

void UI::runABOUT()
{
    clrscr();
    COORD T;
    T.X = aboutme[0].size();
    T.Y = aboutme.size();
    T = Center(T);
    for(int i = 0; i < aboutme.size(); i++)
    {
        setXY(T.X,T.Y+i);
        cout << aboutme[i];
    }
     while (getch()!=27);
}

void UI::runHIGHSCORE()
{
    clrscr();
    COORD T = getsizeContent();
    T = Center(T);
    setXY(T.X,T.Y);
    cout << "RANK";
    setXY(T.X+15,T.Y);
    cout << "SCORE";
    setXY(T.X+31,T.Y);
    cout << "NAME";
    T.Y+=3;
    for(int i = 0; i < ni; i++)
    {
        T.Y+=2;
        setXY(T.X,T.Y);
        cout << i+1;
		setXY(T.X+15,T.Y);
		cout << score_high[i];
		setXY(T.X+31,T.Y);
		cout<< name_high[i];
    }
    T.Y +=5;
    setXY(T.X+14,T.Y);
    cout << setiosflags(ios::right) << "[ESC]  MAIN MENU";
    while(getch()!=27);
    //name: 20,  score ; 5,  rank: 4 (5)51-29 20+11+11+5+4 52-16 36
}

void UI::MENU()
{
    NAME();
    GAME = new ENGINE(Name);
    while(kbhit()) getch();
    runMENU();
    press();
}

void UI::press()
{
    
    while(1)
    {
	     while(!kbhit())
	    {
	        Clour[7] = setCFont[cclour];
	        cclour++;
	        cclour=cclour%6;
	        system(Clour);
	        for (int i =0; (i<20 && !kbhit()); i++) Sleep(50);
	    }
	    KEY = getch();
	    if (KEY == '1')
	    {
	        GAME[0].setmode(0);
	        GAME[0].play();
	        score = GAME[0].score;
     		GAME[0].clear();
	        UPDATE();
	        runMENU();  	
		}
		else if (KEY == '2')
	    {
	        GAME[0].setmode(1);
	        GAME[0].play();
	        score = GAME[0].score;
	        GAME[0].clear();
	        UPDATE();
	        runMENU();
	    }
	    else if (KEY == '3')
	    {
	        runHIGHSCORE();
	        runMENU();
	    }
	    else if (KEY == '4')
	    {
	        runINSTRUCTION();
	        runMENU();       
	    }
	    else if (KEY == '5')
	    {
	        runABOUT();
	        runMENU();
	    }
	    else if (KEY == '6')
	    {
	        break;
	    }
	}
}

void UI::setfullscreen()
{
    keybd_event(VK_MENU,0x38,0,0);
    keybd_event(VK_RETURN,0x1c,0,0);
    keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
    keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}

void UI::NhapHighscore(char name[])
{
    ifstream input;
    string temp;
    input.open(name);
    ni = 0;
    while (!input.eof())
    {
        getline(input,name_high[ni]);
        getline(input,temp);
        score_high[ni] = getNumberInline(temp);
        ni++;
    }
    input.close();
}

void UI::NhapMenu(char name[])
{
    string temp;
    ifstream input1;
    input1.open(name);
    while (!input1.eof())
    {
        getline(input1,temp);
        menu.push_back(temp);
    }
    input1.close();
}

void UI::NhapSetting(char name[])
{
    string temp;
    ifstream input1;
    input1.open(name);
    while (!input1.eof())
    {
        getline(input1,temp);
        setting.push_back(temp);
    }
    input1.close();
}

void UI::NhapInstrution(char name[])
{
    string temp;
    ifstream input2;
    input2.open(name);
    while (!input2.eof())
    {
        getline(input2,temp);
        instructition.push_back(temp);
    }
    input2.close();
}

void UI::NhapAboutme(char name[])
{
    string temp;
    ifstream input2;
    input2.open(name);
    while (!input2.eof())
    {
        getline(input2,temp);
        aboutme.push_back(temp);
    }
    input2.close();
}

COORD UI::getsizeContent()
{
    COORD _result;
    _result.X = 52;
    _result.Y = 18;
    return _result;
}

UI::~UI()
{
    string temp;
    ofstream output;
    output.open("DATA.txt");
    int i;
    for(i = 0; i < 4; i++)
    {
        output << name_high[i] << endl << score_high[i] << endl;
    }
    output << name_high[i] << endl << score_high[i];
    output.close();
}

char UI::Clour[] = "COLOR 0x";
char UI::setCFont[] = "9ABCDF";

void UI::NAME()
{
    COORD _name = Center(20,1);
    setXY(_name.X,_name.Y);
    cout << "ENTER YOUR NAME :" ;
    getline(cin,Name);
    clrscr();
    ShowConsoleCursor(FALSE);
    _name = Center(Name.size()+7,1);
    setXY(_name.X,_name.Y);
    cout << "Hello " << Name << "!";
    Sleep(2000);
}

void UI::UPDATE()
{
    int i = 6;
    while (score_high[i-1]<score&&i>0)
    {
        score_high[i] = score_high[i-1];
        name_high[i] = name_high[i-1];
        i--;
    }
    COORD td = getsizeManHinh();
    td.Y = td.Y/2;
    clrscr();    
    if (i == 0)
    {
 		setXY(td.X/2-8,td.Y-3);
		cout <<"YOUR SCORE: " << score;	    
        setXY(td.X/2-20,td.Y-1);
        cout <<"NEW BEST WAS SETTED - YOU'RE BEST PLAYER";
	    setXY(td.X/2-8,td.Y+1);
	    cout <<"HIGH SCORE: " << score;
	}
	else 
	{
		setXY(td.X/2-8,td.Y);
		cout <<"YOUR SCORE: " << score;
	}
	Sleep(5000);
    score_high[i] = score;
    name_high[i] = Name;
}

