/*
 ============================================================================
 Name        : osc.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
    int n ;

//   collatz(8);

    char data[8];//={1,1,0,1,0,0,0,1};
    char hamming[4]={1,1,0,1};
   char ch;
   int i,j;
   i=0;
   j=0;

    while(i<8){

        ch=getchar();
        data[i]=ch;
        i++;

    }


i=0;
for(i=0;i<8;i++){

  printf("%c",data[i]);
  }


   print(data);
    org(data,hamming,1);

}


void print(char data[8]){

 int i=0;
for(i=0;i<8;i++){

  printf("%c",data[i]);
  }

}




void org(char data[8],char hamming[4],char parity) {

  char hamming_check[4];
int i=0;

 for(i=0;i<8;i++){

  printf(" %c",data[i]);
  }

  //  checking  hamming code
  hamming_check[0]=data[0]^data[1]^data[3]^data[4]^data[7];
  hamming_check[1]=data[0]^data[2]^data[3]^data[5]^data[6];
  hamming_check[2]=data[1]^data[2]^data[3]^data[7];
  hamming_check[3]=data[4]^data[5]^data[6]^data[7];



    for(i=0;i<8;i++){

  printf(" %c",data[i]);
  }


  for(i=0;i<4;i++){

  printf("%c",hamming_check[i]);
  }




}
