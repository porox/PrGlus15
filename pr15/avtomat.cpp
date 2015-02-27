#include "avtomat.h"

#include <stdio.h>
#include <iostream>

 #include <stdlib.h>
     #include <termios.h>
     #include <string.h>
#define ClearScreen() printf("\033[H\033[J")
using namespace std;
//  
// Methods
//  


// Accessor methods
//  


// Other methods
//  


/**
 * @return bool
 */
bool avtomat::is_olimp () 
{
	char tmp;
	int i;
	cout<<"Is olimp? (1-yes, any key - no)"<<"\n";
	cin>>tmp;
	if (tmp=='1'){
		this->olimp=true;
	}
	else{
		cout<<"Control!!"<<"\n";		
		cout<<"enter  average score!"<<"\n";
		while (!(cin >> i) || (i < 0)||(i>5)){
			cerr << "Error while reading the integer value > 0 and <5" << endl;
			cin.clear();
			cin.sync();
		}
		this->Kr1.set(i);
		this->olimp=false;
	}	
}


