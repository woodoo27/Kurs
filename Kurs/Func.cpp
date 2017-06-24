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

Book* DelDataBook(Book* Obj, const int amount, int delrow) {
	
	int new_i=0;
	
	
		Book* tempObj = new Book[amount - 1];

		for (int i = 0; i < amount;i++ )
		{
			if (delrow == i){
			}
			else {
				tempObj[new_i] = Obj[i]; 
				new_i++;
			}
		}
		delete[] Obj;

		Obj = tempObj;
	
	return Obj;

}
User* DelDataUser(User* Obj, const int amount, int delrow) {
	int new_i = 0;


	User* tempObj = new User[amount - 1];

	for (int i = 0; i < amount; i++)
	{
		if (delrow == i) {
		}
		else {
			tempObj[new_i] = Obj[i];  
			new_i++;
		}
	}
	delete[] Obj;

	Obj = tempObj;

	return Obj;

}

Book* AddStructBook(Book* Obj, const int amount) {
	if (amount == 0)
	{
		Obj = new Book[amount + 1]; 
	}
	else
	{
		Book* tempObj = new Book[amount + 1];

		for (int i = 0; i < amount; i++)
		{
			tempObj[i] = Obj[i]; 
		}
		delete[] Obj;

		Obj = tempObj;
	}
	return Obj;
}
User* AddStructUser(User* Obj, const int amount) {
	if (amount == 0)
	{
		Obj = new User[amount + 1]; 
	}
	else
	{
		User* tempObj = new User[amount + 1];
		for (int i = 0; i < amount; i++)
		{
			tempObj[i] = Obj[i]; 
		}
		delete[] Obj;

		Obj = tempObj;
	}
	return Obj;
}

void SetDataBook(Book* Obj, const int amount) {

	char buf[200];
	int temp;


	MassageBook_1();
	cin.get(Obj[amount].B_name, 110);

	while (strlen(Obj[amount].B_name) > 100)
	{
		MassageBook_2();
		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());
		cin.get(Obj[amount].B_name, 110);
	}

	if (Obj[amount].B_name[0] != '\0')
		eatline();

	cin.clear(0);
	cin.ignore(cin.rdbuf()->in_avail());			

	MassageBook_3();
	cin.clear(0);
	cin.ignore(cin.rdbuf()->in_avail());
	cin.get(Obj[amount].Aut, 110);

	while (strlen(Obj[amount].Aut) > 100)
	{
		MassageBook_4();
		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());
		cin.get(Obj[amount].Aut, 110);
	}

	if (Obj[amount].Aut[0] != '\0')
		eatline();

	cin.clear(0);
	cin.ignore(cin.rdbuf()->in_avail());			

	MassageBook_5();
	cin.get(Obj[amount].R_date, 15);

	while (strlen(Obj[amount].R_date)>10)		
	{
		SetConsoleCursorPosition(2, 41);

		MassageBook_5();
		cin.ignore(cin.rdbuf()->in_avail());
		cin.get(Obj[amount].R_date, 15);
	}				 

	if (Obj[amount].R_date[0] != '\0')
		eatline();

	cin.clear(0);
	cin.ignore(cin.rdbuf()->in_avail());			 

	MassageBook_6();
	cin.get(Obj[amount].Con, 35);

	while (strlen(Obj[amount].Con) > 30) {

		MassageBook_7();
		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());
		cin.get(Obj[amount].Con, 35);
	}

	if (Obj[amount].Con[0] != '\0')
		eatline();

	cin.clear(0);
	cin.ignore(cin.rdbuf()->in_avail());			 

	MassageBook_8();
	cin.getline(buf, 8);
	temp = atoi(buf);

	while (1>temp || temp>11 || !atoi(buf))
	{
		MassageBook_9();
		cin.getline(buf, 5);
		temp = atoi(buf);

	}
	Obj[amount].Cou = temp;

	eatline();

	cin.clear(0);
	cin.ignore(cin.rdbuf()->in_avail());			 

	MassageBook_10();
	cin.getline(buf, 8);
	temp = atoi(buf);

	while (0>temp || temp>5 || !atoi(buf))
	{
		MassageBook_11();
		cin.getline(buf, 5);
		temp = atoi(buf);

	}
	Obj[amount].Rat = temp;
	eatline();

	cin.clear(0);
	cin.ignore(cin.rdbuf()->in_avail());			

	MassageBook_12();
	cin.getline(buf, 10);
	temp = atoi(buf);

	while (0>temp || temp>9999 || !atoi(buf))
	{
		MassageBook_13();
		cin.getline(buf, 10);
		temp = atoi(buf);

	}
	Obj[amount].ID_b = temp;
	eatline();

	
}
void SetDataUser(User* Obj, const int amount) {

	char buf[200];
	int temp;
	MassageMem_1();
	cin.get(Obj[amount].U_Name, 110);

	while (strlen(Obj[amount].U_Name) > 100)
	{
		MassageMem_5();
		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());
		cin.get(Obj[amount].U_Name, 110);
	}

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());			 

		MassageMem_2();
		cin.get(Obj[amount].Hbir, 11);
		if (Obj[amount].Hbir[0] != '\0')
			eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());

		MassageMem_3();
		cin.get(Obj[amount].DateIs, 11);
		if (Obj[amount].DateIs[0] != '\0')
			eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());

		MassageMem_4();
		cin.getline(buf, 10);
		temp = atoi(buf);

		while (0>temp || temp>9999 || !atoi(buf))
		{
			MassageBook_12();
			cin.getline(buf, 10);
			temp = atoi(buf);

		}
		Obj[amount].ID_vs_ID[0] = temp;

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());

		MassageMem_10();
		cin.getline(buf, 10);
		temp = atoi(buf);

		while (0>temp || temp>9999 || !atoi(buf))
		{
			MassageBook_11();
			cin.getline(buf, 10);
			temp = atoi(buf);

		}
		Obj[amount].Pas = temp;


		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());

		return ;
	}

void ShowDataBook(const  Book* Obj, const int amount) {
	SetConsoleCursorPosition(0, 5);
	for (int i = 0; i < 35; i++)
	{
		cout << setiosflags(ios::left);					
		cout << '|' << i << ":" << setw(3) << i << ":" << setw(20) << Obj[i].B_name;
		cout << '|' << i << ":" << setw(20) << Obj[i].Aut;
		cout << '|' << i << ":" << setw(10) << Obj[i].R_date;
		cout << '|' << i << ":" << setw(20) << Obj[i].Con;
		cout << '|' << i << ":" << setw(2) << Obj[i].Rat;
		cout << '|' << i << ":" << setw(5) << Obj[i].ID_b;
		cout << '|' << i << ":" << setw(3) << Obj[i].Cou << endl;
	}
}
void ShowDataUser(const  User* Obj, const int amount) {
	SetConsoleCursorPosition(0, 5);
	for (int i = 0; i < 35; i++)
	{
		cout << setiosflags(ios::left);					
		cout << char(186) << setw(3) << i << ":" << setw(20) << Obj[i].U_Name;
		cout << '|' << i << setw(11) << Obj[i].Hbir;
		cout << '|' << i << setw(11) << Obj[i].DateIs;
		cout << '|' << i << setw(20) << Obj[i].ID_vs_ID[0] << endl;
		cout << '|' << i << setw(20) << Obj[i].Pas << endl;
	}
}

Book* OpenFileBook(char* filename, Book* Obj, int * amount) {
	FILE * fName;
	fName = fopen(filename, "rb");
	if (fName) {
		fread(amount, sizeof(int), 1, fName);
		fclose;
	}

	//Создание массива с новым размером 
	Obj = new Book[*amount];
	//Запись в массив с файла

	fName = fopen(filename, "rb");
	if (fName) {
		fread(amount, sizeof(int), 1, fName);
		fread(Obj, sizeof(struct Book), *amount, fName);
		fclose;
	}
	SetConsoleCursorPosition(10, 3);
	cout << setw(30) << filename << " - open";
	return Obj;
}
User* OpenFileUser(char* filename, User* Obj, int * amount) {
	FILE * fName;
	fName = fopen(filename, "rb");
	if (fName) {
		fread(amount, sizeof(int), 1, fName);
		fclose;
	}

	//Создание массива с новым размером 
	Obj = new User[*amount];
	//Запись в массив с файла

	fName = fopen(filename, "rb");
	if (fName) {
		fread(amount, sizeof(int), 1, fName);
		fread(Obj, sizeof(struct User), *amount, fName);
		fclose;
	}
	SetConsoleCursorPosition(62, 3);
	cout << setw(30) << filename << " - open";
	return Obj;
}

void SaveFileBook(char* filename, Book* Obj, int * amount) {
	FILE * fName;
	fName = fopen( filename, "wb+");
	if (fName != NULL)
	{
		fwrite(amount, sizeof(int), 1, fName);
		fwrite(Obj, sizeof(struct Book), *amount, fName);
	}
	fclose(fName);
}
void SaveFileUser(char* filename, User* Obj, int * amount) {
	FILE * fName;
	fName = fopen(filename, "wb+");
	if (fName != NULL)
	{
		fwrite(amount, sizeof(int), 1, fName);
		fwrite(Obj, sizeof(struct User), *amount, fName);
	}
	fclose(fName);
}

void  NewFile(char* filename) {
	FILE * newFile;
	newFile = fopen(filename, "wb");
	fclose(newFile);
}

void ReadMyFileBook( int amount, Book* Obj,int listBook) {

		SetConsoleCursorPosition(0, 5);
		
			cout << setiosflags(ios::left);					
			cout << char(186) << setw(3) << "NN" << ":" << setw(20) << "Book";
			cout << '|' << setw(5) << "ID";
			cout << '|' << setw(5) << "Count" ;
		

		SetConsoleCursorPosition(0, 6);
		for (int i = listBook; i < (34 + listBook) && i<amount; i++) {
				cout << setiosflags(ios::left);					
		cout << char(186) << setw(3) << i << ":" << setw(20) << Obj[i].B_name;
		cout << '|' << setw(5) << Obj[i].ID_b;
		cout << '|' << setw(3) << Obj[i].Cou << endl;
	}


	SetConsoleCursorPosition(2, 41);
	ClearRow();
}
void ReadMyFileUser(int amount, User* Obj, int listUser) {
	int nrow = 0;
	int y = 6;
	cout << setiosflags(ios::left);
	SetConsoleCursorPosition(51, 5);
	cout << '|' << setw(3) << "NN" << setw(3) << ":" << setw(20) << "User";
	cout << '|' << setw(10) << "birthday";
	cout << '|' << setw(10) << "ID-user";

	SetConsoleCursorPosition(51, 6);
	for (int i = listUser; i < (34+ listUser) && i<amount; i++)	{
		SetConsoleCursorPosition(51, y);
		cout << setiosflags(ios::left);							
		cout << '|' << setw(3)<< nrow++ << setw(3) << ":" << setw(20) << Obj[i].U_Name;
		cout << '|' << setw(10) << Obj[i].Hbir;
		cout << '|' << setw(10) << Obj[i].DateIs << endl;
		y++;
	} nrow = 0;

	SetConsoleCursorPosition(2, 41);
	ClearRow();
}

void ReadMyFuleBook( Book* Obj, int amount,int listBook) {
		SetConsoleCursorPosition(0, 5);
		cout << setiosflags(ios::left);
		cout << char(186) << setw(3) << "NN" << ":" << setw(20) << "Book";
		cout << '|' << setw(20) << "Autor";
		cout << '|' << setw(10) << "Relise";
		cout << '|' << setw(20) << "Context";
		cout << '|' << setw(4) << "Rate";
		cout << '|' << setw(5) << "ID";
		cout << '|' << setw(5) << "Count" << endl;

			SetConsoleCursorPosition(0, 6);
		for (int i = listBook; i < (34 + listBook) && i<amount; i++) 

		{
		cout << setiosflags(ios::left);					
		
		cout << char(186) << setw(3) << i << ":" << setw(20) << Obj[i].B_name;
		cout << '|' << setw(20) << Obj[i].Aut;
		cout << '|' << setw(10) << Obj[i].R_date;
		cout << '|' << setw(20) << Obj[i].Con;
		cout << '|' << setw(4) << Obj[i].Rat;
		cout << '|' << setw(5) << Obj[i].ID_b;
		cout << '|' << setw(5) << Obj[i].Cou << endl;
		}
}
void ReadMyFuleUser( User* Obj, int amount,int listUser) {
	SetConsoleCursorPosition(0, 5);
	cout << setiosflags(ios::left);
	cout << char(186) << setw(3) << "NN" << ":" << setw(20) << "User";
	cout << '|' << setw(11) << "birthday";
	cout << '|' << setw(11) << "Date issue";
	cout << '|' << setw(20) << "ID-user";
	cout << '|' << setw(20) << "Passport";

		SetConsoleCursorPosition(0, 6);
	for (int i = listUser; i < (34 + listUser) && i<amount; i++)
	
	{
		cout << setiosflags(ios::left);
		cout << char(186) << setw(3) << i << ":" << setw(20) << Obj[i].U_Name;
		cout << '|' << setw(11) << Obj[i].Hbir;
		cout << '|' << setw(11) << Obj[i].DateIs;
		cout << '|' << setw(20) << Obj[i].ID_vs_ID[0] ;
		cout << '|' << setw(20) << Obj[i].Pas << endl;
	}
}   

void SearchBook(Book*Obj, const int amount) {
	char buf[50];
	bool search = false;
	ClearRow();
	if (amount == 0) {
		MassageBook_14();
	}
	else {
		MassageBook_15();
		cin.clear(0);
		cin.getline(buf, 50);
			for (int i = 0; i < amount; ++i) {
				if (strstr(buf, Obj[i].B_name) != NULL) {
					ShowBook(Obj,i);
					search = true;
				}
				
			}
			if(search!=true) {
					MassageBook_16();
				}
		}
}
void SearchUser(User*Obj, const int amount) {
	char buf[50];
	bool search = false;
	ClearRow();
	if (amount == 0) {
		MassageMem_13();
	}
	else {
		MassageMem_14();
		cin.clear(0);
		cin.getline(buf, 50); int i = 0;
		for (; i < amount; ++i) {
			if (strstr(buf, Obj[i].U_Name) != NULL) {

				ShowUser(Obj,i);
				search = true;
			}
			
		}  
		if(search != true) {
				MassageMem_15();
			}
	}

}

void SearchBookID(Book*Obj, const int amount) {
	char buf[50]; 
	int idSearch;
	bool search = false;
	ClearRow();
	if (amount == 0) {
		MassageBook_14();
	}
	else {
		MassageBook_17();
		cin.clear(0);
		cin.getline(buf, 8);
		idSearch = atoi(buf);

		while (1>idSearch || idSearch>9999 || !atoi(buf))
		{
			MassageBook_13();
			cin.getline(buf, 5);
			idSearch = atoi(buf);
		}
		
		for (int i = 0; i < amount; ++i) {
			if (Obj[i].ID_b == idSearch) {
				ShowBook(Obj,i);
				search = true;
			}
			
		} if (search != true) {
				MassageBook_16();
			}
	}
}
void SearchUserID(User*Obj, const int amount) {
	char buf[50];
	int idSearch;
	bool search = false;
	ClearRow();
	if (amount == 0) {
		MassageMem_13();
	}
	else {
		MassageMem_4();
		cin.clear(0);
		cin.getline(buf, 8);
		idSearch = atoi(buf);

		while (1>idSearch || idSearch>9999 || !atoi(buf))
		{
			MassageMem_11();
			cin.getline(buf, 5);
			idSearch = atoi(buf);
		}

		for (int i = 0; i < amount; ++i) {
			if (Obj[i].ID_vs_ID[0] == idSearch) {
				ShowUser(Obj,i);
				search = true;
			}

		} if (search != true) {
			MassageMem_15();
		}
	}
}

void BorrowBook(Book* ObjB, const int amountBook, User* ObjU, const int amountUser) {

}

void ShowBook(Book * Obj,int i) {
	SetConsoleCursorPosition(0, 41);
	cout << setiosflags(ios::left);
	cout << char(186) << setw(3) << "NN" << ":" << setw(20) << "Book";
	cout << '|' << setw(20) << "Autor";
	cout << '|' << setw(10) << "Relise";
	cout << '|' << setw(20) << "Context";
	cout << '|' << setw(4) << "Rate";
	cout << '|' << setw(5) << "ID";
	cout << '|' << setw(5) << "Count" << endl;

	SetConsoleCursorPosition(0, 42);
	
		cout << setiosflags(ios::left);

		cout << char(186) << setw(3)  <<i<< ":" << setw(20) << Obj[i].B_name;
		cout << '|' << setw(20) << Obj[i].Aut;
		cout << '|' << setw(10) << Obj[i].R_date;
		cout << '|' << setw(20) << Obj[i].Con;
		cout << '|' << setw(4) << Obj[i].Rat;
		cout << '|' << setw(5) << Obj[i].ID_b;
		cout << '|' << setw(5) << Obj[i].Cou << endl;
	
}
void ShowUser(User* Obj, int i) {
	SetConsoleCursorPosition(0, 41);
	cout << setiosflags(ios::left);
	cout << char(186) << setw(3) << "NN" << ":" << setw(20) << "User";
	cout << '|' << setw(11) << "birthday";
	cout << '|' << setw(11) << "Date issue";
	cout << '|' << setw(20) << "ID-user";
	cout << '|' << setw(20) << "Passport";

	SetConsoleCursorPosition(0, 42);

	
		cout << setiosflags(ios::left);
		cout << char(186) << setw(3) <<i<< ":" << setw(20) << Obj[i].U_Name;
		cout << '|' << setw(11) << Obj[i].Hbir;
		cout << '|' << setw(11) << Obj[i].DateIs;
		cout << '|' << setw(20) << Obj[i].ID_vs_ID[0];
		cout << '|' << setw(20) << Obj[i].Pas << endl;
	
	
}


/////////////////edit func					  
