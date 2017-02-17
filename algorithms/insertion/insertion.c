/*
 ============================================================================
 Name        : insertion.c
 Author      : mostafaelgohry
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */







#include "header.h"


int main() {


	insertion_sort();


 return 0;
}





/// the bublle sort array
void insertion_sort(){



    int n=input_n() ;   // the user define the size of array
    int array[n];
    int i,j,in;


    // print the unsort array
	printf("the unsort array is { ");

	srand(time(0));
	 for(i=0;i<n;i++){
		array[i]=rand()%1000;
		printf("%d, ",array[i]);


	 }


	   printf("}");



   /// sorting


	for(i=0; i<n ;i++){

		for(j=0 ;j<n-i;j++){

			while(j>=0 && array[j]>array[j+1]){
				swap(&array[j],&array[j+1]);
			      j--;
			}
		}
	}


	// printing sorting array
	printf(" \n the sort array is { ");
	for(i=1;i<=n;i++) {
		printf("%d, ",array[i]);


	}


	   printf("}");

}
