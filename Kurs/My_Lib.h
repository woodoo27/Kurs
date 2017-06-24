#pragma once
#ifndef _my_h_lib_
#define  _my_h_lib_
//Struct/////////////////////////////////////////////////////////////


using namespace std;
const int LIM = 20;		 //for file
struct Book {					//  структура данных записной книжки
	char B_name[100];			//1.  Book name
	char Aut[100];				//2.  Author	Name
	char R_date[11];			//3.  Release date   format dd.mm.yyyy
	char Con[30];				//4.  Context
	int Cou;					//5.  Count Book
	int Rat;					//6.	rate
	int ID_b;					//7.	ID Book
};
struct User {					//  структура данных пользователя
	char U_Name[100];			//1.  Format User name Surname Patronymic
	char Hbir[11];				//2.  Happy birthday user  format dd.mm.yyyy
	char DateIs[11];			//3.  Date of issue  format dd.mm.yyyy
	int ID_vs_ID[6];			//5.  0-int ID-user 	  1-5 -book ID owner  6 -Number of books on hand
	int Pas;					//Passport
};

Book* AddStructBook(Book* Obj, const int amount);
User* AddStructUser(User* Obj, const int amount);

void SetDataBook(Book* Obj, const int amount);
void SetDataUser(User* Obj, const int amount);

void ShowDataBook(const  Book* Obj, const int amount);
void ShowDataUser(const  User* Obj, const int amount);

Book* OpenFileBook(char* filename, Book* Obj, int * amount);
User* OpenFileUser(char* filename, User* Obj, int * amount);

void SaveFileBook(char* filename, Book* Obj, int * amount);
void SaveFileUser(char* filename, User* Obj, int * amount);

Book* DelDataBook(Book* Obj, const int amount,  int delrow);
User* DelDataUser(User* Obj, const int amount, int delrow);

void SearchBook(Book*Obj, const int amount);
void SearchUser(User*Obj, const int amount);

void SearchBookID(Book*Obj, const int amount);
void SearchUserID(User*Obj, const int amount);

void ReadMyFileUser(int amount, User* Obj, int listBook);
void ReadMyFileBook(int amount, Book* Obj, int listUser);

void ReadMyFuleBook(Book* Obj, int amount, int listBook);
void ReadMyFuleUser(User* Obj, int amount, int listUser);

void BorrowBook(Book* ObjB, const int amountBook, User* ObjU, const int amountUser);

void ShowBook(Book* Obj, int search);
void ShowUser(User* Obj, int search);

void  NewFile(char* filename);
///////////////////////////////////////////////////func console
	
void eatline();
void SetConsoleWinSizePosition(int width, int heigth, short x_position, short y_position);
void SetConsoleCursorPosition(short x_position, short y_position);
//
///////////////////////////////////////////////////func file


///////////////////////////////////////////////////func menu & button
void showmenu();
void showmenuBook();
void showmenuUser();
void UGI(int tab);
int ButtonReturn(int j);
int ButtonTab(int tab);
bool ButtonQuit();
int ButtonFullMode(int t);



/////////////////////////////////Massage
void MassageBook_1();
void MassageBook_2();
void MassageBook_3();
void MassageBook_4();
void MassageBook_5();
void MassageBook_6();
void MassageBook_7();
void MassageBook_7();
void MassageBook_8();
void MassageBook_9();
void MassageBook_10();
void MassageBook_11();
void MassageBook_12();
void MassageBook_13();
void MassageBook_14();
void MassageBook_15();
void MassageBook_16();
void MassageBook_17();

void MassageMem_1();
void MassageMem_2();
void MassageMem_3();
void MassageMem_4();
void MassageMem_5();
void MassageMem_6();
void MassageMem_7();
void MassageMem_8();
void MassageMem_9();
void MassageMem_10();
void MassageMem_11();
void MassageMem_12();
void MassageMem_13();
void MassageMem_14();
void MassageMem_15();

void MassageFile_1();
void MassageFile_2();
void MassageFile_3();
void MassageFile_4();
void MassageFile_5();



//edit
void FullClearRow(int y);
void FullClearRowPanel(int y, int fulllmode);
void ClearRow();
void BookClearRow();
void UserClearRow();


#endif

