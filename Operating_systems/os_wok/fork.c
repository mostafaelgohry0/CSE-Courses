#include <stdio.h>
#include <stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>


int main()
{


    pid_t pid;

    //  input the number  n
     int n;
    printf("enter a number :: ");
    scanf("%d",&n);


      pid = fork();



// check to  generate a child

    if(pid<0){

       printf("error  to generate a child ");
       exit(0);

   }




    if (pid==0){


       //  check  the pid
        printf("\n\n\n----------------------------------------------");
        printf("\n this is the child ");
        printf("\nthis is child pid =%d ",pid);
        printf("\nthis is child  pidget  =%d ",getpid());
        printf("\nthis is child  ppidget  =%d \n\n",getppid());



     printf("the collatz of %d is = ",n);
        while(n!=1){

            if(n%2==0)

                 n=n/2;

            else
                 n=n*3+1;


            printf("%d ",n);

         }


         printf("\n----------------------------------------------\n");

}




    else if  (pid>0) {

         // check the pid
        printf("----------------------------------------------\n");
        printf("this is the parent");
        printf("\nthis is parent pid=%d ",pid);
        printf("\nthis is parent  pidget  =%d ",getpid());
        printf("\nthis is parent  ppidget  =%d \n",getppid());
        printf("----------------------------------------------\n");

        wait(NULL);
    }


    return 0;
}



