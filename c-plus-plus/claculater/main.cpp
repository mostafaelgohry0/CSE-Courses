#include <iostream>
using namespace std ;



int add()

{
int x,y;
char ch;
cin >>x>>ch>>y;

if ( ch== '+' )  //add
{
  return x+y;

}
 else if   (ch== '*') //multi
 {
 return x*y;


 }
 else if   (ch== '-') //sub
 {
 return x-y;


 }

  else if (ch== '/' ) // قسمه
 {
 return x/y;


 }
}

int main ()
{
  cout << "\n\n \t HALLO \n";
  cout << add();


  return 0;

}

