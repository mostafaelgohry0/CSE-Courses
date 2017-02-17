/*
 ============================================================================
 Name        : swap.c
 Author      : mostafa elgohary
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int num1=1;
int num2=2;
//void input(int*num1,int*num2);
void swap_key(int num1,int num2);
void swap_sum(int num1,int num2);
void swap_multi(int num1 ,int num2);
void swap_pointer_type1(int*ptr_num1,int*ptr_num2);
void swap_pointer_type2(int*ptr_num1,int*ptr_num2);
void swap_array();




int main(void) {
	//int num1,num2;

  //  input(&num1,&num2);
	swap_key(num1,num2);
	swap_sum(num1,num2);
	swap_multi(num1,num2);
	swap_pointer_type1(&num1,&num2);
	swap_pointer_type2(&num1,&num2);
	swap_array();

	return EXIT_SUCCESS;
}







void input(int*num1,int*num2){

 printf("Enter num1: ");
	 scanf("%d",num1);
	 printf("Enter num2: ");
	 scanf("%d",num2);


}




// swap  by use a key
void swap_key(int num1,int num2){
	int key;

	key=num1;
	num1=num2;
	num2=key;

	printf("\n num1 in swap_key=%d \n num2 in swap_key=%d",num1,num2);

}



// swap by add the two numbers
void swap_sum(int num1,int num2){

	num1=num1+num2;
	num2=num1-num2;
	num1=num1-num2;

	printf("\n\n\n num1 in swap_sum=%d \n num2 in swap_sum=%d",num1,num2);
}




// swap by multiple  the two numbers
void swap_multi(int num1 ,int num2){

	num1=num1*num2;
	num2=num1/num2;
	num1=num1/num2;

	printf("\n\n\n num1 in swap_multi=%d \n num2 in swap_multi=%d",num1,num2);


}



//  swap  by using pointers

void swap_pointer_type1(int*ptr_num1,int*ptr_num2){
	int*ptr_key;

	ptr_key=ptr_num1;
	ptr_num1=ptr_num2;
	ptr_num2=ptr_key;

	printf("\n\n\n num1 in swap_pointer_type1=%d \n num2 in swap_pointer_type1=%d",*ptr_num1,*ptr_num2);


}




void swap_pointer_type2(int*ptr_num1,int*ptr_num2){

	    ptr_num1=ptr_num1+1;
		ptr_num2=ptr_num2-1;

		printf("\n\n\n num1 in swap_pointer_type2=%d \n num2 in swap_pointer_type2=%d \n",*ptr_num1,*ptr_num2);
}





void swap_array(){
  int i;
   char key[10];
   char arr1[10]="array 1";
   char arr2[10]="array 2";
    char *ptr_arr1,*ptr_arr2;



    for(i=0;i<10;i++){
        key[i]=arr1[i];
        arr1[i]=arr2[i];
        arr2[i]=key[i];
    }

         printf("\n\n");
           puts(arr1);
           puts(arr2);



////////////////////////////////  //////////////////// ////////////// ////////// ////////////// /////

 ptr_arr1=&arr1;
 ptr_arr2=&arr2;


     ptr_arr1=ptr_arr1+16;
     ptr_arr2=ptr_arr2-16;

      printf("\n\n");


               for(i=0;i<10;i++){
                   printf("%c",*ptr_arr1);
                   ptr_arr1++;

                }

             printf("\n");

                for(i=0;i<10;i++){
                     printf("%c",*ptr_arr2);
                     ptr_arr2++;

                }


}
