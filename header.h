#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include<bits/stdc++.h>
#include <math.h>
#include <winsock2.h>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <string>
#include <cstring>
#include <conio.h>
#include <thread>
#include <mutex>
//#include <random>
void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

void setXY (int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void setXY (COORD coord)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
COORD getsizeManHinh()
{
    CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
    HANDLE	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);
	COORD _result;
	_result.X = csbiInfo.dwSize.X;
	_result.Y = csbiInfo.dwSize.Y;
	return _result;
}
void clrfromXY(COORD _input)
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);;
	COORD	Home;
	Home.X = _input.X;
	Home.Y = _input.Y;
	DWORD	dummy;
	GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);
	FillConsoleOutputCharacter(hConsoleOut,' ',csbiInfo.dwSize.X * csbiInfo.dwSize.Y,Home,&dummy);
	setXY(_input.X,_input.Y);
}

void clrfromXY(int x, int y)
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);;
	COORD	Home;
	Home.X = x;
	Home.Y = y;
	DWORD	dummy;
	GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);
	FillConsoleOutputCharacter(hConsoleOut,' ',csbiInfo.dwSize.X * csbiInfo.dwSize.Y,Home,&dummy);
	setXY(x,y);
} 


void clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home = {0,0};
	DWORD	dummy;
	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);
	FillConsoleOutputCharacter(hConsoleOut,' ',csbiInfo.dwSize.X * csbiInfo.dwSize.Y,Home,&dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut,csbiInfo.dwCursorPosition);
}

COORD Center(COORD& _Size)
{
    COORD toado = getsizeManHinh();
    toado.Y = (toado.Y-_Size.Y)/2;
    toado.X = (toado.X-_Size.X)/2;
    return toado;
}

WORD GetConsoleTextAttribute (HANDLE hCon)
{
  CONSOLE_SCREEN_BUFFER_INFO con_info;
  GetConsoleScreenBufferInfo(hCon, &con_info);
  return con_info.wAttributes;
}

COORD Center(int X, int Y)
{
    COORD toado = getsizeManHinh();
    toado.Y = (toado.Y-Y)/2;
    toado.X = (toado.X-X)/2;
    return toado;
}

using namespace std;

template <typename T>
string NumberToString(T pNumber)
{
 ostringstream oOStrStream;
 oOStrStream << pNumber;
 return oOStrStream.str();
}

int getNumberInline(string _input)
{
    int i;
    for(i = 0; i<_input.size(); i++)
    {
        if (_input[i]>='0'&& _input[i]<='9')  break;
    }
    if (i == _input.size()) return 0;
    else
    {
        int _result = 0;
        for (;i<_input.size();i++)
        {
            if (_input[i]>='0'&& _input[i]<='9') _result = _result*10+_input[i]-'0';
        }
        return _result;
    }
}

void setfullscreen()
{
    keybd_event(VK_MENU,0x38,0,0);
    keybd_event(VK_RETURN,0x1c,0,0);
    keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
    keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}
#endif

