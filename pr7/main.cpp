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
		List *temp = Head;
 		List *cur = NULL;
            if(Head != NULL)
            {
                while(temp != NULL)
                {
               	    cur=   temp ;
	                    temp = temp -> next;
          	    delete cur;
		 }
            }	
	}

	void pr(){
		List *temp = Head;
 		List *cur = NULL;
		List *prev= Head;
		int summ=Head->data;
		bool end=false;
            if(Head != NULL)
            {	
		if ((Head->data % 2)==0){delete Head; temp=Head->next; Head=temp; summ=0; }
		while((temp->next!=NULL)){
			cout<<"main ( "<<temp<<" data "<<temp->data<<" ; next->"<<temp->next<<")"<<"prev ( "<<prev <<"data  "<<prev->data<<" prev next "<<prev->next<<") \n";
			if((temp->data%2)==0){
				if (temp->next==NULL){
					if(temp==Head){Head->next=NULL;}
					 prev->next=NULL;
				}
				else{
					if (temp==Head){
						delete temp;
						Head=Head->next;
						cur=Head; 
					}
					else{
						if (!((temp->data %2)==0)){prev->next=temp;} 
						cur=temp->next;
						cout<<"del("<<temp<<" ;data ->"<<temp->data<<"); ";
						delete temp;
					}

					temp=cur;
					cout<<"xyi("<<temp<<" ; data->"<<temp->data<<"); ";

					if((temp->data % 2)!=0){prev->next=temp; prev=temp; cout<<"prev("<<prev<<" ;data= "<<prev->data<<")"<<"\n";}
				} 			
			}else {summ+=prev->data; temp=temp->next;}
			
		}	
		if ((temp->data % 2)==0){ prev->next=NULL;}
		cout<<"summ= "<<summ;
            } else
		 cout<<"List is empty !"<<"\n";
	
	}

	void processing(){
		int sum=0;
		if (Head != NULL)
		{
			List *cur = NULL;
			
			while ( ((Head->data%2) == 0)&(Head!=NULL)) //если удаляем 1 элемент
			{
				if ((Head->next == NULL)) {
								delete Head;
								cur->next = NULL;
							
							}	
							else{
									cur= Head->next;
									delete Head;
							}
				Head = cur;
				Head=Head->next;
			}
			
		if (Head != NULL)
			{
		
			List *tmp = Head;
			
			
			while ((tmp != NULL)){

				cur = tmp;
				tmp = tmp->next;
				
				//dell prop 2
					if ((tmp!=NULL)){
						if(tmp->data %2==0){
							if ((tmp->next == NULL)) {
								delete tmp;
								cur->next = NULL;
							
							}	
							else{
								
	cur->next = tmp->next;
									delete tmp;
							}
							if (cur==NULL) {break;}
							tmp= cur->next;
						}
					}	
				//
				
				//add coube
				if ((cur!=NULL)){
					if(tmp->data % 2 !=0){
						List *temp = new (List);
						temp->data = cur->data * cur->data * cur->data;
						sum+=cur->data+temp->data;
						temp->next = tmp;
						cur->next = temp;
							
						tmp = cur;
						tmp = tmp->next->next;
					}
				}else break;
				//
				
			}
			cout << "Summ = "<<sum<< "\n";
			
		}} else cout << "list is empty!" << "\n";
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

