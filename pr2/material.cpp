#include <iostream>
#include <iomanip>
#include <locale>
#include <fstream>
using namespace std;
 


 struct  source { 
    int id; 
    string Adress; 
    string TelNumber;
};
  
struct List{
   source data;
    List *next;
};
 
class ListNode
{
    private:
        List *Head;
		ifstream FileOut;
		ofstream  FileIn;
		 string  NameFile ;
		 int Count; 
 
    public:
	
        ListNode():Head(NULL) {}


        void add(const  source value)                 //добавление в конец
        {
            List *Ptr = new (List);
            Ptr -> data = value;
 
            if(Head == NULL)
            {
                Head = Ptr;
                Ptr -> next = NULL;
				Count=1;
            }
            else
            {
                List *temp = Head;
 
                while(temp -> next != NULL)
                    temp = temp -> next;
                
                temp -> next = Ptr;
                Ptr -> next = NULL;
               
  	Count++;
            }
        }
 
         void  GetElemByPos( int Pos, const  source value )             //добавление в указанную
        {    
			 if (Head != NULL)
			 {
				 List *tmp = Head;


				 int Kol_el = 0;
				 while (tmp->next != NULL && tmp->data.id != Pos )
				 {
					 tmp = tmp->next;
					 ++Kol_el;
				 }
				 if (tmp->data.id == Pos){
					 tmp->data = value;
				 }
			 }
        }
 
        void delList(const int value)
        {
            List *tmp = Head;
            List *cur = NULL;
 
            if(Head != NULL)
            {
                if((Head -> data.id) == value)                 //если удаляем 1 элемент
                {
                    cur = Head -> next;
                    delete Head;
                    Head = cur;
				
                }
                else
                {
                    while((tmp->next != NULL) && (tmp -> data.id != value))
                    {
                        cur = tmp;
                        tmp = tmp -> next;
                    }
 
					if ((tmp->next == NULL) && (tmp->data.id == value))          //если элемент между
                    {   
															                     //1 и последним					
							delete tmp;
							cur->next = NULL;						
                    }
                    else                                    //если элемент последний
                    {
						if (tmp->data.id == value){
							cur->next = tmp->next;
							delete tmp;
						}
                    }
                }
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
        void showList()
        {
            List *temp = Head;
 
            if(Head != NULL)
            {
                while(temp != NULL)
                {
                    cout << temp -> data.id << ";  "<<temp -> data. Adress << ";  "<<temp -> data.TelNumber << ";"<<"\n";
 

                   temp = temp -> next;
                }
            }
            else
                cout << "list is empty!"<<"\n";
        }
};
 
