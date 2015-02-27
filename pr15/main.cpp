
#include <stdio.h>
#include <iostream>

#include "student.h" 


 #include <stdlib.h>
 #include <termios.h>	
 #include <string.h>
 #include <list>
 #include <set>
#define ClearScreen() printf("\033[H\033[J")
using namespace std;


int  main()
{
	char i = '0';
	int id=0;
	char tmp;
	char aChar[]={'a','b','c','d','f','i','g','k','l','A','B','C','D','F','I','G','K','L'};
	std::set<char> a(aChar, aChar+18);	
	
	list<student*> DB;
	list<student*>::iterator iter;

	do {
		switch (i) {
		case '0':
			/* Main menu*/
			ClearScreen();
			cin.clear();
			cin.sync();
			cout << "Add (1)"<<"\n" ;
			cout << "show A-K(2)" << "\n";
			cout << "Show list(3)" << "\n";
			cout << "Exit(4)" << "\n";
			cin >> i;
			break;

		case '1':
			/* Добавление */
			 ClearScreen();
			
			{student *t=new student;
			t->set_info_();
			DB.push_back(t);}
			i = '0';
			break;

		case '2':
			/*Удаление */
			ClearScreen();
			
			for(iter=DB.begin();iter!=DB.end();++iter){
				if(a.find((*iter)->FirstL)!=a.end()){				
					(*iter)->get_full_info();		
				}	
			}
			//getch();
			cin>>tmp;
			
			i = '0';
			break;

		case '3':
			/* Просмотр */
			 ClearScreen();
			for(iter=DB.begin();iter!=DB.end();++iter){
				(*iter)->get_full_info();			
			}
			//getch();
			cin>>tmp;
			i = '0';
			break;

		case '4':
			/* Выход */
			cin>>tmp;
			ClearScreen();	
			break;
		default:
			cout << "You entered the wrong character!  Try again"<<"\n";
			i = '0';
			//getch();
			break;
		}

	} while (i != '4');
	return 0;
}


