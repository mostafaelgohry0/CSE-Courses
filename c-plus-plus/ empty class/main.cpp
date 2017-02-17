




#include<iostream>
#include<string.h>
using namespace std;

                                       //sunday//

class sunday
{

  public:
   int sundaya(){  cout <<" \n\n the empty  classes are : class 1    class 4\n\n "; return 0;}
  int sundayb(){   cout <<"\n\n the empty classes are : class 3 \n\n " ;return 0;}
  int sundayc(){   cout <<"\n\n the empty classes are : class 1    class 2\n\n " ;return 0;}

};


                                    //monday//

class monday
{

  public:
  int  mondaya(){  cout <<"\n\n the empty classes are : no class\n\n";return 0;}
  int  mondayb(){   cout <<" \n\n the  empty classes are : class 5 \n\n" ;return 0;}
  int  mondayc(){   cout <<"\n\n  the empty classes are : class 1   class 7   class 2 \n\n" ;return 0;}


};


                                //Tuesday//

class tuesday
{

  public:
  int  tuesdaya(){  cout <<"\n\n the empty classes are : no class\n\n";return 0;}
  int  tuesdayb(){   cout <<" \n\n the  empty classes are : class 3 \n\n" ;return 0;}
  int  tuesdayc(){   cout <<"\n\n  the empty classes are :   class 2   class 4 \n\n" ;return 0;}


};


                             //Wednesday//

class wednesday
{

  public:
  int  wednesdaya(){  cout <<"\n\n the empty classes are :  class 3\n\n";return 0;}
  int  wednesdayb(){   cout <<" \n\n the  empty classes are : class 2 \n\n" ;return 0;}
  int  wednesdayc(){   cout <<"\n\n  the empty classes are :  class 2 \n\n" ;return 0;}


};




                                //thursday//

class  thursday
{

  public:
  int  thursdaya(){  cout <<"\n\n the empty classes are :  class 3\n\n";return 0;}
  int  thursdayb(){   cout <<" \n\n the  empty classes are : class 1 \n\n" ;return 0;}
  int  thursdayc(){   cout <<"\n\n  the empty classes are : class 3   class 7   class 4 \n\n" ;return 0;}


};





int main ()
{
   sunday ob1;
   monday ob2;
   tuesday  ob3;
   wednesday ob4;
   thursday ob5;
 char item[10];
 char period[3];
 cout << "\n \t\t Hallo  \n \n    This program help you to know the empty class in your faculty \n\n";
  cout << "     enter the day: ";
  cin >> item;

  cout <<" \n \n \" choose the period  \"a\" , \"b\" or \"c\"  \" ";
  cout << " \n\n    enter the period: ";
  cin>> period;

          //sunday//

  if ( strcmp (item,"sunday")==0)
  {

if ( strcmp (period,"a")==0)
  cout <<ob1.sundaya();

  else if ( strcmp (period,"b")==0)
  cout <<ob1.sundayb();

 else if ( strcmp (period,"c")==0)
  cout <<ob1.sundayc();

  cout << "             \n\nthanks for using this program\n\n";

  }

       //  monday //

  else if ( strcmp (item,"monday")==0)
  {

if ( strcmp (period,"a")==0)
  cout <<ob2.mondaya();

  else if ( strcmp (period,"b")==0)
  cout <<ob2.mondayb();

 else if ( strcmp (period,"c")==0)
  cout <<ob2.mondayc();

  cout << "             \n\nthanks for using this program\n\n";

  }

    //  tuseday //

  else if ( strcmp (item,"tuseday")==0)
  {

if ( strcmp (period,"a")==0)
  cout <<ob3.tuesdaya();

  else if ( strcmp (period,"b")==0)
  cout <<ob3.tuesdayb();

 else if ( strcmp (period,"c")==0)
  cout <<ob3.tuesdayc();

cout << "             \n\nthanks for using this program\n\n";
  }


              //  wednesday //

  else if ( strcmp (item,"wednesday")==0)
  {

if ( strcmp (period,"a")==0)
  cout <<ob4.wednesdaya();

  else if ( strcmp (period,"b")==0)
  cout <<ob4.wednesdayb();

 else if ( strcmp (period,"c")==0)
  cout <<ob4.wednesdayc();
cout << "             \n\nthanks for using this program\n\n";
  }



        //  thursday //

  else if ( strcmp (item,"thursday")==0)
  {

if ( strcmp (period,"a")==0)
  cout <<ob5.thursdaya();

  else if ( strcmp (period,"b")==0)
  cout <<ob5.thursdayb();

 else if ( strcmp (period,"c")==0)
  cout <<ob5.thursdayc();
cout << "             \n\nthanks for using this program\n\n";


  }

 else
cout << "\n\n error \n\n"<<"             \n\nthanks for using this program\n\n";
  return 0;

}
