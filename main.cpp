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
The following program perform the function for which a calender is used
MADE BY SHIVAM MATHUR
:)
	Note that the username is- 	shivam
	and the password is- 		cool
	can be changed but it must be notified with the distribution and scapping the password feature would mean copyright infringement
*/
#include "func.cpp"                     						//Contains all the User-Defined functions accessed in the program
void main()				//using void to cut the crap													//Main function
{

roadblock:														//Password roadblock

	a = digesMD5();												//returns 1 if password or username do not match
	if (a==1)
    {
   	gotoxy(20,18);		cout<<"The PASSWORD or USERNAME is not correct\n\n\n";
   	gotoxy(20,19);		cout<<"\t1. Press 'y' to enter again\n";
   	gotoxy(20,20);		cout<<"\t2. Press any other key to exit\n";
    gotoxy(20,21);		cin>>pchoice;
	  {
      	if  (pchoice=='y' || pchoice=='Y')
			goto roadblock;
		else
     		gotoxy(20,22); cout<<"You chose to exit";
			gotoxy(20,23); cout<<"Good BYE\n";
			cout<<"\nPress any key to end";
      		GetCh();
      		exit(0);
	  }
    }

start:
  	system("cls");								//Cleares the screen (defined in--Windows.h--It is Standard function in DOS)
	ri=79;		bt=27;
	setscr();
/********************************************************CREDITS************************************************************************/
	////////////////////////This code (from above line to 16 lines under this line) must be there with every distribution////////////////////////////////////////
	///////////////Removing this part to the code is not allowed in any case,the doing so would directly mean without any argument-//
	///////////////the violation of the free license provided and a case of copyright infringement.//////////////////////////////////	
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	gotoxy( 0,14); 	cout<<"CREDITS\n";
	gotoxy( 5,15); 	cout<<"           88           88                                             \n";
	gotoxy( 5,16); 	cout<<"           88           88                                             \n";
	gotoxy( 5,17);		cout<<"           88                                                          \n";
	gotoxy( 5,18); 	cout<<",adPPYba,  88,dPPYba,   88  8b       d8  ,adPPYYba,  8 ,dPYba,,adPYba, \n";
	gotoxy( 5,19); 	cout<<"SSS    sa  88P'     8a  88  `8b     d8'  aa     `Y8  88P'    88     8as\n";
	gotoxy( 5,20); 	cout<<"   S8ba    88       88  88   `8b   d8'   ,adPPPPP88  88      88      88\n";
	gotoxy( 5,21); 	cout<<"aa    DSD  88       88  88    `8b,d8'    88,    ,88  88      88      88\n";
	gotoxy( 5,22); 	cout<<"SaYbbdPa'  88       88  88      s8s      `s8bbdPsY8  88      88      88\n";
	gotoxy( 0, 0);
/***************************************************************************************************************************************/
	

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	gotoxy( 0, 0);		cout<<"________________________________________________________________________________\n";				//welcome
	gotoxy( 0,10);		cout<<"________________________________________________________________________________\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	gotoxy(28, 0);		cout<<"Welcome to the Calender";
	cout<<"\n\n";
	gotoxy( 0, 3);
	cout<<"\t1. Enter 1 to print day of any date\n";							//options of the program
	cout<<"\t2. Enter 2 to print calender of any month\n";
	cout<<"\t3. Enter 3 to print calender of any year\n";
	cout<<"\t4. Enter 4 to find the dates in a month on which a day occurs\n\n\t";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
	gotoxy( 8, 8); cout <<"Enter your choice:\t";	cin>>ch;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
/***************************************************************************************************************************************/
	if (ch==1)															//Prints the day
	  begi1:	{
     		system("cls");
         fla=0;
   			if(again==1)
         	{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
            gotoxy(30, 4);	cout<<"!!! ENTER AGAIN !!!";
            }
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
			gotoxy(28, 7);   	cout<<"______________________";
			gotoxy(28,20);   	cout<<"______________________\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
			gotoxy(34, 7);   	cout<<"DAY-FINDER";
			gotoxy(28, 9);		cout<<"Enter the date(DD)\n";
			gotoxy(28,10);		cin>>date;
			gotoxy(28,12);		cout<<"Enter the month\n";
			gotoxy(28,13);		cin>>monstr; if(isdigit(monstr[0])==0) {strcpy(str,monstr); lim=12;	strcase='m';	chkstr(); mon=strno;} else mon=atoi(monstr);
			gotoxy(28,15);		cout<<"Enter the year(YYYY)\n";
			gotoxy(28,16);		cin>>year;
         chkdate();
			if(again==1)
				goto begi1;
			x=dayno();
			if(flag==0)
				{
					gotoxy(28,18);		cout<<"The day was : ";
				}
			else if(flag==1)
				{
					gotoxy(28,18);		cout<<"The day will be : ";
				}
			 else if(flag==2)
				{
					gotoxy(28,18);		cout<<"Today is a : ";
				}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
			cout<<week[x]<<"\n";
		}
/***************************************************************************************************************************************/
	if (ch==2)															//prints the calender of the month
		{
begi2:
			system("cls");
   			if(again==1)
         	{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
         		gotoxy(28, 4);	cout<<"!!! ENTER AGAIN !!!";
            }
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
			gotoxy(28, 7);   	cout<<"____________________";
			gotoxy(28,15);   	cout<<"____________________\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
			gotoxy(31, 7);   	cout<<"MONTH-CALENDER";
			gotoxy(28, 9); 	cout<<"Enter the month\n";
			gotoxy(28,10); 	cin>>monstr; if(isdigit(monstr[0])==0) {strcpy(str,monstr); lim=12;	strcase='m';	chkstr(); mon=strno;} else {mon=atoi(monstr);fla = 0;}
			counter = mon;
			gotoxy(28,12);		cout<<"Enter the year{YYYY}\n";
			gotoxy(28,13);		cin>>year;
			date=1;
         chkdate();
			if(again == 1)
				goto begi2;
			system("cls");
			monthcal();
		}
/***************************************************************************************************************************************/
	if (ch==3)															//prints the calender of the year
		{
begi3:
			system("cls");
   			if(again == 1)
  	{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
         		gotoxy(29, 4);	cout<<"!!! ENTER AGAIN !!!";
            }
			again=0;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
			gotoxy(28, 7);   	cout<<"_____________________";
			gotoxy(28,13);   	cout<<"_____________________\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
			gotoxy(31, 7);   	cout<<"ANNUAL-CALENDER";
			gotoxy(28, 9);		cout<<"Enter the year(YYYY)\n";
			gotoxy(28,11);		cin>>year;
			date=1;
			mon=1;
			chkdate();
			if(again==1)
				goto begi3;
      		system("cls");

			for (counter = 1; counter <= 12; counter++)
 				{
					printAll();
 				}
		}
/***************************************************************************************************************************************/
	if (ch==4)															//prints the dates on which a day lies in a month
		{
begi4:
			system("cls");
   			if(again == 1)
         	{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
         		gotoxy(29, 4);	cout<<"!!! ENTER AGAIN !!!";
            }
			again=0;
         fla=0;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
			gotoxy(28, 7);   	cout<<"________________________";
			gotoxy(28,18);   	cout<<"________________________\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
			gotoxy(35, 7);   	cout<<"DATE-FINDER";
			gotoxy(28, 9);		cout<<"Enter the day(in words)\n";
			gotoxy(28,10);		cin>>day;
			gotoxy(28,12); 	cout<<"Enter the month\n";
			gotoxy(28,13);		cin>>monstr; if(isdigit(monstr[0])==0) {strcpy(str,monstr); lim=12;	strcase='m';	chkstr(); mon=strno;}else mon=atoi(monstr);
			gotoxy(28,15);		cout<<"Enter the year\n";
			gotoxy(28,16);		cin>>year;
			cout<<"\n";			cout<<"\n";
			date=1;
			chkdate();
			if(again==1)
				goto begi4;
			system("cls");
			day2date ();
			goto rep;
		}
	else
/***************************************************************************************************************************************/
rep:
		repeat() ;
	if  (ch1=='y'||ch1=='Y')
		goto start;
}

//end of file
//made by shivam mathur