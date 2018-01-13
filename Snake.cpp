#include<iostream>
#include <conio.h>
#include <vector>
#include <cstdlib>
#include <Windows.h>
#include<ctime>
using namespace std;
vector <int> sx(20);
vector <int> sy(20);
char map[20][20];
int fx,fy,L=1,d=0;
HANDLE hOutput;
void cls();
void Anew();
void food();
void drew();
void AddLong(int ox,int oy);
void W(int &ox,int &oy);
void walk();
void eat();
void GameBegin();
void End();
int main()
{
	Anew();
	food();
	drew();
	GameBegin();
	return 0;
}
void cls()
{
    COORD coord={0,0};
    hOutput=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, coord);
}
void Anew()
{
	
	sx[0]=sy[0]=9;
	for(int i=0;i<20;i++)
	    for(int j=0;j<20;j++)
	        map[j][i]='-';
	map[sx[0]][sy[0]]='*';
}
void food()
{
	srand((unsigned)time(NULL));
	fx=rand()%20;
	fy=rand()%20;
	map[fx][fy]='@';
 } 
 void eat()
 {
 	if(sx[0]==fx && sy[0]==fy)
 	{
 		map[fx][fy]='-';
 		food();
 		L++;
	 }
 }
void drew()
{	
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<20;j++)
		{
			cout<<map[j][i];
		}
		if(i==9)
		{
			cout<<"       ³¤¶È:"<<L<<endl;
		}
		else
		{
			cout<<endl;
		}
	}	 
	map[sx[0]][sy[0]]='-';
	for(int i=1;i<L;i++)
	{
		map[sx[i]][sy[i]]=map[sx[i-1]][sy[i-1]]='-';
	}  
}
void AddLong(int ox,int oy)
{
	int Ox,Oy;
	map[sx[0]][sy[0]]='*';
	for(int i=1;i<L;i++)
	{
		Ox=sx[i];
		Oy=sy[i];
		sx[i]=ox;
		sy[i]=oy;
		ox=Ox;
		oy=Oy;
		map[sx[i]][sy[i]]=map[sx[i-1]][sy[i-1]]='*';
	}
}
void End()
{
	if(sx[0]<-1||sx[0]>21||sy[0]<-1||sy[0]>21)
	{
		system("cls");
		cout<<"Your Lost!"<<endl;
		cout<<"the game is over"<<endl;
		Sleep(500);
		exit(0);
	}
}
void W(int &ox,int &oy)
{
	AddLong(ox,oy);
	cls();
	Sleep(200);		
	drew();
	walk();
	eat();
	End();
}
void walk()
{
	if(kbhit())
	{
		char s=getch();
		int ox=sx[0];
		int oy=sy[0];
		switch (s)
		{
			case 'w':
	
				for(;sy[0]>=0;sy[0]--)
				{
					W(ox,oy);
					oy=sy[0];
				}
				break;
			case 's':
				for(;sy[0]>=0;sy[0]++)
				{
					W(ox,oy);
					oy=sy[0];
				}
				break;
			case 'a':
				for(;sx[0]>=0;sx[0]--)
				{
					W(ox,oy); 
					ox=sx[0];
				}
				break;
			case 'd':
				for(;sx[0]>=0;sx[0]++)
				{
					W(ox,oy);
					ox=sx[0];
				}
				break;
				
		}
	}
}
void GameBegin()
{
	while (true)
	{
		walk();
	}
}
