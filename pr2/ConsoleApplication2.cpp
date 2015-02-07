#include "material.cpp"
#include <stdio.h>
#include <iostream>

 #include <stdlib.h>
     #include <termios.h>
     #include <string.h>
#define ClearScreen() printf("\033[H\033[J")
using namespace std;

  
source dataSet(){
	source tmp;
	cout << "Enter id library" << "\n";
	while (!(cin >> tmp.id) || (tmp.id < 0)){
	cerr << "Error while reading the integer value > 0" << endl;
	cin.clear();
	cin.sync();
	}
	cout << "Enter  Adress  library " << "\n";
	cin >> tmp.Adress;
	cout << "Enter TelNumber library" << "\n";
	cin >> tmp.TelNumber;

	return tmp;
}

int  main()
{
	char i = '0';
	int id;
	char tmp;

	ListNode DB;

	do {
		switch (i) {
		case '0':
			/* Main menu*/
			 ClearScreen();
			cin.clear();
			cin.sync();
			cout << "Add (1)"<<"\n" ;
			cout << "Delete(2)" << "\n";
			cout << "Change(3)" << "\n";
			cout << "Show list(4)" << "\n";
			cout << "File write(5)" << "\n";
			cout << "File read(6)" << "\n";
			cout << "Exit(7)" << "\n";
			cin >> i;
			break;

		case '1':
			/* Добавление */
			 ClearScreen();
			cout << "Enter new  data" << "\n";
			DB.add(dataSet());
			i = '0';
			break;

		case '2':
			/*Удаление */
			 ClearScreen();
			cout << "Enter record id, you want to delete " << "\n";
			while (!(cin >> id) || (id < 0)){
				cerr << "Error while reading the integer value > 0" << endl;
				cin.clear();
				cin.sync();
			}
			DB.delList(id);
			i = '0';
			break;

		case '3':
			/*Изменение */
		 ClearScreen();
			cout << "Enter record id, you want to change " << "\n";
			while (!(cin >> id) || (id < 0)){
				cerr << "Error while reading the integer value > 0" << endl;
				cin.clear();
				cin.sync();
			}
			DB.GetElemByPos(id, dataSet());
			i = '0';
			break;

		case '4':
			/* Просмотр */
			 ClearScreen();
			DB.showList();
			//getch();
			cin>>tmp;
			i = '0';
			break;


	case '5':
			/*Запись в фаил*/
			ClearScreen();
			if (!(DB.FileWrite()))
			{
				cerr << "File error!!" << endl;
			}
			i = '0';
			break;

		case '6':
			/*Запись в фаил*/
			ClearScreen();
			if (!(DB.FileRead()))
			{
				cerr << "File error!!" << endl;
				
			}
			i = '0';
			break;

		case '7':
			/* Выход */
			ClearScreen();
			break;
		default:
			cout << "You entered the wrong character!  Try again"<<"\n";
			i = '0';
			//getch();
			break;
		}

	} while (i != '7');
	
	return 0;
}

