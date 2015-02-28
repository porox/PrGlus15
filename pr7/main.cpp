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


	void clear(){
		
 		List *cur = NULL;
            if(Head != NULL)
            {
		List *temp = Head;
                while(temp)
                {
               	    cur=   temp ;
	                    temp = temp -> next;
          	    delete cur;
		 }
		
            }	
	}

	void pr(){
		List *r = Head;
		List *prev=NULL;
		int summ=0;
		if(Head != NULL)
		{	
			while((Head!=NULL)&&(Head->data%2==0)){
				r=Head->next;
				delete Head;
				Head=r;
			}
			if(Head != NULL){
				while (r){
				    List *next = r->next;
				    if (r->data % 2  == 0){
					if (prev) prev->next = next;
					delete r;
				    }
				    else{
					//cout<<prev<<" prev -> "<<prev->data<<" n"
					List *t =new List;
					t->data = r->data * r->data * r->data;
					summ+=r->data+t->data;					
					t->next=next;
					r->next=t;
					r=r->next;
					//prev->next=t;
					//prev = prev->next->next;
					prev=r;
				    }
				    r = next;
				   
				}
			}
			
			cout<<"summ= "<<summ;
		} else
		cout<<"List is empty !"<<"\n";
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
	while (!(cin>>tmp)){
		
			cerr << "Error while reading the integer value " << endl;
			cin.clear();
			while (cin.get() !='\n'); //clear
	}
	return tmp;
}

int main() {
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
			cout << "Processing(2)" << "\n";
			cout << "Show list (3)" << "\n";
			cout << "Exit(4)" << "\n";
			cin >> i;
			break;
		case '1':
			//add elements
			ClearScreen();
			cout << "Enter new element" << "\n";
			DB.add(dataSet());
			i = '0';
			break;
		case '2':
			//removing elements proportional 2
			ClearScreen();
			DB.pr();
			cin>>tmp;
			i = '0';
			break;
		case '3':
			//Show
			ClearScreen();
			DB.showList();
			//getch();
			cin>>tmp;
			i = '0';
			break;
		case '4':
			//exit
			ClearScreen();
			break;
		default:
			cout << "You entered the wrong character!  Try again" << "\n";
			i = '0';
			//getch();
			cin>>tmp;
			break;
		}

	} while (i != '4');
	DB.clear();
	return 0;
}

