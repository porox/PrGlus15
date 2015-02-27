
#include "student.h"
	#include <stdio.h>
#include <iostream>

 #include <stdlib.h>
     #include <termios.h>
     #include <string.h>
#define ClearScreen() printf("\033[H\033[J")

//  
// Methods
//  


// Accessor methods
//  


// Other methods
//  

bool student::is_exam ()
{
	char tmp;
	int i;
	cout<<"Is exam? (1-yes, any key - no)"<<"\n";
	cin>>tmp;
	if (tmp=='1'){
		this->ex=true;
		cout<<"enter  mark exam!"<<"\n";
		while (!(cin >> i) || (i < 0)||(i>5)){
			cerr << "Error while reading the integer value > 0 and <5" << endl;
			cin.clear();
			cin.sync();
		}
		this->exam1.set(i);		
	}
	else{
		this->avt.is_olimp();
		this->ex=false;	
	}
	 
}



void student::get_full_info ()
{	cout<<"------------------------------------------------------------------------------"<<"\n";
	cout<<this->Last_name<<"|"<<this->First_name<<"|"<<this->Patronymic<<"\n";
	if (ex){
		cout<<"exam ball = "<<this->exam1.get()<<"\n";
		cout<<"------------------------------------------------------------------------------"<<"\n";
	}
	else{
		cout<<"avtomat reason:  "<<"\n";
		if(this->avt.olimp){
			cout<<"olimpiada !"<<"\n";			
		}
		else{
			cout<<"Kontrolnaja sred ball= "<<this->avt.Kr1.get()<<"\n";
		}

		cout<<"------------------------------------------------------------------------------"<<"\n";
	}
}



bool student::set_info_ ()
{
	cout<<"enter last name student"<<"\n";
	cin>> this->Last_name;
	this->FirstL=this->Last_name[0];
	cout<<"enter First name student"<<"\n";
	cin>> this->First_name;
	cout<<"enter Patronymic student"<<"\n";
	cin>>this->Patronymic;
	this->is_exam();
	return true;

}


