#include "GR_HEAD.h"
/*-------------------------------------------------------------------------*/
void Coordinate::Display(flag f)                         // �뢮� �� ��࠭;
    { f? cout << y : cout << x; }
//--------------------------------------------------------------------------
float& Coordinate::getC(flag f)				// ���� ���न���;
    {
     if(f) return y;
     else return x;
    }
//--------------------------------------------------------------------------
void Start()               //                   �뢮� ���� �� ��࠭.
{
 textmode(C80);		textattr(0x1B); clrscr();   //         ����� 梥⮢.
gotoxy(16, 3);   cout << "������ ०��:";

gotoxy(21,7);   cout << "���� ��ࠬ��஢                  - F2";
gotoxy(21,9);   cout << "��ᬮ�� ���न���               - F3";
gotoxy(21,11);   cout << "��ᬮ�� ��䨪�                 - F4";
gotoxy(21,13);   cout << "������஢���� ���न���         - F5";
gotoxy(21,15);   cout << "���࠭��� ���न���� � 䠩�      - F6";
gotoxy(21,17);   cout << "����� ���न���� �� 䠩��      - F7";

gotoxy(21,20);   cout << "�����襭�� ࠡ��� �ணࠬ��      - F12";

}
//---------------------------------------------------------------------------
void InputParameters(int &st)			// ���� ��ࠬ��஢ �㭪樨.
{
	textmode(C80);	textattr(0x1B);		clrscr();

		     Pisk(20);
   gotoxy(21, 3); cout<< "������ ��砫��� ���न���� �... ";
				gotoxy(55, 3);  X0 = getF();
		     Pisk(30);
   gotoxy(21, 5); cout<< "������ ������� ���न���� �... ";
				gotoxy(55, 5);	Xk = getF();
		     Pisk(40);
						// ���塞 ���⠨ �᫨ ��न���
      if(X0>Xk){ X0+=Xk; Xk=X0-Xk; X0-=Xk; }	// ��砫� ����� ����. ����;

 do{
   gotoxy(21, 7); clreol(); cout<< "������ 蠣... ";
				gotoxy(55, 7);	dX = getF();
 }while(dX<0 || abs(Xk-X0)/dX>MAX);     //  ����� �����, �᫨ �᫮ �������⨬�.

   gotoxy(10, 9); cout << "������ ��ࠬ����(a1,b1,a2,b2,a3,b3) �१ �������... ";
   gotoxy(15, 11); cin >> a1>>','>>b1>>','>>a2>>','>>b2>>','>>a3>>','>>b3;

 st = abs((Xk-X0)/dX)+2;			// ������⢮ ��ப � ⠡���;
}
//---------------------------------------------------------------------------
void DataCalc(Coordinate** CPrt, int st)	// ����� ������;
{
 if(!st) { No_matr(); return; }  //              ����஫� ������⢨� ������.

 textmode(C4350);	  textattr(0x1B);	clrscr();   // ����� 梥⮢.

 float x=X0;					// ���न��� ��砫�;
 for(int i=0; i<st; i++)
  {
   CPrt[i]->getC(X)=x;					    // ���祭�� x;
   CPrt[i]->getC(Y)=a1*sin(b1*x)+a2*sin(b2*x)+a3*sin(b3*x); // ���祭�� f(x);
   x += dX;						    // ���饥���;
  }
}
//-------------------------------------------------------------------------
void ViewTable(Coordinate** CPrt, int st)	// ���⬮���� ⠡����;
{
 if(!st) { No_matr(); return; }  	 // ����஫� ������⢨� ⠡����;

 int n=0;					// ����� ���孥� ��ப�;
 char ch=0;

 for(;;)				// ���� 横� ��ࠡ�⪨ ������;
 {
  switch(ch)
  {
   case 0 : Display(CPrt,st,n); ch=42;	continue;
   case 42: ch = getch();		continue;
   case 72: ch=0; if(n)n--;		continue;
   case 80: ch=0; if(n<st-20)n++;	continue;
   case 13: clrscr();			return;
   case 27: clrscr();			return;
   default: Sound(4,150); ch =  0;	continue;
  }
 }

}
//-------------------------------------------------------------------------
void HeaderTable()
{
   textmode(C80); textattr(0x0A);	clrscr();
						// ����� ⠡����;
   gotoxy(25,2); cout << " Step        X               Y       ";
   gotoxy(25,3); cout << "-----T---------------T---------------";
}
//-------------------------------------------------------------------------
void Display(Coordinate** CPrt, int st, int n)	//
{
   HeaderTable();					// ����� ⠡����;
					// ���� �뢮�� ⠡���� � ���᮫�;
   for (int i = n; (i<n+20) && i<st && i>-1;i++)
   {
    gotoxy(25,4+i-n); cout << '|'<< setw(4) << i<< "|";
    cout << setw(15) << CPrt[i]->getC(X) << "|";
    cout << setw(14) << CPrt[i]->getC(Y) << "|";
   }
}
//--------------------------------------------------------------------------
void Graphik(Coordinate** CPrt, int st)	 // �뢮� ��䨪� �㭪樨 � ���᮫�;
{
 if(!st) { No_matr(); return; }		      // ����஫� ������⢨� ⠡����

  textmode(C4350); textattr(0xf0);	clrscr();

 CSort(CPrt,st);		// ������㥬 �� x ��। �뢮��� ��䨪�;
//			*** ������祭�� ��䨪� ***
 int gdriver = DETECT;
  int gmode;
  int errorcode;
  initgraph(&gdriver, &gmode, PATHTODRIVER);
  errorcode = graphresult();
  if (errorcode != grOk)
  {
   printf("ERROR!");
   exit(1);
  }

  int i;				// ������ ������� � ���ᨢ�
  int x,y;				// ���न���� �� ��䨪�;
  int scaleX = (570/abs(Xk-X0));        // �����樥� �� x
		// ���ᮢ�� ���न����� �ᥩ
  setcolor(0);
  lineto(20,225);
  setcolor(7);
  lineto(605,225);
  setcolor(0);
  lineto(600,220);
   setcolor(7);
  lineto(610,225);
   lineto(600,230);

  setcolor(0);
  lineto((30-(CPrt[0]->getC(X)*scaleX)),450);

  setcolor(7);
  lineto((30-(CPrt[0]->getC(X)*scaleX)),35);

  setcolor(0);
  lineto((25-(CPrt[0]->getC(X)*scaleX)),40);

  setcolor(7);
  lineto((30-(CPrt[0]->getC(X)*scaleX)),30);
  lineto((35-(CPrt[0]->getC(X)*scaleX)),40);

    setcolor(0);
    lineto((30),225-(CPrt[0]->getC(Y)*scaleX));

   for (i = 0; i<st; i++)		// ���� ���ᮢ�� ��䨪�;
   {
    x=CPrt[i]->getC(X)*scaleX;
    y=225-(CPrt[i]->getC(Y)*scaleX);
    setcolor(10);
    lineto(x+30-(CPrt[0]->getC(X)*scaleX),y);
   }

getch();
closegraph();
}
//-------------------------------------------------------------------------
void Edit(Coordinate** CPrt, int st)
{
 if(!st) { No_matr(); return; }  //              ����஫� ������⢨� ������.

  textmode(C80); textattr(0x0A);	clrscr();

  int n=0;
  unsigned int id=0;
  flag f=X;
  char ch=0;
 for(;;)
 {
  switch(ch)
  {
   case  0: Display(CPrt,st,id,n,f); ch=42;	continue;
   case 42: ch = getch();			continue;
   case 72: ch=0; if(!id){ if(n)n--; }
		  else id--;    		continue;
   case 80: ch=0; if(id==19){if(n<st-20)n++;}
		  else id++;    		continue;
   case 75: if(f||!(n+id)){  f=X; ch=0; }
	    else { ch=72; f=Y; }		continue;
   case 77: if(!f||n+id==st-1){ f=Y; ch=0; }
	    else { ch=80; f=X; }		continue;
   case  9: ch=77;				continue;
   case  8: ch=0; EditEl(CPrt,id,n,f);		continue;
   case 13: clrscr();				return;
   case 27: clrscr();				return;
   default: Sound(4,150); ch = 0;		continue;
  }
 }
}
//-------------------------------------------------------------------------
void Display(Coordinate** CPrt, int st, int id,int n, flag f) // �뢮� ���
							// ।���஢���;
{
   HeaderTable();					// ����� ⠡����;

   for (int i = n; (i<n+20) && i<st && i>-1;i++)  // ���� �뢮�� ⠡����;
   {
    gotoxy(25,4+i-n); cout << '|'<< setw(4) << i<< "|";
    if(i==id+n && !f) textcolor(4);
    clreol(); cout << setw(15) << CPrt[i]->getC(X);
    textcolor(10); clreol(); cout << "|";
    if(i==id+n && f) textcolor(4);
    clreol(); cout << setw(15) << CPrt[i]->getC(Y);
    textcolor(10); clreol(); cout << "|";
   }
   gotoxy(45+f*16,4+id);
}
//-------------------------------------------------------------------------
void EditEl(Coordinate** CPrt,int id,int n, flag f) // ।���஢��� ��������;
{

 char s[20];                            // ���ୠ� ��ப�
 for(int i=0; i<20; i++)
  s[i]='\0';

 i = 0;					// ����塞 ������ ���ᨢ�;
 char ch;                               // ��� ������

 do{					// �뢮� ⥪��� ���祭��;
  gotoxy(32+f*15,4+id); textcolor(11); clreol(); cout << setw(13+f) << s;
			 textcolor(10); clreol(); cout << " |";
			 if(!f) cout << setw(15) << CPrt[id+n]->getC(Y) << "|";

  gotoxy(45+f*16,4+id);			// ������ ���⪨ �뤥������� ��-��;
  ch=getch();

  if(!i)				// �᫨ �� �㫥��� ������� ���ᨢ�
   if(ch==45)				// �஢��塞 ����;
    s[i++]=45;                          // �᫨ ����� '-'
   else s[i++]=43;			// ���� '+' �� 㬮�砭��;

  if((ch>47 && ch<58) || ch==46)	// �᫨ ������ ����
   s[i++]=ch;				// ������塞 �� � ���ᨢ;
  else
   if(ch==8 && i>0)			// �᫨ ������ backspase
   {
    s[--i]='\0';			// ���ࠥ� �।��饥 ���祭��;
   }

 }while(ch!=13 && ch!=27 && i!=20);	// ��室 �� ������ Exc ��� Enter;
 if(ch==13) { CPrt[id+n]->getC(f)=CIF(s); }	// �᫨ Enter - ��࠭塞;

}
