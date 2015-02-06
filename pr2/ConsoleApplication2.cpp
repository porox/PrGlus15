#include <tchar.h>
#include "material.cpp"
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <windows.h>
using namespace std;

void ClearScreen()
  {
  HANDLE                     hStdOut;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD                      count;
  DWORD                      cellCount;
  COORD                      homeCoords = { 0, 0 };

  hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
  if (hStdOut == INVALID_HANDLE_VALUE) return;

  /* Get the number of cells in the current buffer */
  if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
  cellCount = csbi.dwSize.X *csbi.dwSize.Y;

  /* Fill the entire buffer with spaces */
  if (!FillConsoleOutputCharacter(
    hStdOut,
    (TCHAR) ' ',
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Fill the entire buffer with the current colors and attributes */
  if (!FillConsoleOutputAttribute(
    hStdOut,
    csbi.wAttributes,
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Move the cursor home */
  SetConsoleCursorPosition( hStdOut, homeCoords );
  }
  
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
			cout << "Exit(5)" << "\n";
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
			getch();
			i = '0';
			break;

		case '5':
			/* Выход */
			 ClearScreen();
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
			system("cls");
			break;
		default:
			cout << "You entered the wrong character!  Try again"<<"\n";
			i = '0';
			getch();
			break;
		}

	} while (i != '5');
	
	return 0;
}

