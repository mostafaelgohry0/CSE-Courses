#include <stdio.h>
#include <stdlib.h>
#include<sys/types.h>

int main()
{
    int n ;

    collatz(8);

    return 0;
}




void collatz(int n){
/*
printf("\n Enter a number :: ");
scanf("%d",&n);

printf("\n the collatz of %d  is = ",n);
*/

  while(n!=1){



    if(n%2==0){


        fork();
       n=n/2;
       wait();
    }


     else {

    fork();
    n=n*3+1;
     wait();
     }
    // wait();
    printf("%d ",n);
   // wait();

  }

}
