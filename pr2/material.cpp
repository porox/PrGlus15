#include <iostream>
#include <iomanip>
#include <locale>
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
		string NameFile ='.\DB.txt';
 
    public:
	
        ListNode():Head(NULL) {}

bool FileWrite()
		{
			int sizeAdress;
			int sizeTelNumber;
			try
			{
				
				List *temp = Head;

				if (Head != NULL)
				{
					FileIn.open(NameFile, ios_base::binary | ios::out);
					
					FileIn.write((char*)&Count, sizeof(int));
					while (temp != NULL)
					{
						FileIn.write((char*)&temp->data.id, sizeof(temp->data.id));
						sizeAdress = temp->data.Adress.length();
						
						FileIn.write((char*)&sizeAdress, sizeof(sizeAdress));
						
						FileIn.write((char*)temp->data.Adress.c_str(), sizeof(char) * sizeAdress);
						
						sizeTelNumber = temp->data.TelNumber.length();
						
						FileIn.write((char*)&sizeTelNumber, sizeof(sizeTelNumber));
						
						FileIn.write((char*)temp->data.TelNumber.c_str(), sizeof(char)*sizeTelNumber);
						temp = temp->next;
					}
					FileIn.close();
				}
				else
					throw 1;
			}
			catch(...)
			{
				return false;
			}
			return true;
		}

		bool FileRead()
		{
			int sizeAdress=0;
			int sizeTelNumber=0;
			bool out = true;
			source data;
			int i=0;
			int Col;
			try
			{

					FileOut.open(NameFile, ios_base::binary | ios::in);
					if (FileOut.is_open()) {

						FileOut.read((char*)&Col, sizeof(int));
						while (i < Col)
						{
							FileOut.read((char*)&data.id, sizeof(int));

							FileOut.read((char*)&sizeAdress, sizeof(int));
							char *tmp = new char[sizeAdress + 1];
							tmp[sizeAdress] = '\0';
							FileOut.read(tmp, sizeof(char)*sizeAdress);
							data.Adress = (string)tmp;
							FileOut.read((char*)&sizeTelNumber, sizeof(int));
							char *tmp1 = new char[sizeTelNumber + 1];
							tmp1[sizeTelNumber] = '\0';
							FileOut.read(tmp1, sizeof(char)*sizeTelNumber);
							data.TelNumber = (string)tmp1;
							
							add(data);
							i++;
						}
						FileOut.close();
						
					}
					else{ throw 4; } 			
			}
			catch (...)
			{
				out = false;
			}
			return out;
		}
        void add(const  source value)                 //добавление в конец
        {
            List *Ptr = new List;
            Ptr -> data = value;
 
            if(Head == NULL)
            {
                Head = Ptr;
                Ptr -> next = NULL;
            }
            else
            {
                List *temp = Head;
 
                while(temp -> next != NULL)
                    temp = temp -> next;
                
                temp -> next = Ptr;
                Ptr -> next = NULL;
               
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
 
