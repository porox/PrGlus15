
#ifndef STUDENT_H
#define STUDENT_H
#include "exam.h"
#include "avtomat.h"
#include <string>
using namespace std;

class student
{
public:

  // Public attributes
  //  

  avtomat avt;
  exam exam1;
  bool ex;
  char FirstL;


  /**
   * @return bool
   */
  bool is_exam ();


  /**
   */
  void get_full_info ();


  /**
   * @return bool
   */
  bool set_info_ ();

protected:

public:

protected:

public:

protected:


private:

  // Private attributes
  //  

  string Last_name;
  string First_name;
  string Patronymic;
public:

private:

public:

private:



};

#endif // STUDENT_H
