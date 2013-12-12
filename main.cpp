/*
<CALENDAR-Tool To Perform Calendar Related Functions.>
    Copyright (C) <2011-12>  <SHIVAM MATHUR--shivam_jpr@hotmail.com>

    This program is free software: you can redistribute it and/or modify
    the software until it is not mentioned in the source,
    under the terms of the GNU Affero General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.


*The terms and conditions given below or in the licence.txt(https://sourceforge.net/projects/c-cpp-calender/files/licence.txt) follow to every part of the program until and unless explictly mentioned
 these terms and conditons might change without your prior information and in any case the licence terms as
 mentioned in the latest version of -(https://sourceforge.net/projects/c-cpp-calender/files/licence.txt)
 would be valid and applicable.
*The redistributors are expected to use the screenshots provided with the APP than rather than creating their own.
*The icon of Calendar must not be changed and in any case the icon provided with the APP must be used.

****___NOTE_____**** :- to compile add "-lshlwapi" when calling the linker.

The following program perform the functions for which a calendar is used
MADE BY SHIVAM MATHUR
:)
*/

//Contains all the User-Defined functions accessed in the program
#include"func.h"
#include "extern.h"
#pragma comment(lib, "Shlwapi.lib")

int main() 					//Main function
{
/***********************************************************Password roadblock***************************************************************/    

/*setting console screen*/	
	const string tile="CALENDAR "+ver+" - By SHIVAM";	
	SetConsoleTitleA(tile.c_str());	//DOS-function to give title to a console windowe- *takes char as parameters 								
/*......*/

	ri=79;		bt=29;				//initial dimensions of screen
	cal.setscr();					//Resetting the screen size
/*creating local calendar directory*/	
	TCHAR pthc[MAX_PATH];			//variable to store file name
	SHGetFolderPath(NULL,CSIDL_LOCAL_APPDATA|CSIDL_FLAG_CREATE,NULL, 0,pthc); /*function to find local application directory*/				
	PathAppend(pthc, TEXT("Calendar"));	//function to edit stored path
	CreateDirectory(pthc,NULL);
/*......*/	
	
/***************************************************************************************************************************************/
do
{

  	cal.docls();		//Cleares the screen
	ri=79;	bt=29;		//sizes for console screen
	cal.setscr();		//resizing the console screen

/********************************************************CREDITS************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////			This code (from 2 above lines to 20 lines under this line) must be there with every distribution					   //
///				Removing this part to the code is not allowed in any case,the doing so would directly mean without 			  	      ///
//				any argument the violation of the free license provided and a case of copyright infringement.						 ////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*setting up options menu*/
	
	cal.setclr(7);	
	cal.gotoxy( 0,15); 	cout<<"CREDITS\n";
	cal.setclr(8);
	cal.gotoxy( 5,17); 	cout<<" 888888888888                                                 ,adSba,   \n";
	cal.gotoxy( 5,18); 	cout<<"      88                                                     SS    SS   \n";
	cal.gotoxy( 5,19);  cout<<"      88                                                    SS     SS   \n";
	cal.gotoxy( 5,20); 	cout<<"      88      ,adSSSba,    adSSSba,  8 ,dSSba,,adSSba,     SS      SS   \n";
	cal.gotoxy( 5,21); 	cout<<"      88      SSS    SS         `SS  88S     88     SSa   SS       SS   \n";
	cal.gotoxy( 5,22);	cout<<"      88      SSSSSSSSS  ,adSSSSSSS  88      88      88  SSSSSSSSSSSSSS \n";
	cal.gotoxy( 5,23); 	cout<<"      88      SS         SS      SS  88      88      88            SS   \n";
	cal.gotoxy( 5,24); 	cout<<"      88      'aSSSSSa'  `aSSSSSSSS  88      88      88            SS   \n";
	cal.gotoxy( 0, 0);
	
/***************************************************************************************************************************************/
	

	cal.setclr(12);	
	cal.gotoxy( 0,14);		cout<<"________________________________________________________________________________";
	cal.gotoxy( 0, 0);		cout<<"________________________________________________________________________________";	//welcome
	cal.gotoxy( 0,25);		cout<<"________________________________________________________________________________";
	cal.setclr(15);	
	cal.gotoxy(73-strlen(usrn)-4,12);		cout<<"Welcome "<<usrn;
	cal.gotoxy(28, 0);		cout<<"캘린더에 오신 것을 환영합니다.";	
	cal.gotoxy(70, 0);		cout<<"VER "<< ver;
	cout<<"\n\n";
	cal.setclr(7);	
	cout<<"OPTIONS";
	cal.gotoxy( 0, 3);
	cal.setclr(15);			
	cout<<"\n\t1. 요일 출력\n";					//Options of the program
	cout<<"\n\t2. 원하는 달의 달력을 출력합니다.\n";
	cout<<"\n\t3. 원하는 해의 모든 달력을 출력합니다.\n";
	cout<<"\n\t4. 해당 년도, 달의 같은 요일을 출력합니다.\n";
	cout<<"\n\t5. D-day\n";
    cal.setclr(10);	
    cal.gotoxy(65,28); cout<<"ESC : EXIT";				//Provodomg button for exit	
    cal.gotoxy(5,28); cout<<"F10 : ABOUT";				//Provodomg button for about		
	
	cal.calmenu();

/*......*/	
	
/***************************************************************************************************************************************/

	if (kvt==1)			//Prints the day
		{
			cal.logcal('d');
     		do{	
				cal.docls();
         	fla=0;
   			if(again==1)
         	{
				cal.setclr(10);	
				cal.gotoxy(29, 4);		cout<<"!!! enter again !!!";
            }
            again=0;
			cal.setclr(2);	
			cal.gotoxy(28, 7);   	cout<<"______________________";
			cal.gotoxy(28,20);   	cout<<"______________________\n";
			cal.setclr(15);	
			cal.gotoxy(34, 7);   	cout<<"요일 찾기";
			cal.gotoxy(28, 9);		cout<<"날짜 입력\n";
			cal.gotoxy(28,10);		cal.infl('d'); if (again==1) continue;
			cal.gotoxy(28,12);		cout<<"달 입력\n";
			cal.gotoxy(28,13);		cal.infl('m'); 
			cal.gotoxy(28,15);		cout<<"년도 입력\n";
			cal.gotoxy(28,16);		cal.infl('y'); if (again==1) continue;
			cal.chkdate();
			}while(again==1);
			x=cal.dayno();
			if(flag==0)
				{
					cal.gotoxy(28,18);		cout<<"이 날의 요일은 : ";
				}
			else if(flag==1)
				{
					cal.gotoxy(28,18);		cout<<"이 날의 요일은 : ";
				}
			else if(flag==2)
				{
					cal.gotoxy(28,18);		cout<<"오늘은 : ";
				}
			cal.setclr(12);	
			cout<<week[x]<<"\n";
		}
/***************************************************************************************************************************************/
	if (kvt==2)				//prints the calendar of the month
		{
			cal.logcal('m');
			do{
			cal.docls();
   			if(again==1)
         	{
				cal.setclr(10);	
         		cal.gotoxy(28, 4);	cout<<"!!! ENTER AGAIN !!!";
            }
            again=0;
			cal.setclr(2);	
			cal.gotoxy(28, 7);   	cout<<"\t____________________"; 
			cal.gotoxy(28,15);   	cout<<"____________________\n";
			cal.setclr(15);	
			cal.gotoxy(31, 7);   	cout<<"달력";
			cal.gotoxy(28, 9); 		cout<<"달 입력\n";
			cal.gotoxy(28,10); 		cal.infl('m'); 
			cal.gotoxy(28,12);		cout<<"년도 입력\n";
			cal.gotoxy(28,13);		cal.infl('y'); if (again==1) continue;
			date=1;
         	counter = mon;
		 	cal.chkdate();
			}while(again==1);
			cal.docls();
			cal.monthcal();
		}
/***************************************************************************************************************************************/
	if (kvt==3)			//prints the calendar of the year
		{
			cal.logcal('y');	
 			do{
			cal.docls();
   			if(again == 1)
  				{
					cal.setclr(10);	
         			cal.gotoxy(33, 4);	cout<<"!!! ENTER AGAIN !!!";
				}
			again=0;
			cal.setclr(2);	
			cal.gotoxy(26, 7);   	cout<<"______________________________";
			cal.gotoxy(26,18);   	cout<<"______________________________\n";
			cal.setclr(15);	
			cal.gotoxy(35, 7);   	cout<<"해당 년도 전체 달력";
			cal.gotoxy(26, 9);		cout<<"년도 입력\n";
			cal.gotoxy(26,10);		cal.infl('y'); if (again==1) continue;
			
			date=1;			mon=1;
			cal.chkdate();
			}while(again==1);
      		cal.docls();
							
				for (counter = 1; counter <= 12; counter++)
 				{
					cal.printAll();
				if (!strncmp(fl,"y",1) || !strncmp(fl,"Y",1))					
					cal.printcaltofile();
 				}		
			
		}
/***************************************************************************************************************************************/
	if (kvt==4)			//prints the dates on which a day lies in a month
		{
			cal.logcal('t');
			do{
			cal.docls();
   			if(again == 1)
         		{
					cal.setclr(10);	
         			cal.gotoxy(29, 4);	cout<<"!!! ENTER AGAIN !!!";
				}
			again=0;
			strno='\0';
			fla=0;
			cal.setclr(2);	
			cal.gotoxy(28, 7);   	cout<<"________________________";
			cal.gotoxy(28,18);   	cout<<"________________________\n";
			cal.setclr(15);	
			cal.gotoxy(35, 7);   	cout<<"해당 년도, 달의 요일 날짜찾기";
			cal.gotoxy(28, 9);		cout<<"요일 입력\n";
			cal.gotoxy(28,10);		cal.infl('f'); if (again==1) continue;
			cal.gotoxy(28,12); 		cout<<"달 입력\n";
			cal.gotoxy(28,13);		cal.infl('m');
			cal.gotoxy(28,15);		cout<<"년도 입력\n";
			cal.gotoxy(28,16);		cal.infl('y'); if (again==1) continue;
			cout<<"\n";			cout<<"\n";
			date=1;
			cal.chkdate();
			}while(again==1);
			cal.docls();
			if(daynum==7)		daynum=0;
			cal.day2date();
		}
/***************************************************************************************************************************************/
	if(kvt ==5)//D day 기능
	{

		int Dtotal = 0;//d데이까지의 전체 일 수 
		int Ttotal = 0;//오늘까지의 전체 일 수 

		int Dyear;// 입력받은 디데이 년도
		int Dmonth;//입력받은 디데이 월
		int Dday;//입력받은 디데이 날짜

		SYSTEMTIME ChkDate;//시스템 타임 변수

		GetLocalTime(&ChkDate);// ChkDate에 현재 날짜와 시간을 입력하는 함수

		cal.docls();// 창 청소

		cal.setclr(15);	
		cal.gotoxy(30, 7);   	cout<<"\tD-day";

		cal.gotoxy(28, 9);		cout<<"년도 입력\n";
		cal.gotoxy(28,10);		cin >> Dyear;
		cal.gotoxy(28,12);      cout<<"달 입력\n";
		cal.gotoxy(28,13);		cin >> Dmonth;
		cal.gotoxy(28,15);		cout<<"날짜 입력\n";
		cal.gotoxy(28,16);		cin >> Dday;
		
		//Dtotal계산
		if ( Dyear - 2013 > 0 ) {
			for ( int z = 0; z < Dyear - 2013; z++ ) {
				Dtotal += 365;
			}
		}
		for ( int z = 1 ; z < Dmonth ; z++ ) {
			Dtotal += daysInMonth[z];
		}

		Dtotal += Dday;

		//Ttotal 계산
		if ( ChkDate.wYear - 2013 > 0 ) {
			for ( int z = 0; z < ChkDate.wYear - 2013; z++ ) {
				Ttotal += 365;
			}
		}
		for ( int z = 1 ; z < ChkDate.wMonth ; z++ ) {
			Ttotal += daysInMonth[z];
		}

		Ttotal += ChkDate.wDay;

		//Dtotal - Ttotal = 남은 일자
		Dtotal -= Ttotal;

		cal.gotoxy(28,20);		cout << "기념일 까지 " << Dtotal << "일 남았습니다.\n" << endl;

	}
/***************************************************************************************************************************************/

		cal.repeat(kvt);

}while(ch1=='y');	
    
return 0;						//end of main statement

}
//end of code
//made by shivam mathur
