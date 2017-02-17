/*
 ============================================================================
 Name        : bubble.c
 Author      : mostafaelgohry
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
*/





#include "header.h"


int main() {


    int n=input_n() ;   // the user define the size of array
    int array[n];

	bubble_sort(array,n);


 return 0;
}




/// the bublle sort array
void bubble_sort(int array[],int n){


 int i,j;

    // print the unsort array
	printf("the unsort array is { ");

	srand(time(0));
	 for(i=0;i<n;i++){
		array[i]=rand()%1000;
		printf("%d, ",array[i]);

	 }


	   printf("}");


// sorting

  clock_t start ,end;    //calaclute time of program
  double time ;

start=clock();

	for(i=0; i<n ;i++){

		for(j=0 ;j<n-i;j++){
			if(array[j]>array[j+1])
				swap(&array[j],&array[j+1]);
		}
	}

end=clock();

	// printing sorting array
	printf(" \n the sort array is { ");
	for(i=1;i<=n;i++) {
		printf("%d, ",array[i]);
	}
	   printf("}");



time=(double)(end-start)/CLOCKS_PER_SEC;
printf("\n\t the time= %f s",time);

}



