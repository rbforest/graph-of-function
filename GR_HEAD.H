#ifndef GRHEAD
#define GRHEAD
	//         ������祭�� ���������� �㭪権.
# include <conio.h>
# include <iostream.h>
# include <iomanip.h>
# include <dos.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <ctype.h>
# include <graphics.h>
#define PATHTODRIVER "c:\\BORLANDC\\bgi\\"

const int MAX = 2000;		        // ���ᨬ��쭮� ������⢮ ��ப
					// ⠡����

enum flag {X,Y};			// 䫠�� X � Y ��� 㤮��⢠
					// ������祭�� ���न���;
float X0, Xk, dX;			// ��砫쭠�, ����筠� ���न����
					// 蠣 ᬥ饭��;
float a1,b1,a2,b2,a3,b3;		// ��㬥��� �㭪樨;

/*---------------------------- GR_INTRF.CPP --------------------------------*/
class Coordinate			// ����� ���न���
{
 private:
   float x;					// ���न��� X;
   float y;					// ���न��� Y;
 public:
   void Display(flag f);                         // �뢮� �� ��࠭;
   float& getC(flag f);				// ���� ���न���;
};

void Start();				// �뢮� ���� �� ��࠭.
void InputParameters(int &st);          // ���� ������ � ��ࠬ��஢
void DataCalc(Coordinate** CPrt, int st);	// ����� �㭪樨;
void ViewTable(Coordinate**, int);	// ����� ⠡����
void HeaderTable();			// ����� ⠡����;
void Display(Coordinate** CPrt, int st, int n); // �뢮� ⠡��� � ���᮫�;
void Graphik(Coordinate** CPrt, int st);	// �뢮� ��䨪� � ���᮫�;
void Edit(Coordinate** CPrt, int st);		// ������஢���� ⠡����;
void Display(Coordinate** CPrt, int st,int id,int n, flag f); // �뢮�
			// ⠡���� ��� ।���஢����;
void EditEl(Coordinate** CPrt,int id,int n, flag f);	// ������஢����
			// �������

/*------------------------------ GR_PROC.CPP -------------------------------*/
float getF();
float CIF(char s[]);
void CSort(Coordinate**, int);
void Order(Coordinate**, Coordinate**);
void Pisk(int n);
void Sound(int n, int dd);
void No_matr();
void Stop();                        //           �����襭�� ࠡ��� �ணࠬ��.

/*------------------------------- GR_RW.CPP --------------------------------*/
void Write(Coordinate** CPrt,int st);      // ������ � 䠩�.
void sizeSt(int &st, char name[40]);
void Read(Coordinate** CPrt,int st,char name[40]);   // �⥭�� �� 䠩��.
#endif