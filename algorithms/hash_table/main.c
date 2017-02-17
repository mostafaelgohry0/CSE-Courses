/*
 ============================================================================
 Name        : hash_table.c
 Author      :mostafa elgohry
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

  typedef struct hash{
		 int input_num;
		 int index_num;
	 }h;


int i;
int size();
void initial(struct hash*h,int n);
void print_hash(struct hash*h,int n);
void print_one_element(struct hash*h,int n);
void swap(struct hash*h,int n);
void delete_num(struct hash*h,int n);
void delete_hash(struct hash*h,int n);




int main(void) {

     int n,remainder;
     n=size();
     struct hash h[n];

       initial(h,n);

     for(i=0;i<n;i++){
    	 printf("  Enter %d number : ",i+1);
    	 scanf("%d",&h[i].input_num);


    	 remainder=h[i].input_num%n;
         printf("remainder of %d= %d \n",h[i].input_num,remainder);


         while(h[remainder].index_num!=-1){

            remainder=remainder+1;

            if(remainder>=n)
               remainder=remainder-n;
    	  }


        h[remainder].index_num=h[i].input_num;


     }


         print_hash(h,n);
         print_one_element(h,n);
         swap(h,n);
         delete_num(h,n);
         delete_hash(h,n);

	return EXIT_SUCCESS;
}



//__________________________________________________________________________________

// INPUT SIZE OF THE HASH TABLE

 int size(){
	 int n ;
	 printf("INPUT SIZE OF THE HASH TABLE : ");
	 scanf("%d",&n);
	 return n ;
 }

//__________________________________________________________________________________





//__________________________________________________________________________________

// initialize function
//  make the index of array = -1


void initial(struct hash*h,int n){

	int i;
	for(i=0;i<n;i++){

	    (h+i)->index_num=-1;

	}

}

//__________________________________________________________________________________




//__________________________________________________________________________________
//  Print function

void print_hash(struct hash*h,int n){




	 printf("\n");
	 printf("you entered  value : ");

	for(i=0;i<n;i++)
		printf("%-8d",(h+i)->input_num);


    printf("\n_____________THE  HASH TABLE____________\n");



	printf("the         value  : ");
    for(i=0;i<n;i++)
		printf("%-8d",i);


    printf("\n\n");
	printf("the new index value: ");

	for(i=0;i<n;i++)
        printf("%-8d",(h+i)->index_num);





}


//_______________________________________________________________________






//__________________________________________________________________________________
//// print one element


void print_one_element(struct hash*h,int n){
    int num;
    printf(" \n ENTER THE NUMBER OF INDEX NUMBER LESS THAN ( %d ) to print:",n);
    scanf("%d",&num);

    // test if num > n

    if(num>n-1) {
        printf("error enter  the number less %d " ,n);
        scanf("%d",&num);

    }

    printf("\nthe value of %d number = %d ",num,(h+num)->index_num);


}

//__________________________________________________________________________________





//__________________________________________________________________________________
// swap function
void swap(struct hash*h,int n){
     int num1,num2,key;
     printf(" \n ENTER THE TWO NUMBERS TO SWAP  :");
     scanf("%d%d",&num1,&num2);


     // swap
     key=(h+num1)->index_num;
     (h+num1)->index_num=(h+num2)->index_num;
     (h+num2)->index_num=key;


     printf(" \nthe hash table after  swap\n ");


	printf("the         value  : ");
    for(i=0;i<n;i++)
		printf("%-8d",i);


    printf("\n\n");
	printf("the new index value: ");

	for(i=0;i<n;i++)
        printf("%-8d",(h+i)->index_num);



}
//__________________________________________________________________________________






//__________________________________________________________________________________
//  delete function


void delete_num(struct hash*h,int n){
    int num;
    printf(" \nENTER THE NUMBER OF INDEX NUMBER  to DELETE:");
    scanf("%d",&num);
    (h+num)->index_num=0;


   printf(" \n the hash table after  delete\n ");

	printf("the         value  : ");
    for(i=0;i<n;i++)
		printf("%-8d",i);


    printf("\n");
	printf("the new index value: ");

	for(i=0;i<n;i++)
        printf("%-8d",(h+i)->index_num);


}
//__________________________________________________________________________________






//__________________________________________________________________________________
//  delete function


void delete_hash(struct hash*h,int n){


	for(i=0;i<n;i++)
        (h+i)->index_num=0;



 printf("\n\n");
	printf("the         value  : ");
    for(i=0;i<n;i++)
		printf("%-8d",i);


    printf("\n\n");
	printf("the new index value: ");

	for(i=0;i<n;i++)
        printf("%-8d",(h+i)->index_num);



}

//__________________________________________________________________________________
