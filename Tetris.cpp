#include "header.h"
#include "structure.h"
#include "brick.h"
#include "engine.h"
#include "UI.h"
 
using namespace std;
int main()
{
    WSADATA wsaData;
	WSAStartup(2.2,&wsaData);
	srand(time(0));
	UI giaodien;
	giaodien.MENU();
	return 0;
}     
