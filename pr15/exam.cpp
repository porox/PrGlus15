#include "exam.h"
	#include <stdio.h>
#include <iostream>

 #include <stdlib.h>
     #include <termios.h>
     #include <string.h>
#define ClearScreen() printf("\033[H\033[J")
using namespace std;
//  




//  
// Methods
//  


// Accessor methods
//  


// Other methods
//  


/**
 * @param  ball
 */
void exam::set (int ball)
{
	_ball=ball;
}


/**
 * @return int
 */
int exam::get ()
{
	return(_ball);
}


