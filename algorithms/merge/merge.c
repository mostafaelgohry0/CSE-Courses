/*
 ============================================================================
 Name        : merge.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */




//#include "header.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main (){


	int x ,i ;
	for(i=0 ;i<29;i++)
		x+=i;
	printf("%d",x);
	return 0;
}

//
// int i,j,k;
// int right_array[],left_array[];
//
//
//
//
//
// int input_n(){
//
// 	int n ;
// 	printf("Enter the number of array element");
// 	scanf("%d",&n);
// 	return n ;
// }
//
//
//
//
//
//int main() {
//
//
//    int n=input_n() ;   // the user define the size of array
//    int array[n];
//
//        // print the unsort array
//    	printf("the unsort array is { ");
//
//    	srand(time(0));
//    	 for(i=0;i<n;i++){
//    		array[i]=rand()%1000;
//    		printf("%d, ",array[i]);
//
//    	 }
//    	  printf("}");
//
//
//    split(array,n);
//
//    print_array(array,n);
//
//
//
// return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
///// the bublle sort array
//void merge_sort(int array[],int left ,int right){
//
//
//   i=0;  j=0; k=0;
//
//   while(i<=right && j<=left){
//
//	   if(left_array[i]<=right_array[j]){
//
//		   array[k]=left_array[i];
//		   i++;
//	   }
//
//	   else {
//
//		   array[k]=right_array[j];
//		   		   j++;
//	   }
//
//	   k++;
//
//
//   }
//
//
//
//
//   //check if there elements
//
//
//   while (i < left)
//      {
//          array[k] = left_array[i];
//          i++;
//          k++;
//      }
//
//      /* Copy the remaining elements of R[], if there are any */
//      while (j < right)
//      {
//          array[k] = right_array[j];
//          j++;
//          k++;
//      }
//
//
//
//}
//
//
//
//
//
//
//
///////  sprite
//
// int split(int array[],int n){
//
//	int mid;
//	int left=n/2;
//	int right=n/2;
//
//   //check the end of split element
//	if (n<2)
//	return 0;
//
//	else{
//		mid=n/2;
//
//	    for(i=0;i<mid;i++){
//		    left_array[i]=array[i];
//    	}
//
//	    for(i=mid;i<n-1;i++){
//			right_array[i]=array[i];
//		}
//
//
//	 split(left_array,mid);
//	 split(right_array,mid);
//
//	 merge_sort(array,left,right);
//
//
//	}
//
//
//
//
//}
//
//
// void print_array(int array[],int n){
//
//	 	// printing sorting array
//	 	printf(" \n the sort array is { ");
//	 	for(i=0;i<n;i++) {
//	 		printf("%d, ",array[i]);
//	 	}
//	 	   printf("}");
// }
//
//
//
//
//
//
//
//
//
//
//
//
//
//
////
////
////    // print the unsort array
////	printf("the unsort array is { ");
////
////	srand(time(0));
////	 for(i=0;i<n;i++){
////		array[i]=rand()%1000;
////		printf("%d, ",array[i]);
////
////	 }
////
////
////	   printf("}");
////
////
////// sorting
////
////  clock_t start ,end;    //calaclute time of program
////  double time ;
////
////start=clock();
////
////	for(i=0; i<n ;i++){
////
////		for(j=0 ;j<n-i;j++){
////			if(array[j]>array[j+1])
////				swap(&array[j],&array[j+1]);
////		}
////	}
////
////end=clock();
////
////	// printing sorting array
////	printf(" \n the sort array is { ");
////	for(i=1;i<=n;i++) {
////		printf("%d, ",array[i]);
////	}
////	   printf("}");
////
////
////
////time=(double)(end-start)/CLOCKS_PER_SEC;
////printf("\n\t the time= %f s",time);
////
////}
////
////
