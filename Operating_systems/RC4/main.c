

///---------------------------------------------------------------

 //  Name ::  Mostafa Elasayed Gohary
 //    program :  RC4


///---------------------------------------------------------------




#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n,k, *key_ptr,i,p;

    int P[100];




    printf("  Enter the size of  lookup table S  : ");
    scanf("%d",&n);

    printf("  Enter the size of  key array : ");
    scanf("%d",&k);

    printf("  Enter the size of  plaintext array  : ");
    scanf("%d",&p);


    key_ptr=(int*)malloc(n*sizeof(int));


///---------------------------------------------------------------
      /////  input   the  plaintext

      printf("\n enter  the  plaintext   :  ");

        for(i=0;i<p;i++){

            scanf("%d",&P[i]);
        }



                     // input the key
    printf(" \n  Enter the key array  :    ");

    for(i=0;i<k;i++){

        scanf("%d",(key_ptr+i));
    }


///---------------------------------------------------------------

  ///   print   the key
    printf("\n you entered this array key :: ");
     for(i=0;i<k;i++){

            printf(" %d  ",*(key_ptr+i) );
     }




 ///   print   the plaintext
    printf("\n you entered this array plaintext :: ");
     for(i=0;i<p;i++){

            printf(" %d  ",P[i] );
     }


///---------------------------------------------------------------




                  RC4(p,P,n,k,key_ptr);



    return 0;
}




///   swap function

 void swap (int *x ,int *y){
  int z ;

 // printf(" b %d   %d  \n",*x,*y);
    z=*x;
    *x=*y;
    *y=z;

 //printf(" a %d   %d  \n",*x,*y);
 }




////////////////////////////////////////////////////////////////////////////

///   rc4  function

 void RC4 (int p ,int P[100] ,int n, int k ,int*key_ptr){


  int s[n],i,j,key_byte[n],t,m;

  int encrypt[p],decrypt[p];

   j=0;








   ///  intalize  the key array
   /*
  for (i=k;i<n;i++){

    *(key_ptr+i)=*(key_ptr-k+i);

  }

 //   check key  array
  printf("\n ");
   for(i=0;i<n;i++){

            printf(" %d  ",*(key_ptr+i) );
     }
*/





///  inatialize

 for (i=0;i<n;i++){

    s[i]=i;
    *(key_ptr+i)=*(key_ptr+(i%k));

 }



///---------------------------------------------------------------

/// print s
printf("\n\n  the   S array is  : ");
for (i=0;i<n;i++){

      printf("%d ",s[i]);
}

/// print  k

printf("\n  the  k  array  is  : ");
for (i=0;i<n;i++){

    printf("%d ",*(key_ptr+i));

}

///---------------------------------------------------------------

//////////////////////////////////////////////////////////////////////////////////////////

/////// generate   the    s  array

for (i=0;i<n;i++){

    j=(j+s[i]+*(key_ptr+i))%n;

    swap(&s[i],&s[j]);

  }






printf("\n\n   the   S array is  : ");
for (i=0;i<n;i++){

      printf("%d ",s[i]);
}



printf("\n\n");
    m=0;
    j=0;
    for(i=0;i<n;i++){


    i=(i+1)%n;
    j=(j+s[i])%n;

    swap(&s[i],&s[j]);

    t=(s[i]+s[j])%n;
    key_byte[m]=s[t];

     m++;

    }



  //  print  the  keystreambyte

  printf("\n this is the Keystreambyte  :  ");
  for(i=0;i<p;i++)
    printf(" %d ",key_byte[i]);



/////////////////////////////////////////////////////////////////////////////////////


     ///encrypt


   /// print  the encrypt  array

   printf("   \n\n this is the encrypt array  : ");

     for(i=0;i<p;i++){

        encrypt[i]=key_byte[i]^P[i];

        printf(" %d ",encrypt[i]);

     }




///////////////////////////////////////////////////////////////////////////////////////////

   ///decrypt


   /// print  the encrypt  array

   printf("   \n this is the decrypt array  : ");

     for(i=0;i<p;i++){

        decrypt[i]=key_byte[i] ^ encrypt[i];

        printf(" %d ",decrypt[i]);

     }


 }
