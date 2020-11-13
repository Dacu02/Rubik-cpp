#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <string>
using namespace std;
/*
struct CubeLoopingException : public exception
{
	const char * c () const throw ()
    {
    	return "Cube was looping itself";
    }
};*/
/*
bianco = 15
rosso = 12
blu = 9
giallo = 14
arancione = 6 
verde = 10
NON SI INCONTRANO MAI
0 - 3 /  1 - 5  /  2 - 4
*/

class Cube{
	private:	//Here are all the properties of the object Cube
	int TIME;
	int Cubo[6][3][3];
	int x,y,z;
	bool view;
	int ContRubik;
	bool MoveCont, Debugs;
	public:
	Debugging(){
		Debugs = !Debugs;
	}
	D(int d){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[d][0][0]);
		cout<<endl<<(char) 219;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<'|';
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[d][0][1]);
		cout<<(char) 219;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<'|';
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[d][0][2]);
		cout<<(char) 219<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[d][1][0]);
		cout<<(char) 219;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<'|';
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[d][1][1]);
		cout<<(char) 219;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<'|';
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[d][1][2]);
		cout<<(char) 219<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[d][2][0]);
		cout<<(char) 219;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<'|';
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[d][2][1]);
		cout<<(char) 219;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<'|';
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[d][2][2]);
		cout<<(char) 219<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		//Debug, when abilited can see other layers
	}
	Counter(bool C){
		MoveCont=C;
		ContRubik=0;
		//Set moves counter on
	}
	Cb(){	//Output format, SetConsoleT... keeps characters colors, meanwhile system("color xy"); changes all of them (I'ts like a toTerminal())
		if(MoveCont)	//All the numbers bigger than 15 represents a character in ASCII code, 
		ContRubik++; //Counter of moves + 1 (here because every output = 1 move)
		string s,l;
		s.append(7,219);
		l.append(7,196);
		cout<<"\n      ________________________\n";
		cout<<"     /";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[z][0][0]);
		cout<<s;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<'/';
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[z][0][1]);
		cout<<s;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<'/';
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[z][0][2]);
		cout<<s;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<"/"<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<endl;
		cout<<"    /"<<l<<"/"<<l<<"/"<<l<<"/";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[y][0][2]);
		cout<<(char) 220;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char)179;
		cout<<"\n   /";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[z][1][0]);
		cout<<s;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<'/';
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[z][1][1]);
		cout<<s;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<'/';
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[z][1][2]);
		cout<<s;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<'/'<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[y][0][2]);
		cout<<(char) 219;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		cout<<endl;
		cout<<"  /"<<l<<"/"<<l<<"/"<<l<<"/";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[y][0][1]);
		cout<<(char) 220;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[y][0][2]);
		cout<<(char) 219;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		cout<<"\n /";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[z][2][0]);
		cout<<s;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<'/';
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[z][2][1]);
		cout<<s;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<'/';
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[z][2][2]);
		cout<<s;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<'/'<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[y][0][1]);
		cout<<(char) 219;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[y][0][2]);
		cout<<(char) 223;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179<<endl;
		cout<<(char) 218<<l<<(char) 194<<l<<(char) 194<<l<<'/';
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[y][0][0]);
		cout<<(char) 220;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[y][0][1]);
		cout<<(char) 219;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179<<'/'<<(char) 179<<endl;
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[x][0][0]);
		cout<<s;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[x][0][1]);
		cout<<s;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[x][0][2]);
		cout<<s;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[y][0][0]);
		cout<<(char) 219;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[y][0][1]);
		cout<<(char) 223;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<'/';
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[y][1][2]);
		cout<<(char) 220;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179<<endl;
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[x][0][0]);
		cout<<s;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[x][0][1]);
		cout<<s;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[x][0][2]);
		cout<<s;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[y][0][0]);
		cout<<(char) 219;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179<<'/'<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[y][1][2]);
		cout<<(char) 219;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179<<endl;
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[x][0][0]);
		cout<<s;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[x][0][1]);
		cout<<s;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[x][0][2]);
		cout<<s;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[y][0][0]);
		cout<<(char) 223;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<'/';
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[y][1][1]);
		cout<<(char) 220;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[y][1][2]);
		cout<<(char) 219;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179<<endl<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[x][0][0]);
		cout<<s;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[x][0][1]);
		cout<<s;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[x][0][2]);
		cout<<s;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179<<'/'<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[y][1][1]);
		cout<<(char) 219;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[y][1][2]);
		cout<<(char) 223;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		cout<<endl<<(char) 195<<l<<(char) 197<<l<<(char) 197<<l<<(char) 180;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[y][1][0]);
		cout<<(char) 220;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[y][1][1]);
		cout<<(char) 219;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179<<'/'<<(char) 179<<endl;
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[x][1][0]);
		cout<<s;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[x][1][1]);
		cout<<s;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[x][1][2]);
		cout<<s;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[y][1][0]);
		cout<<(char) 219;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[y][1][1]);
		cout<<(char) 223;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<'/';
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[y][2][2]);
		cout<<(char) 220;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179<<endl;
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[x][1][0]);
		cout<<s;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[x][1][1]);
		cout<<s;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[x][1][2]);
		cout<<s;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[y][1][0]);
		cout<<(char) 219;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179<<'/'<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[y][2][2]);
		cout<<(char) 219;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[x][1][0]);
		cout<<s;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[x][1][1]);
		cout<<s;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[x][1][2]);
		cout<<s;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[y][1][0]);
		cout<<(char) 223;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<'/';
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[y][2][1]);
		cout<<(char) 220;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[y][2][2]);
		cout<<(char) 219;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[x][1][0]);
		cout<<s;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[x][1][1]);
		cout<<s;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[x][1][2]);
		cout<<s;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179<<'/'<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[y][2][1]);
		cout<<(char) 219;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[y][2][2]);
		cout<<(char) 223;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<'/';
		cout<<endl<<(char) 195<<l<<(char) 197<<l<<(char) 197<<l<<(char) 180;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[y][2][0]);
		cout<<(char) 220;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[y][2][1]);
		cout<<(char) 219;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179<<'/'<<endl<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[x][2][0]);
		cout<<s;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[x][2][1]);
		cout<<s;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[x][2][2]);
		cout<<s;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[y][2][0]);
		cout<<(char) 219;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[y][2][1]);
		cout<<(char) 223;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<'/'<<endl<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[x][2][0]);
		cout<<s;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[x][2][1]);
		cout<<s;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[x][2][2]);
		cout<<s;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[y][2][0]);
		cout<<(char) 219;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		cout<<'/'<<endl<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[x][2][0]);
		cout<<s;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[x][2][1]);
		cout<<s;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[x][2][2]);
		cout<<s;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[y][2][0]);
		cout<<(char) 223;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<'/'<<endl<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[x][2][0]);
		cout<<s;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[x][2][1]);
		cout<<s;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cubo[x][2][2]);
		cout<<s;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout<<(char) 179<<'/'<<endl;
		cout<<(char) 192<<l<<(char) 193<<l<<(char) 193<<l<<(char) 217;
		if(Debugs)
		{
		D(getOpposite(x));
		D(getOpposite(y));	//Debug options
		D(getOpposite(z));}
		Sleep(TIME);	//Waits TIME milliseconds
		}
	Cube(){		//Here we give values to all the proprerties   C O N S T R U C T O R
			TIME=150;
			ContRubik=0;
			x=0, y=1, z=2;
			int i,j,k;
			for(i=0;i<6;i++)
				for(j=0;j<3;j++)
					for(k=0;k<3;k++){
						switch(i){
						case 0:
							Cubo[i][j][k]=15;
						break;
						case 1:
							Cubo[i][j][k]=6;
						break;
						case 2:
							Cubo[i][j][k]=10;
						break;
						case 3:
							Cubo[i][j][k]=14;
						break;
						case 4:
							Cubo[i][j][k]=9;
						break;
						case 5:
							Cubo[i][j][k]=12;
						break;
						}
			}
		}
	setPiece(int a, int b, int c, int p){
		Cubo[a][b][c]=p;	//Debug, change one piece color (if used wrong program may not work)
	}
	getOpposite(int n){	//Takes the color, and gives the opposite face color 
		switch(n){
			case 0: 
				return 3;
			break;
			case 1:
				return 5;
			break;
			case 2:
				return 4;
			break;
			case 3:
				return 0;
			break;
			case 4:
				return 2;
			break;
			case 5:
				return 1;
			break;
		}
	}
	setTime(int T){	//Sets the time between outputs 
		TIME=T;
	}
	WO(){	//Rotates the cube until the white face is up
		if(Cubo[getOpposite(z)][1][1]!=15){
			if(Cubo[x][1][1]==15||Cubo[z][1][1]==15||Cubo[getOpposite(x)][1][1]==15){
				do{
					moveX(false);
				}while(Cubo[(getOpposite(z))][1][1]!=15);
			}
			else{
				do{
					moveZ(false);
				}while(Cubo[getOpposite(z)][1][1!=15]);
			}
		}
	}
	moveX(bool r){	//Moves the cube in X
		int n;
		S(r, y);
		S(!r, getOpposite(y));
		if(r){
			INV(true, x);
			INV(true, getOpposite(x));
			n=z; 		
			z=getOpposite(x);		
			x=n;
		}else{
			INV(true, z);
			INV(true, getOpposite(z));
			n=x;
			x=getOpposite(z);
			z=n;
		}
	}
	moveY(bool r){	//Moves the cube in Y
		int n;
		INV(false, getOpposite(x));
		S(!r, z);
		S(!r, getOpposite(z));
		if(r){
			n=y;
			y=getOpposite(x);
			x=n;
		}else{
			n=x;
			x=getOpposite(y);
			y=n;
		}
		INV(false, getOpposite(x));
	}
	moveZ(bool r){	//Moves the cube in Z
		int n;
		S(r, x);
		S(r, getOpposite(x));
		S(false, getOpposite(z));
		S(r, z);
		INV(true, getOpposite(z));
		if(r){
			S(r, z);
			n=y;
			y=getOpposite(z);
			z=n;
		}else{
			n=z;
			z=getOpposite(y);
			y=n;
			S(!r, getOpposite(y));
		}
		S(r, z);
		S(r, getOpposite(z));
		INV(true, getOpposite(z));
		S(!r, getOpposite(y));
	}
	moveF(bool r, char c){	//Moves the layer like user choice, all moves are made with R and X Y Z moves
			switch(c){
			case 'r':
				moveR(r);
			break;
			case 'l':
				moveY(true);
				moveY(true);
				moveR(r);
				moveY(true);
				moveY(true);
			break;
			case 'u':
				moveZ(false);
				moveR(r);
				moveZ(true);
			break;
			case 'd':
				moveZ(true);
				moveR(r);
				moveZ(false);
			break;
			case 'f':
				moveY(false);
				moveR(r);
				moveY(true);
			break;
			case 'b':
				moveY(true);
				moveR(r);
				moveY(false);
			break;
		}
			if(view)
				Cb();
	}
	moveR(bool r){	//Moves the right layer 
		int i,n,m;
		S(r, y);
		if(r){
			for(i=0;i<3;i++){
				n=Cubo[x][i][2];
				Cubo[x][i][2]=Cubo[z][i][2];
				m=Cubo[getOpposite(z)][i][2];
				Cubo[getOpposite(z)][i][2]=n;
				Cubo[z][i][2]=Cubo[getOpposite(x)][i][2];
				Cubo[getOpposite(x)][i][2]=m;
			}
			n=Cubo[z][0][2];
			Cubo[z][0][2]=Cubo[z][2][2];
			Cubo[z][2][2]=n;
			n=Cubo[getOpposite(z)][0][2];
			Cubo[getOpposite(z)][0][2]=Cubo[getOpposite(z)][2][2];
			Cubo[getOpposite(z)][2][2]=n;
		}else{
			for(i=0;i<3;i++){
				n=Cubo[z][i][2];
				Cubo[z][i][2]=Cubo[x][i][2];
				m=Cubo[getOpposite(x)][i][2];
				Cubo[getOpposite(x)][i][2]=n;
				Cubo[x][i][2]=Cubo[getOpposite(z)][i][2];
				Cubo[getOpposite(z)][i][2]=m;
			}
			n=Cubo[x][0][2];
			Cubo[x][0][2]=Cubo[x][2][2];
			Cubo[x][2][2]=n;
			n=Cubo[getOpposite(x)][0][2];
			Cubo[getOpposite(x)][0][2]=Cubo[getOpposite(x)][2][2];
			Cubo[getOpposite(x)][2][2]=n;
		}
	}
	INV(bool r, int dim){	//Program function, reverses a layer
	int n,i;
	if(r){
			for(i=0;i<3;i++){
			n=Cubo[dim][0][i];
			Cubo[dim][0][i]=Cubo[dim][2][i];
			Cubo[dim][2][i]=n;
			}
	}else{
			for(i=0;i<3;i++){
			n=Cubo[dim][i][2];
			Cubo[dim][i][2]=Cubo[dim][i][0];
			Cubo[dim][i][0]=n;
			}
		}
	}
	S(bool r, int dim){	//Program function, rotate a face, but not the background 
		int n,m;
		if(r){
			n=Cubo[dim][2][0];
			Cubo[dim][2][0]=Cubo[dim][0][0];
			m=Cubo[dim][2][2];
			Cubo[dim][2][2]=n;
			n=Cubo[dim][0][2];
			Cubo[dim][0][2]=m;
			Cubo[dim][0][0]=n;
			//LATI SU, ANGOLI GIU
			n=Cubo[dim][0][1];
			Cubo[dim][0][1]=Cubo[dim][1][2];
			m=Cubo[dim][1][0];
			Cubo[dim][1][0]=n;
			n=Cubo[dim][2][1];
			Cubo[dim][2][1]=m;
			Cubo[dim][1][2]=n;
	}else{
			n=Cubo[dim][0][2];
			Cubo[dim][0][2]=Cubo[dim][0][0];
			m=Cubo[dim][2][2];
			Cubo[dim][2][2]=n;
			n=Cubo[dim][2][0];
			Cubo[dim][2][0]=m;
			Cubo[dim][0][0]=n;
			//LATI SU, ANGOLI GIU
			n=Cubo[dim][1][2];
			Cubo[dim][1][2]=Cubo[dim][0][1];
			m=Cubo[dim][2][1];
			Cubo[dim][2][1]=n;
			n=Cubo[dim][1][0];
			Cubo[dim][1][0]=m;
			Cubo[dim][0][1]=n;
		}
	}
	bool Done(){	//Verifies if cube is done
		int i, j, k, s=0;
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				s+=Cubo[x][i][j];
			}
		}
		if(s/Cubo[x][1][1]!=9)
		return false;
		for(i=0;i<6;i++){
			for(j=0;j<3;j++){
				for(k=0;k<3;k++){
					if(Cubo[i][j][k]!=Cubo[i][1][1])
						return false;
				}
			}
		}
		return true;
	}
	Scramble(int var){	//Simply, scrambles the cube with normal moves
		int i, n;
		bool b = false, v;
		v=view;
		view=false;
		srand(time(NULL));
		for(i=0;i<var;i++){
			n=rand()%6;
			b=!b;
			switch(n){
				case 0:
					moveF(b, 'r');
				break;
				case 1:
					moveF(b, 'l');
				break;
				case 2:
					moveF(b, 'u');
				break;
				case 3:
					moveF(b, 'd');
				break;
				case 4:
					moveF(b, 'f');
				break;
				case 5:
					moveF(b, 'b');
				break;
			}		
		}
		view=v;
	}
	//All functions after are part of my RESOLVER ALGORITHM, based on Jessica FRIDRICH and layer-by-layer resolution algorithms
	//Every function can be done only if previous functions are already done, otherwise program may not work
	WCross(){	//First function of RA, makes a white cross 
		int i;
		WO();
		while((Cubo[0][0][1]+Cubo[0][1][0]+Cubo[0][1][2]+Cubo[0][2][1])!=(Cubo[0][1][1]*4)){
			while(Cubo[x][0][1]==15||Cubo[x][1][0]==15||Cubo[x][2][1]==15||Cubo[x][1][2]==15){
			if(Cubo[x][0][1]==15||Cubo[x][2][1]==15){
				while(Cubo[0][2][1]==15)
					moveF(false, 'd');
				moveF(false, 'f');
			}
			if(Cubo[x][1][0]==15){
				while(Cubo[0][1][0]==15)
					moveF(false, 'd');
				moveF(true, 'l');
			}
			if(Cubo[x][1][2]==15){
				while(Cubo[0][1][2]==15)
					moveF(false, 'd');
				moveF(false, 'r');
			}
		}
		moveY(false);
		while(Cubo[3][0][1]==15||Cubo[3][1][0]==15||Cubo[3][2][1]==15||Cubo[3][1][2]==15){
			if(Cubo[3][2][1]==15){
				while(Cubo[0][2][1]==15)
					moveF(false, 'd');
				moveF(false, 'f');
				moveF(false, 'f');
			}
			moveY(false);
			}
		}
		for(i=0;i<4;i=i){
			if(Cubo[x][2][1]!=Cubo[x][1][1])
			{
				i=0;
				moveF(false, 'f');
				moveF(false, 'f');
				do{
					do{
						moveY(true);
						moveF(true, 'u');
					}while(Cubo[x][0][1]!=Cubo[x][1][1]);
					moveF(false, 'f');
					moveF(false, 'f');
				}while(Cubo[z][2][1]==15);
			}
			else{
				i++;
			}
			moveY(true);
		}
	}
	NANG(){	//Second function of RA, moves angles and resolves first layer
		WO();
		int a,b,c,i,v[4];
		for(i=0;i<16;i++){
			if(Cubo[x][2][2]==15||Cubo[y][2][0]==15||Cubo[0][2][2]==15){
				if(Cubo[x][2][2]!=Cubo[x][1][1]||Cubo[y][2][0]!=Cubo[y][1][1]||Cubo[0][2][2]!=15){
					moveF(false, 'r');
					moveF(false, 'u');
					moveF(true, 'r');
					moveF(true, 'u');
				}
			}
			if(Cubo[x][0][2]==15||Cubo[z][2][2]==15||Cubo[y][0][0]==15){
					a=Cubo[x][0][2];
					b=Cubo[y][0][0];
					c=Cubo[z][2][2];
					while(!((a==Cubo[x][1][1]||b==Cubo[x][1][1]||c==Cubo[x][1][1])&&(a==Cubo[y][1][1]||b==Cubo[y][1][1]||c==Cubo[y][1][1]))){
						moveF(true,'u');
						moveY(true);
					}
					while(Cubo[0][2][2]!=15||Cubo[x][2][2]!=Cubo[x][1][1]||Cubo[y][2][0]!=Cubo[y][1][1]){
						moveF(false, 'r');
						moveF(false, 'u');
						moveF(true, 'r');
						moveF(true, 'u');
					}
			}else{
				moveY(false);
			}
		}
	}
	CDL(){	//DL DEBUGGING RA3 PROBLEM
		// 1 2 4 5
		bool c1 = (Cubo[x][1][0] == Cubo[x][1][1]) and (Cubo[x][1][2] == Cubo[x][1][2]) and (Cubo[x][1][0] == Cubo[x][1][2]);
		bool c2 = (Cubo[y][1][0] == Cubo[y][1][1]) and (Cubo[y][1][2] == Cubo[y][1][2]) and (Cubo[y][1][0] == Cubo[y][1][2]);
		bool c3 = (Cubo[getOpposite(x)][1][0] == Cubo[getOpposite(x)][1][1]) and (Cubo[getOpposite(x)][1][2] == Cubo[getOpposite(x)][1][2]) and (Cubo[getOpposite(x)][1][0] == Cubo[getOpposite(x)][1][2]);
		bool c4 = (Cubo[getOpposite(y)][1][0] == Cubo[getOpposite(y)][1][1]) and (Cubo[getOpposite(y)][1][2] == Cubo[getOpposite(y)][1][2]) and (Cubo[getOpposite(y)][1][0] == Cubo[getOpposite(y)][1][2]);
		if (not(c1 and c2 and c3 and c4)){
			if(c1)
				if(not c2)
					moveY(false);
				else
					if(not c3){
						moveY(false);
						moveY(false);
					}
					else
						moveY(true);
			if(Cubo[x][1][1]!=Cubo[x][1][2]){
				moveF(false, 'u');
				moveF(false, 'r');
				moveF(true, 'u');
				moveF(true, 'r');
				moveF(true, 'u');
				moveF(true, 'f');
				moveF(false, 'u');
				moveF(false, 'f');
			}else{
				moveF(true, 'u');
				moveF(true, 'l');
				moveF(false, 'u');
				moveF(false ,'l');
				moveF(false, 'u');
				moveF(false, 'f');
				moveF(true, 'u');
				moveF(true, 'f');
			}
		}
		return (not (c1 and c2 and c3 and c4));
	}
	DL(){	//Third part of RA, resolves the second layer with the L-to-L algorithm
		WO();
		int i,a,b;
		do{
			for(i=0;i<16;i++){
				if(Cubo[x][0][1]!=14&&Cubo[3][2][1]!=14){
					a=Cubo[x][0][1];
					b=Cubo[3][2][1];
					while(a!=Cubo[x][1][1]){
						moveF(true, 'u');
						moveY(true);
					}
					if(b==Cubo[y][1][1]){
						moveF(false, 'u');
						moveF(false, 'r');
						moveF(true, 'u');
						moveF(true, 'r');
						moveF(true, 'u');
						moveF(true, 'f');
						moveF(false, 'u');
						moveF(false, 'f');
					}else{
						moveF(true, 'u');
						moveF(true, 'l');
						moveF(false, 'u');
						moveF(false ,'l');
						moveF(false, 'u');
						moveF(false, 'f');
						moveF(true, 'u');
						moveF(true, 'f');
					}
				}else{
					if((Cubo[x][1][2]!=14&&Cubo[y][1][0]!=14)&&(Cubo[x][1][2]!=Cubo[x][1][1]&&Cubo[y][1][0]!=Cubo[y][1][1])){
						moveF(false, 'u');
						moveF(false, 'r');
						moveF(true, 'u');
						moveF(true, 'r');
						moveF(true, 'u');
						moveF(true, 'f');
						moveF(false, 'u');
						moveF(false, 'f');
					}else{
						moveY(true);
					}
				}
			}
		}while(CDL());
	}
	YCross(){	//Fourth part of the RA, makes a yellow cross with corners colors placed right
		WO();
		int b=0, i,j;
		while(Cubo[z][0][1]!=14||Cubo[z][1][0]!=14||Cubo[z][2][1]!=14||Cubo[z][1][2]!=14){
			if(Cubo[z][1][0]==14&&Cubo[z][1][2]==14){
				b=1;
			}else{
				moveY(false);
				if(Cubo[z][1][0]==14&&Cubo[z][1][2]==14){
					b=1;
				}else{
					for(i=0;i<3;i++){
						if(Cubo[z][1][0]==14&&Cubo[z][0][1]==14){
							b=2;
							i=4;
						}else{
							moveY(false);
						}
					}
					if(i==3){
						b=1;
					}
				}
			}
			for(b=b;b>0;b--){
				moveF(false, 'f');
				moveF(false, 'r');
				moveF(false, 'u');
				moveF(true, 'r');
				moveF(true, 'u');
				moveF(true, 'f');
			}
		}
		while(Cubo[x][0][1]!=Cubo[x][1][1]||Cubo[y][0][1]!=Cubo[y][1][1]||Cubo[getOpposite(x)][0][1]!=Cubo[getOpposite(x)][1][1]||Cubo[getOpposite(y)][0][1]!=Cubo[getOpposite(y)][1][1]){
			if(Cubo[x][0][1]==Cubo[x][1][1]&&Cubo[getOpposite(x)][0][1]==Cubo[getOpposite(x)][1][1]){
				moveF(false, 'r');
				moveF(false, 'u');
				moveF(true, 'r');
				moveF(false, 'u');
				moveF(false, 'r');
				moveF(false, 'u');
				moveF(false, 'u');
				moveF(true, 'r');
				moveF(false, 'u');
				moveY(true);
				moveF(false, 'r');
				moveF(false, 'u');
				moveF(true, 'r');
				moveF(false, 'u');
				moveF(false, 'r');
				moveF(false, 'u');
				moveF(false, 'u');
				moveF(true, 'r');
			}else{
				if(Cubo[x][0][1]==Cubo[x][1][1]&&Cubo[y][0][1]==Cubo[y][1][1]){
					moveY(false);
					moveF(false, 'r');
					moveF(false, 'u');
					moveF(true, 'r');
					moveF(false, 'u');
					moveF(false, 'r');
					moveF(false, 'u');
					moveF(false, 'u');
					moveF(true, 'r');
				}
			}
			bool q,d,o;
			q=!(Cubo[x][1][1]!=Cubo[x][0][1]||Cubo[y][1][1]!=Cubo[y][0][1]||Cubo[getOpposite(y)][1][1]!=Cubo[getOpposite(y)][0][1]||Cubo[getOpposite(x)][1][1]!=Cubo[getOpposite(x)][0][1]);
			d=((Cubo[x][1][1]==Cubo[x][0][1]&&Cubo[y][1][1]==Cubo[y][0][1])||(Cubo[y][1][1]==Cubo[y][0][1]&&Cubo[getOpposite(x)][1][1]==Cubo[getOpposite(x)][0][1])||(Cubo[x][1][1]==Cubo[x][0][1]&&Cubo[getOpposite(y)][1][1]==Cubo[getOpposite(y)][0][1])||(Cubo[getOpposite(x)][1][1]==Cubo[getOpposite(x)][0][1]&&Cubo[getOpposite(y)][1][1]==Cubo[getOpposite(y)][0][1]));
			o=((Cubo[x][1][1]==Cubo[x][0][1]&&Cubo[getOpposite(x)][1][1]==Cubo[getOpposite(x)][0][1])||(Cubo[y][1][1]==Cubo[y][0][1]&&Cubo[getOpposite(y)][1][1]==Cubo[getOpposite(y)][0][1]));
			for(i=0;i<4&&(!(q||d||o));i++){
				moveF(true, 'u');
			q=!(Cubo[x][1][1]!=Cubo[x][0][1]||Cubo[y][1][1]!=Cubo[y][0][1]||Cubo[getOpposite(y)][1][1]!=Cubo[getOpposite(y)][0][1]||Cubo[getOpposite(x)][1][1]!=Cubo[getOpposite(x)][0][1]);
			d=((Cubo[x][1][1]==Cubo[x][0][1]&&Cubo[y][1][1]==Cubo[y][0][1])||(Cubo[y][1][1]==Cubo[y][0][1]&&Cubo[getOpposite(x)][1][1]==Cubo[getOpposite(x)][0][1])||(Cubo[x][1][1]==Cubo[x][0][1]&&Cubo[getOpposite(y)][1][1]==Cubo[getOpposite(y)][0][1])||(Cubo[getOpposite(x)][1][1]==Cubo[getOpposite(x)][0][1]&&Cubo[getOpposite(y)][1][1]==Cubo[getOpposite(y)][0][1]));
			o=((Cubo[x][1][1]==Cubo[x][0][1]&&Cubo[getOpposite(x)][1][1]==Cubo[getOpposite(x)][0][1])||(Cubo[y][1][1]==Cubo[y][0][1]&&Cubo[getOpposite(y)][1][1]==Cubo[getOpposite(y)][0][1]));
			}
			if(!q){
				if(o){
					if(Cubo[x][1][1]!=Cubo[x][0][1]||Cubo[getOpposite(x)][1][1]!=Cubo[getOpposite(x)][0][1]){
						moveY(false);
					}
				}else{
					if(d){
						while(Cubo[x][1][1]!=Cubo[x][0][1]||Cubo[y][1][1]!=Cubo[y][0][1])
							moveY(true);
					}
				}
			}
		}
	}
	LA(){	//Fifth and last part of RA, with RUR'U' algorithm sets last angles of yellow cross right 
		WO();
		bool e=true;
		int a,b,c,i,j;
		for(i=0;i<4;i++){
			a=Cubo[x][0][0];
			b=Cubo[z][2][0];
			c=Cubo[getOpposite(y)][0][2];
			if((a==Cubo[x][1][1]||b==Cubo[x][1][1]||c==Cubo[x][1][1])&&(a==Cubo[getOpposite(y)][1][1]||b==Cubo[getOpposite(y)][1][1]||c==Cubo[getOpposite(y)][1][1])){
				i=5;
			}
			moveY(false);
		}
		if(i==4){
			do{
				moveF(false, 'r');
				moveF(true, 'u');
				moveF(true, 'l');
				moveF(false, 'u');
				moveF(true, 'r');
				moveF(true, 'u');
				moveF(false, 'l');
				moveF(false, 'u');
				a=Cubo[x][0][2];
				b=Cubo[y][0][0];
				c=Cubo[z][2][2];
			}while(!(a==Cubo[x][1][1]||b==Cubo[x][1][1]||c==Cubo[x][1][1])&&(a==Cubo[y][1][1]||b==Cubo[y][1][1]||c==Cubo[y][1][1]));
		}
		for(i=0;i<5;i++){
			a=Cubo[x][0][0];
			b=Cubo[getOpposite(y)][0][2];
			c=Cubo[z][2][0];
			if((a==Cubo[getOpposite(y)][1][1]||b==Cubo[getOpposite(y)][1][1]||c==Cubo[getOpposite(y)][1][1])&&(a==Cubo[x][1][1]||b==Cubo[x][1][1]||c==Cubo[x][1][1])){
				do{
					a=Cubo[x][0][2];
					b=Cubo[y][0][0];
					c=Cubo[z][2][2];
					if((a==Cubo[x][1][1]||b==Cubo[x][1][1]||c==Cubo[x][1][1])&&(a==Cubo[y][1][1]||b==Cubo[y][1][1]||c==Cubo[y][1][1])){
						e=false;
					}else{
					i=0;
					moveF(false, 'r');
					moveF(true, 'u');
					moveF(true, 'l');
					moveF(false, 'u');
					moveF(true, 'r');
					moveF(true, 'u');
					moveF(false, 'l');
					moveF(false, 'u');
				}
			}while(e);
			e=true;
			}else{
				moveY(true);
			}
		}
		moveX(false);
		moveX(false);
		while(!Done()){
			if(Cubo[3][2][2]==14){
			}else{
				if(Cubo[x][2][2]==14){
					for(j=0;j<4;j++){
						moveF(false, 'r');
						moveF(false, 'u');
						moveF(true, 'r');
						moveF(true, 'u');
					}
				}else{
					for(j=0;j<2;j++){
						moveF(false, 'r');
						moveF(false, 'u');
						moveF(true, 'r');
						moveF(true, 'u');
					}
				}
			}
				moveF(true, 'd');
		}
	}
	//RA functions end
	//New functions after
	VON(){	//Sets view mode on
		view=true;
	}
	VOFF(){	//Sets view mode off
		view=false;
	}
	getContMoves(){	//Gets total moves
		return ContRubik;
	}
};
//This algorithm took me a year, enjoy!
//All conditions are harder that they seems, even I can't remember them all
FS(){	//Full screen of WINDOWS OS TERMINAL
	system("mode con COLS=700");
	ShowWindow(GetConsoleWindow(),SW_MAXIMIZE);
	SendMessage(GetConsoleWindow(),WM_SYSKEYDOWN,VK_RETURN,0x20000000);
}
main(){
	/*try{
		cout<<0/0;
		throw CubeLoopingException();
	}
	catch(runtime_error& e){
		cout<<"Catched";
	}
	*/
	srand(0);	//Random functions starts
	Cube Rubik;	//Creates a Cube called Rubik
	int tm;
	int dx, dy, dz, dc;
	int s;
	string SI;
	bool t=true;
	bool r;
	char c;
	FS();	//Sets full screen
	int i;
	Rubik.Cb();
	Rubik.VOFF();
	cout<<"\nInserire H per accedere ai comandi\n"; // Rumeno - Inglese
	while(t){
		cout<<endl;
		cout<<"Inserisci input: ";
		cin>>SI;
		for(i=0;i<SI.length();i++){
			if(i<SI.length()-1)
				r = SI[i+1]=='\'';
			c=SI[i];
		/*
		cin>>c;
		r=false;
		if(c=='\''){
			r=true;
			cin>>c;
		}*/
			if(c<97)
				c+=32;
			switch(c){
			case 'x':
				Rubik.moveX(r);
				Rubik.Cb();
			break;
			case 'y':
				Rubik.moveY(!r);
				Rubik.Cb();
			break;
			case 'z':
				Rubik.moveZ(r);
				Rubik.Cb();
			break;
			case 'a':	//When input is a, AR starts resolving cube
				Rubik.VON();
				Rubik.Counter(true);
				Rubik.WCross();
				Rubik.NANG();
				Rubik.DL();
				Rubik.YCross();
				Rubik.LA();
				Rubik.VOFF();
				cout<<"\nCubo risolto in "<<Rubik.getContMoves()<<" mosse\n";	//Rumeno - Inglese
				Rubik.Counter(false);
				if(Rubik.Done()){
					cout<<"\n\nCubo risolto!"<<endl;	//Rumeno - Inglese
					sleep(2);
				}
			break;
			case 's':	//S for scramble
				Rubik.Scramble(40);
				Rubik.Cb();
			break;
			case 'n':	//N is second AR function
				Rubik.VON();
				Rubik.NANG();
				Rubik.VOFF();
			break;
			case 'w':	//W sets white face up 
				Rubik.VON();
				Rubik.WCross();
				Rubik.VOFF();
			break;
			case 't':	//T is third AR function
				Rubik.VON();
				Rubik.DL();
				Rubik.VOFF();
			break;
			case 'g':	//G is fourth AR function
				Rubik.VON();
				Rubik.YCross();
				Rubik.VOFF();
			break;
			case 'e':	//E is fifth AR function
				Rubik.VON();
				Rubik.LA();
				Rubik.VOFF();
			break;
			case 'h':	//H of HELP , TRADUCI  --------------
				cout<<"\n________________________________________________________________________________________________________";
				cout<<"\n\n\t\tMOVIMENTI DEL CUBO\n\nInserisci X per muovere il cubo verso l\'asse X\ninserisci Y per muoverlo verso l\'asse Y\ninserisci Z per muoverlo verso l\'asse Z\n";
				cout<<"\n\t\tMOVIMENTI LATERALI\n\nInserisci R per muovere il lato destro, L per quello sinistro\ninserisci U per muovere il lato superiore, D per quello inferiore\ninserisci F per muovere il lato frontale, B per quello posteriore\n";
				cout<<"\n\t\tAUTORISOLUZIONE\n\nInserisci S per mischiare il cubo e A per risolverlo\n";
				cout<<"Per risolvere una parte del cubo inserire W, N, T, G oppure E\n";
				cout<<"\n\t\tINFO\n\nOgni movimento puo\' essere compiuto all'inverso inviando la lettera e l'apostrofo >  \' \nInserisci Q per modificare la velocita\' dei movimenti\n";
				cout<<"Inserisci H per rileggere i comandi\n";
				cout<<"\n________________________________________________________________________________________________________\n";
				Rubik.Cb();
			break;
			case 'q':	//When q changes time between moves
				cout<<"\nInserisci il tempo in millisecondi\n";
				cin>>tm;
				Rubik.setTime(tm);
			break;
			case 'm':
				cout<<"Inserisci x: ";
				cin>>dx;
				cout<<"Inserisci y: ";
				cin>>dy;
				cout<<"Inserisci z: ";
				cin>>dz;
				cout<<"Inserisci il numero corrispondente al colore: ";
				cin>>dc;
				Rubik.setPiece(dx,dy,dz,dc);
					Rubik.Cb();
			break;
			case 'k':
				Rubik.Debugging();
			break;
			default:	//When is a characrter not mentioned before, goes here
				Rubik.moveF(r, c);
				Rubik.Cb();
			}
			if (r)
				i++;
			r=false;
		}
//		if(Rubik.Done())
//			cout<<"\nCubo risolto\n";
	}
}
