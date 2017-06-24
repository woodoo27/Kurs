#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<windows.h> 
#include <iomanip>
#include <Windows.h>
#include <string>
#include <cstdlib> 
#include <conio.h>	 //console
#include"My_Lib.h"
using namespace std;

int main()
{
	char buf[200];
	int temp;

	int  tab = 0;
	bool quit = true;
	int fullmode = 0;
	int joke = 0;
	char fileNameBook[128];
	char fileNameUser[128];
	
	FILE * inf = NULL;
	Book *bookBacklist = 0;
	User *userBacklist = 0;
	int bookAmount = 0;
	int userAmount = 0;   
	int*p_amountBook = &bookAmount;
	int*p_amountUser = &userAmount;
	int listBook = 0;
	int listUser = 0;

	UGI(tab);
	showmenuBook();
	SetConsoleCursorPosition(2, 42);
	for (; quit == true;) {

		if (_kbhit()) {
			switch (_getch()) {
			case 9: {
				SetConsoleCursorPosition(0, 45);
				tab = ButtonTab(tab);

				if (0 == tab)
					showmenuBook();
				else
					showmenuUser();

				ClearRow();
				break;
			}
			case 16: cout << "SHIFT=10";
				break;
			case '1': {
				showmenuBook();
				cout << "ONE=31";
				break;
			}
			case 27: cout << "Esc=27 ";

				ClearRow();
				break;
			case 72:// cout << "MVK_UP = 72";
				if (tab == 0) {
					 listBook -= 34;
					if (listBook>=0) {
						if (fullmode == 1) {
							for (int i = 5; i < 40; i++)
								FullClearRowPanel(i, fullmode);
							FullClearRow(41);
							ReadMyFuleBook(bookBacklist, bookAmount, listBook);
							//ReadMyFuleUser(userBacklist, userAmount, listUser);
						}
						else {
							for (int i = 5; i < 40; i++)
								FullClearRowPanel(i, fullmode);
							ReadMyFileBook(bookAmount, bookBacklist, listBook);
							ReadMyFileUser(userAmount, userBacklist, listUser);
						}
					}
					else {
						listBook=0;
					}
				}
				else {	
					listUser -= 34;
					if (listUser>=0) {
						if (fullmode == 1) {
							for (int i = 5; i < 40; i++)
								FullClearRowPanel(i, fullmode);
							FullClearRow(41);
							//ReadMyFuleBook(bookBacklist, bookAmount, listBook);
							ReadMyFuleUser(userBacklist, userAmount, listUser);
						}
						else {
							for (int i = 5; i < 40; i++)
								FullClearRowPanel(i, fullmode);
							ReadMyFileBook(bookAmount, bookBacklist, listBook);
							ReadMyFileUser(userAmount, userBacklist, listUser);
						}
						}
					else {
							listUser = 0;
						}
				}
				ClearRow();
				SetConsoleCursorPosition(2, 41);
				ClearRow();
				break;

				
			case 75: cout << "MVK_LEFT = 75";

				ClearRow();
				break;
			case 77: cout << "MVK_RIGHT = 77";

				ClearRow();
				break;
			case 80: //cout << "MVK_DOWN = 80";
				if (tab == 0) {
					 listBook += 34;
					if (listBook<bookAmount) {
						if (fullmode == 1) {
							for (int i = 5; i < 40; i++)
								FullClearRowPanel(i, fullmode);
							FullClearRow(41);
								ReadMyFuleBook(bookBacklist, bookAmount, listBook);
								//ReadMyFuleUser(userBacklist, userAmount, listUser);
							
						}
						else {
							for (int i = 5; i < 40; i++)
								FullClearRowPanel(i, fullmode);
							ReadMyFileBook(bookAmount, bookBacklist, listBook);
							ReadMyFileUser(userAmount, userBacklist, listUser);
						}
					}
					else {
						listBook = bookAmount-(bookAmount % 34) ; 
					}
				}
				else {
					listUser += 34;
					if (listUser<userAmount) {
						if (fullmode == 1) {
							for (int i = 5; i < 40; i++)
								FullClearRowPanel(i, fullmode);
							FullClearRow(41);
								ReadMyFuleUser(userBacklist, userAmount, listUser);
								//ReadMyFuleBook(bookBacklist, bookAmount, listBook);
						}
						else {
							for (int i = 5; i < 40; i++)
								FullClearRowPanel(i, fullmode);
							ReadMyFileUser(userAmount, userBacklist, listUser);
							ReadMyFileBook(bookAmount, bookBacklist, listBook);
						}
					}
					else {
						listUser = userAmount-(userAmount % 34) ;

					}
				}
				ClearRow();
				SetConsoleCursorPosition(2, 41);
				ClearRow();
				break;
			case 'b':;
			case 'B': {
				
				break;
			}
			case 'd':;
			case 'D': {
				int delrow;
				if (0 == tab) {
					ClearRow();
					SetConsoleCursorPosition(2, 41);
					cout << "Enter delete row \t\t\t\t\t\t\t " << endl;
					SetConsoleCursorPosition(2, 42);
					cin >> delrow;
					bookBacklist = DelDataBook(bookBacklist, bookAmount, delrow);
					BookClearRow();
					bookAmount--;
					FullClearRow(41);
					ReadMyFileBook(bookAmount, bookBacklist, listBook);
					SaveFileBook(fileNameBook, bookBacklist, p_amountBook);
					ClearRow();
				}
				else {
					ClearRow();
					SetConsoleCursorPosition(2, 41);
					cout << "Enter delete row \t\t\t\t\t\t\t " << endl;
					cin >> delrow;
					userBacklist = DelDataUser(userBacklist, userAmount, delrow);
					UserClearRow();
					userAmount--;
					FullClearRow(41);
					ReadMyFileUser(userAmount, userBacklist, listUser);
					SaveFileUser(fileNameUser, userBacklist, p_amountUser);
					ClearRow();
				}
				break;
			}
			case 'e':;								   //work
			case 'E': {

				if (0 == tab) {
					showmenuBook();
					cin.clear(0);
					cin.ignore(cin.rdbuf()->in_avail());			 //clear stream
					int YesOrNot = 0; //  продолжить или остановить ввод данных
					do
					{	 
						 
						cin.clear(0);
						cin.ignore(cin.rdbuf()->in_avail());
						//ReadMyFileBook(bookAmount, bookBacklist, listBook);
						bookBacklist = AddStructBook(bookBacklist, bookAmount);
						SetDataBook(bookBacklist, bookAmount);
						bookAmount++;
						SetConsoleCursorPosition(2, 41); 
						SaveFileBook(fileNameBook, bookBacklist, p_amountBook);
						ClearRow();
						cout << "Continue entering data (1 - yes, 0 - no): ";
						cin >> YesOrNot;
						cin.get();
					} while (YesOrNot != 0);
					ReadMyFileBook(bookAmount, bookBacklist, listBook);
				}
				else {
					showmenuUser();
					cin.clear(0);
					cin.ignore(cin.rdbuf()->in_avail());			 
					int YesOrNot = 0; //  продолжить или остановить ввод данных
					do
					{
						
						cin.clear(0);
						cin.ignore(cin.rdbuf()->in_avail());
						//ReadMyFileUser(userAmount, userBacklist, listUser);
						userBacklist = AddStructUser(userBacklist, userAmount);
						SetDataUser(userBacklist, userAmount);
						ClearRow();
						userAmount++;
						SetConsoleCursorPosition(2, 41); 
						SaveFileUser(fileNameUser, userBacklist, p_amountUser);
						cout << "Continue entering data (1 - yes, 0 - no): ";
						cin >> YesOrNot;										   //chek enter add
						cin.get();
					} while (YesOrNot != 0);
					ReadMyFileUser(userAmount, userBacklist,listUser);
				}
				ClearRow();
				break;
			}
			case 's':;
			case 'S': {
				if (tab == 0) {
					SaveFileBook(fileNameBook, bookBacklist, p_amountBook);
					cin.clear(0);
					cin.ignore(cin.rdbuf()->in_avail());
					ClearRow();
				}	
				else{
					SaveFileUser(fileNameBook, userBacklist, p_amountUser);
					cin.clear(0);
					cin.ignore(cin.rdbuf()->in_avail());
					ClearRow();
				}
				break;
			}
			case 'q':;								  //work
			case 'Q': {
				quit = ButtonQuit();
				ClearRow();
				break;
			}
			case 't':;
			case 'T': {
				fullmode = ButtonFullMode(fullmode);
				ClearRow();
				if (fullmode == 1) {
					for (int i = 5; i < 40; i++)
						FullClearRowPanel(i, fullmode);
					FullClearRow(41);

					if (tab == 0)
						ReadMyFuleBook( bookBacklist, bookAmount, listBook);
					else
						ReadMyFuleUser(userBacklist, userAmount, listUser);
				}
				else {
					for (int i = 5; i < 40; i++)
						FullClearRowPanel(i, fullmode);
					
						ReadMyFileBook(bookAmount, bookBacklist, listBook);
					
						ReadMyFileUser(userAmount, userBacklist, listUser);
				}

				cin.clear(0);
				cin.ignore(cin.rdbuf()->in_avail());			 //clear stream
				break;
			}
			case 'o':;
			case 'O': {
				if (tab == 0) {

					FullClearRow(41);
					BookClearRow();
					SetConsoleCursorPosition(2, 41);
					cout << "Enter file name ->";
					gets_s(fileNameBook);
					bookBacklist = OpenFileBook(fileNameBook, bookBacklist, p_amountBook);
					ReadMyFileBook( bookAmount, bookBacklist, listBook);

				}
				else {
					FullClearRow(41);
					SetConsoleCursorPosition(2, 41);
					cout << "Enter file name ->";
					gets_s(fileNameUser);
					userBacklist = OpenFileUser(fileNameUser, userBacklist, p_amountUser);

					ReadMyFileUser(userAmount, userBacklist, listUser);
				}
				cin.clear(0);
				cin.ignore(cin.rdbuf()->in_avail());
				ClearRow();
				
				break;
			}
			case 'r':;
			case 'R': {	
				if (tab == 0) {
					MassageBook_12();
					cin.getline(buf, 10);
					temp = atoi(buf);

					while (0 > temp || temp > 9999 || !atoi(buf))
					{
						MassageBook_13();
						cin.getline(buf, 10);
						temp = atoi(buf);

					}
					temp;
					eatline();
					SetDataBook(bookBacklist, temp);
					if (fullmode == 0)
						ReadMyFileBook(bookAmount, bookBacklist, listBook);
					else
						ReadMyFuleBook(bookBacklist, bookAmount, listBook);
					cin.clear(0);
					cin.ignore(cin.rdbuf()->in_avail());
					ClearRow();
				}  
				else {
					MassageMem_4();
					cin.getline(buf, 10);
					temp = atoi(buf);

					while (0>temp || temp>9999 || !atoi(buf))
					{
						MassageBook_12();
						cin.getline(buf, 10);
						temp = atoi(buf);

					}
					
					temp;
					eatline();
					SetDataUser(userBacklist, temp);
					if (fullmode == 0)
						ReadMyFileUser(userAmount, userBacklist, listUser);
					else
						ReadMyFuleUser(userBacklist, userAmount, listUser);
					cin.clear(0);
					cin.ignore(cin.rdbuf()->in_avail());
					ClearRow();
				}

				break;
			}
			case 'f':;
			case 'F': {									  
				cin.clear(0);
				cin.ignore(cin.rdbuf()->in_avail());
				ClearRow();
				if (tab == 0) {

					SearchBook(bookBacklist, bookAmount);
				}
				else {
					SearchUser(userBacklist, userAmount);
				}
				cin.clear(0);
				cin.ignore(cin.rdbuf()->in_avail());
				break;
			}
			case 'i':;
			case 'I': {

				if (tab == 0) {

					SearchBookID(bookBacklist, bookAmount);
				}
				else {
					SearchUserID(userBacklist, userAmount);
				}
				cin.clear(0);
				cin.ignore(cin.rdbuf()->in_avail());
				break;
			}
			case 13: {
				joke = ButtonReturn(joke);
				break;
			}
			default:
				cout << " That's not a choice.";
			}
			SetConsoleCursorPosition(2, 42);  // курсу на парковкy
			cin.clear(0);
			cin.ignore(cin.rdbuf()->in_avail());			 //clear stream
		}


	}
	delete[] bookBacklist;
	delete[] userBacklist;
	cout << " Bye!";
	return 0;





}