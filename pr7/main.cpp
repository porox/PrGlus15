#include <iostream>
#include <iomanip>
#include <locale>
#include <stdio.h>
#include <iostream>
 #include <stdlib.h>
 #include <termios.h>
 #include <string.h>
#define ClearScreen() printf("\033[H\033[J")
using namespace std;
struct List{
	int data;
	List *next;
};

class ListNode
{
private:
	List *Head;
	int pow1(int i, int g){
		int res=i;
		while (g > 0){
			res *= i;
		}
		return res; 
	}

public:

	ListNode() :Head(NULL) {}

	void add(const  int value)                 //добавление в конец
	{
		List *Ptr = new List;
		Ptr->data = value;

		if (Head == NULL)
		{
			Head = Ptr;
			Ptr->next = NULL;
		}
		else
		{
			List *temp = Head;

			while (temp->next != NULL)
				temp = temp->next;

			temp->next = Ptr;
			Ptr->next = NULL;

		}
	}

	void SummElements(){
		List *temp = Head;
		int summ = 0; 
		if (Head != NULL)
		{
			while (temp != NULL)
			{
				summ += temp->data;
				temp = temp->next;
			}
			cout << "Summ = "<<summ<< "\n";
		}
		else
			cout << "list is empty!" << "\n";
	}

	void  AddCoube ()             //добавление в указанную
	{
		if (Head != NULL)
		{
			List *tmp = Head;
			List *cur = NULL;
			
			while ((tmp != NULL)){

				cur = tmp;
				tmp = tmp->next;
				List *temp = new (List);
				temp->data = cur->data * cur->data * cur->data;
				temp->next = tmp;
				cur->next = temp;
				tmp = cur;
				tmp = tmp->next->next;
			}
			
		}
	}

	void delElements()
	{
		List *tmp = Head;
		List *cur = NULL;

		if (Head != NULL)
		{
			if ((Head->data)%2  == 0)                 //если удаляем 1 элемент
			{
				cur = Head->next;
				delete Head;
				Head = cur;
			}
			else
			{
				while ((tmp->next != NULL)){
						
				cur = tmp;
				tmp = tmp->next;
				if (tmp->data % 2 == 0){
					if ((tmp->next == NULL))          
					{				
						delete tmp;
						cur->next = NULL;
						
					}
					else                    
					{
							cur->next = tmp->next;
							delete tmp;
					}
					tmp = cur;
				}
	
				}
			}
		}
	}

	void showList()
	{
		List *temp = Head;

		if (Head != NULL)
		{
			while (temp != NULL)
			{
				cout << temp->data << "; " <<"\n";
				temp = temp->next;
			}
		}
		else
			cout << "list is empty!" << "\n";
	}
};
int dataSet(){
	int tmp;
	bool check;
	check=true;
	while (check){
		
			cerr << "Error while reading the integer value " << endl;
			
		if (cin >> tmp){ check= false; cin>>tmp;}; 
	}
	return tmp;
}

int  main() 	
{	
	ListNode DB;
	char tmp;
	char i = '0';
	do {
		switch (i){
		case '0':
			/* Main menu*/
			ClearScreen();
			cin.clear();
			cin.sync();
			cout << "Add (1)" << "\n";
			cout << "Removing elements proportional 2(2)" << "\n";
			cout << "Sum(3)" << "\n";
			cout << "Add coube (4)" << "\n";
			cout << "Show list (5)" << "\n";
			cout << "Exit(6)" << "\n";
			cin >> i;
			break;
		case '1':
			//add elements
			ClearScreen();
			cout << "Enter new  element" << "\n";
			DB.add(dataSet());
			i = '0';
;			break;
		case '2':
			//removing elements proportional 2
			ClearScreen();
			DB.delElements();
			i = '0';
			break;
		case '3':
			//summ elements
			ClearScreen();
			DB.SummElements();
			//getch();
			cin >>tmp;
			i = '0';
			break;
		case '4':
			//add coube
			ClearScreen();
			DB.AddCoube(); 
			i = '0';
			break;
		case '5':
			//Show
			ClearScreen();
			DB.showList();
			//getch();
			cin>>tmp;
			i = '0';

			break;
		case '6':
			//exit 
			ClearScreen();
			break;
		default:
			cout << "You entered the wrong character!  Try again" << "\n";
			for (int f = 1; f < 10; f++){
				DB.add(f);
			}
			i = '0';
			//getch();
			cin>>tmp;
			break;
		}

	} while (i != '6');

	return 0;
}

