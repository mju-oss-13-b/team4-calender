/*
 <CALENDER-Tool To Perform Calender Related Functions.>
    Copyright (C) <2011>  <SHIVAM MATHUR--shivam_jpr@hotmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

	Note that the username is- 	shivam
	and the password is- 		cool
	can be changed but it must be notified with the distribution and scapping the password feature would mean copyright infringement
*/
/*
FUNC.CPP is a part of CALENDER.
contain all the user defined functions
*/
#include <iostream.h>								//For all the stream input-output operations
#include <string.h>									//For all the string related functions
#include <stdio.h>									//For all the standard input/output functions
#include <windows.h>								//For all the functions required to access WINDOWS API
#include <ctype.h>
#include <stdlib.h>
#include "header files\md5.h"	//For password protection to create hash of username and password

/**********************************************************GLOBAL IDENTIFIERS********************************************************************/
int  a, i=0, j, m, q, s, u, w, x, y, z, ri, bt, kl, yeno = 0, cenno = 0, date = 0, dinno = 0, ch = 0, mon = 0, year = 0,  daynum = 0, again = 0, 
	 achk, bchk, counter = 1, wrap = 0, startDOW =0, weekNumber = 0, dayCounter = 1, loopCount = 0, ket, met, ret, flag, acc, lim, strno, fla=0,
	 month		[12] = {6, 1, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 },  
	 daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	
char uchk[10],pchk[10],bul=16,ch1,day[10],usrn[10],pass[10],pchoice,bi,monstr[15],str[15],strcase,
	 week	[ 7][10] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"},
	 months [12][10] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
/************************************************************************************************************************************************/

/********************************************************USER DEFINED FUNCTIONS*********************************************************/


CONSOLE_SCREEN_BUFFER_INFO csbi;						//Function to go to any point of the console screen(Taken from CONIO library)
void gotoxy ( short x, short y )
{  COORD coord = {x, y};
   SetConsoleCursorPosition ( GetStdHandle ( STD_OUTPUT_HANDLE ), coord ); //SetConsoleCursorPosition--A COORD structure that contains the column and row coordinates of the cursor in the console screen buffer.
}

COORD getxy (  CONSOLE_SCREEN_BUFFER_INFO * csbi)		//Function to get the position of the cursor the screen
{
	
	COORD coord = csbi->dwCursorPosition;
	return coord;
}

/***************************************************************************************************************************************/

void setscr()											//Function to set the size of the console screen
{
	HANDLE hOut;
    CONSOLE_SCREEN_BUFFER_INFO SBInfo;
    SMALL_RECT DisplayArea = {0, 0, 0, 0}; //Structure in windows library--Defines the coordinates of the upper left and lower right corners of a rectangle.
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hOut,&SBInfo);
    SBInfo.srWindow.Right;
    SBInfo.srWindow.Bottom;
    DisplayArea.Right = ri;
	DisplayArea.Bottom = bt;
    SetConsoleWindowInfo(hOut,TRUE,&DisplayArea);
}

/***************************************************************************************************************************************/
char GetCh()											//Function to accept a character from the keyboard(Taken from CONIO library)
{
	HANDLE hStdin = GetStdHandle (STD_INPUT_HANDLE);
	INPUT_RECORD irInputRecord;
	DWORD dwEventsRead;
	char cChar;

  while(ReadConsoleInputA (hStdin, &irInputRecord, 1, &dwEventsRead)) // Read key press 
    if	(
		irInputRecord.EventType == KEY_EVENT
		&&irInputRecord.Event.KeyEvent.wVirtualKeyCode != VK_SHIFT
		&&irInputRecord.Event.KeyEvent.wVirtualKeyCode != VK_MENU
		&&irInputRecord.Event.KeyEvent.wVirtualKeyCode != VK_CONTROL
		)
			{
				cChar = irInputRecord.Event.KeyEvent.uChar.AsciiChar;
				ReadConsoleInputA (hStdin, &irInputRecord , 1, &dwEventsRead);   //Read key release 
				return cChar;
			}
	return EOF;
}

/***************************************************************************************************************************************/
int digesMD5()											//Function for password protection
{
	MD5 md5 ;
	COORD coord;
   //----------------------------Local Identifiers for digesMD5()----------------------//
		int  v=33;
		char str3[33] = "3ae9d8799d1bb5e201e5704293bb54ef";	//--hash of username(shivam)--
		char str4[33] = "b1f4f9a523e36fd969f4573e25af4540";	//--hash of password(cool)--
		char c[5], getusrn2str [33], getpass2str [33];
   //---------------------------------------------------------------------------------//
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);	//Function to change the colour of output handle in the console		
	gotoxy(28,8);		cout<<"___________________";
	gotoxy(28,16);		cout<<"___________________";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gotoxy(34,8);		cout<<"WELCOME";
	gotoxy(28,10);		cout<<"Enter the username\n";
	gotoxy(28,11);		cin>>usrn;	
	char* str1   = md5.digestString(usrn);
	strcpy(getusrn2str, str1);  									//converting char* to char[]
	gotoxy(28,13);		cout<<"Enter the password\n";
	i=0;
	gotoxy(28,14);
	while(i!=13)													//Loop until 'Enter' is pressed
		{
			enter:
			c [i]= GetCh();
			if(c[i]==13)
				{
    				break;
				}
			if(c[i]!=13 && c[i]!=0 && c[i]!=9 && c[i]!=27 && c[i]!=32 && c[i]!=18 && c[i]!=-32 )	//condition to prevent the special character to be inputted into password
				{
					if (c[i]==8)																	//Condition to erase password if backspace is pressed
						{
							GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
							coord = getxy( &csbi);
							kl= coord.X-1;
							gotoxy(kl,coord.Y);
							putchar('\0')   ;i--;													//putting a null character
							GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
							coord = getxy( &csbi);
		
							if(coord.X<29)
								gotoxy(29,14) ;
	
							GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
							coord = getxy( &csbi);
							kl= coord.X-1;
							gotoxy(kl,coord.Y);
							goto enter;																//After erasing sending the control to input handle again
						}
					else
						{
							putchar('*');															//Masking an '*' over the password characters
							bi=EOF; z=bi+5;															//setting z =4(I was too lazy to type 4)
							if (i<z)
								pchk[i]=c[i];
							GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
							coord = getxy( &csbi);
							i=coord.X-28;
						}
				}
		}
	cout<<"\n";
	char* str2  = md5.digestString(pchk);
	strcpy(getpass2str,str2);						 //converting char* to char[]
	while(v-->0)
		{
			if(getpass2str[v]==str4[v] && getusrn2str[v]==str3[v])
      			acc=0;
			else if(getpass2str[v]!=str4[v] || getusrn2str[v]!=str3[v])
      			{
      				acc=1;
      				break;
      			}
		}
      if(acc==1)
      	return 1;
      else
      	return 5;									//returning something !=1
}

/***************************************************************************************************************************************/
int dayno()										/*
													Function to give the dayno of any date 
													For eg if day is Sunday on a date, dayno is '0'
												*/
{

if (year%4 == 0 && (year %100 != 0 || year%400 == 0))//Updation of the array containing no of days in a month, if leap year is detected
{
   daysInMonth[1] = 29;
   month[0]		  = 5;
   month[1]       = 1;
}
	x=year%100;	y=x/4;	z=x+y;	yeno=z%7;

	if		(year>=1700&&year<1800)		cenno=5;
	else if	(year>=1800&&year<1900)		cenno=3;									
	else if	(year>=1900&&year<2000)		cenno=1;
	else if	(year>=2000&&year<2100)		cenno=0;
	else if	(year>=2100&&year<2200)		cenno=5;
	else if	(year>=2200&&year<2300)		cenno=3;
	dinno =	(((cenno+yeno+month[mon-1])%7)+date)%7;
	return dinno;
}
/***************************************************************************************************************************************/

int chkstr()						/*
									function to read day name or month name from the user 
									and assign a number to it for identification
									*/
{
	fla=0;
	if(isdigit(str[0])==0)							
	{
		for(i=0;i<=lim;i++)
		{
			if(isupper(str[i]))
			str[i] = tolower(str[i]);
		}
		if(isupper(str[0])==0)			
			str[0]-=32;								//making the string title case
	}
	for(i=0;i<=lim;i++)								//loop to recognise a string and assign a number to it													
		{	
			fla = 0;
			if(strcase == 'm')
				ret=strncmp(str,months[i],3);																		
			else if(strcase == 'd')
				ret=strncmp(str,week[i],3);
			if(ret == 0)
				{
					if(strcase == 'm')
					{
						strno = i+1;				//storing the string code
						break;
					}
					else if(strcase == 'd')
					{
						strno = i; 
						break;
					}
				}
			else fla = 2;
		}
	return strno;
	return fla;
}

/***************************************************************************************************************************************/
int chkdate()											/*
														Function to check if the date entered by the user is correct
														and also check if the date is of the past or a future date 
														or it is today's date
														(works on system date)(uses SYSTEMTIME class in WINDOWS.H)
														*/

{
	again=0;
    if (year%4 == 0 && (year %100 != 0 || year%400 == 0))				//Updation of the array containing no of days in a month, if leap year is detected
	daysInMonth[1]=29;
	
	if(date>daysInMonth[mon-1] || date <1 )								//checking if the date is not correct
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
		gotoxy(27, 4);	cout<<"Wrong date entered--WAIT";
		again=1 ;
		for(w=0;w<500000000;w++){};
	}
	else if(fla==2)														//checking if the month is not correct
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
		gotoxy(26, 4);	cout<<"Enter month correctly--WAIT";
		again=1 ;
		for(w=0;w<500000000;w++){};
	}
	else if(year<1700 || year>2300)										//checking if the year is not between (1700-2300)
	{ 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);	
		gotoxy(24, 4);	cout<<"Enter year from 1700-2300--WAIT";
		for(w=0;w<600000000;w++){};
		again=1	;
	}
	
	SYSTEMTIME ChkDate;
    GetSystemTime(&ChkDate);
	if(ChkDate.wYear > year)											//Checking if the date is of the past or a future date 
		flag = 0;														//or it is Today's date	
	else if(ChkDate.wYear < year)
		flag = 1;
	else if(ChkDate.wYear == year)
	{
		if(ChkDate.wMonth > mon)
			flag = 0;
		else if(ChkDate.wMonth < mon)
			flag = 1;
		else if(ChkDate.wMonth == mon)
		{
			if(ChkDate.wDay > date)
				flag = 0;
			else if(ChkDate.wDay < date)
				flag = 1;
			else if(ChkDate.wDay == date)	
				flag = 2;
		}
	}
	return again;
	return flag;
}

/***************************************************************************************************************************************/
void setpos()								//Function to give a horizontal tab while printing tabular calender
	{
		if(s<3)								//This if-else construct checks for the month and sets the alignment
		gotoxy(28*s+q,w+2);					
		else if (s>=3 && s<6)
		gotoxy(28*(s-3)+q,13+w);
		else if (s>=6 && s<9)
		gotoxy(28*(s-6)+q,24+w);
		else if (s>=9 && s<12)
		gotoxy(28*(s-9)+q,35+w);
	}

/***************************************************************************************************************************************/
void newline()								//Function for nextline ("\n") while printint tabular calender		
	{	
		if(s<3)								//This if-else construct checks for the month and prints the newline  
		gotoxy(28*s+1,u);					//and redirects the cursor to set proper alignment
		else if (s>=3 && s<6)
		gotoxy(28*(s-3)+1,u);
		else if (s>=6 && s<9)
		gotoxy(28*(s-6)+1,u);
		else if (s>=9 && s<12)
		gotoxy(28*(s-9)+1,u);
	}

/***************************************************************************************************************************************/
void printAll()								//Function to print the calender of year
{
	ri=77;		bt=50;		setscr();
	COORD coord;
  	if(ch==3)
	{
		for(m=0;m<5;m++)					//Loop of print lines to give a Tubular look
			{
				gotoxy(0,m*11);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
				cout<<"_______________________________________________________________________________";
			}
	}
	date=1;		mon=counter;	startDOW = dayno() ;	wrap = startDOW;		s=counter-1;
	q=0;		w=0;	     	setpos();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
	cout << "---------------------";
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	coord = getxy( &csbi);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	gotoxy(coord.X-17,coord.Y);cout <<months[counter-1]<<" "<<year;
 	q=0;		w=1;			setpos();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	cout << "  S  M  T  W  T  F  S" ;		//printing the days
 	q=0;		w=2;			setpos();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
	cout << "---------------------";
    for (loopCount = 0; loopCount < startDOW; loopCount++)
 	{
 		if(loopCount==0)
			{
				q=3;	w=3;	setpos();
			}
		else
				cout << "   ";				// how many space to indent new month
 	}
	cout<<" ";
 	for (dayCounter=1;dayCounter<=daysInMonth[counter-1]; dayCounter++)
 	{	
	
		if (wrap == 7)						//if Saturday, next line
 			 {
 			 GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
			 coord = getxy( &csbi);
			 u=coord.Y+1;
			 newline();
			 wrap = 0;						//resets day of week counter
 			 weekNumber++;												
 			 }
	 	if(wrap==0) 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);	 
		date=1;		mon=counter;	 startDOW = dayno() ;					   
		 if (dayCounter<10 && startDOW!=0)	//adds space for single digit days
			 cout <<" "<< dayCounter << " ";	
		 else if (dayCounter<10 && startDOW==0)
		 {	  
			 if (dayCounter==1) 
				{
					GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
					coord = getxy( &csbi);
					u=coord.Y+1;
					newline();
				}
			 cout <<" "<< dayCounter << " ";		//printing the dates
		 }	
		 else
			 cout << dayCounter << " ";				//printing the dates
			 wrap++;
 	}
		 GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
		 coord = getxy( &csbi);
		 gotoxy(coord.X,coord.Y+4);
}

/***************************************************************************************************************************************/
void monthcal()								//function to print the calender of a month
{
	COORD coord;
  	date=1;		mon=counter; 	startDOW = dayno() ;	wrap = startDOW;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
	cout<<"\n\n";
	cout << "---------------------\n";
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	coord = getxy( &csbi);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	gotoxy(4,coord.Y-1);cout <<months[counter-1]<<" "<<year;
  	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	cout << "\n  S  M  T  W  T  F  S" << endl;				//printing the days
 	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
	cout << "---------------------" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	for (loopCount = 0; loopCount < startDOW; loopCount++)
 	{
 		cout << "   ";						// how many space to indent new month
 	}
		cout<<" ";
 	for (dayCounter=1;dayCounter<=daysInMonth[counter-1]; dayCounter++)
 	{
		 if (wrap == 7)						//if Saturday, next line
 			 {
 			 cout << "\n ";
 			 wrap = 0;						//resets day of week counter
 			 weekNumber++;											
 			 }
		 if(wrap==0) 
		 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		 else
		 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
 		 if (dayCounter<10)					//adds space for single digit days
 			 cout << " ";
 			 cout << dayCounter << " ";		//prints the date
			 wrap++;
 	}
 					cout << "\n\n";
}

/***************************************************************************************************************************************/
void day2date ()							//Function to print date to the given day in a month
{
	COORD coord;
	if(isdigit(day[0])==0) 
	{	
		strcpy(str,day);	lim=7;		strcase='d';	chkstr(); daynum=strno;
	}
	else 
		daynum=atoi(day);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
	gotoxy(28, 6);   	cout<<"_____________________";
	gotoxy(28,17);   	cout<<"_____________________\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	gotoxy(30, 6);		cout<<week[daynum]<<" lies on";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	gotoxy(28, 6);
	for(j=1;j<=daysInMonth[mon-1];j++)																		//loop to check for each day
		{
			date=j;
			wrap=dayno();
			if(daynum==wrap)
			if(j<10)
			  	{
					GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
					coord = getxy( &csbi);
					gotoxy(28,(coord.Y+2));	cout<<bul<<"\t"<<"0"<<j<<" "<<months[mon-1]<<" "<<year;			//printing the dates < 10
				}
			else
         		{
					GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
					coord = getxy( &csbi);
					gotoxy(28,(coord.Y+2));	cout<<bul<<"\t"<<j<<" "<<months[mon-1]<<" "<<year;				//printing dates > 10
				}
		}
}
	
/***************************************************************************************************************************************/
char repeat()																//Function to repeat the program
{
      if (ch>4)
         {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
			gotoxy( 40,8); cout<<"\t!!!WRONG CHOICE!!!\n";
         }
      if(ch>4)
		  gotoxy( 0,24);
	  else if(ch==3)
   	      gotoxy(0,47);
	  else
		  gotoxy( 0,22);
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
      cout<<"   Do you want to Run the program again (y/n)\t";				//Asking the user if he wants to repeat the program			
      
	  if(ch==3)																//This if-else construct just aligns the cursor 
		{gotoxy(48,47); 	cin>>ch1; }
      else if (ch==2)
		{gotoxy(48,22); 	cin>>ch1; }
      else if (ch> 4)
		{gotoxy(48,24); 	cin>>ch1; }
      else
		{gotoxy(48, 22);	cin>>ch1; }
      return ch1;
}
/***************************************************************************************************************************************/
/*************************************************************END OF FILE***************************************************************/