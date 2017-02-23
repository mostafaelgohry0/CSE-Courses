/*
 ============================================================================
 Name        : cache_simulation.c
 Author      :
 Version     :
 Conpyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

/*
   #define direct_mapping 1
   #define  full_mapping 2
   #define  set_mapping 3
*/
///  the strutct

  typedef struct Cache {

	int memory_size;
	int cache_size;
    short mapping_fun;
	short replace_alg;
	short write_miss_policy;
	short write_hit_policy;


  }cache;


  //// end struct





  //// input function


 void input(struct Cache*cache){


	 printf("ENTER THE SIZE OF MAIM MEMORY IN (megabyte):");
	 scanf("%d",&cache->memory_size);

	 printf("ENTER THE SIZE OF CACHE IN (kilobyte):");
	 scanf("%d",&cache->cache_size);

	 printf(" CHOOSE THE MAPPING FUNCTION \n \"1\" direct , \"2\" full or \"3\" set: " );
     scanf("%d",&cache->mapping_fun);


     printf(" CHOOSE THE REPLACEMENT ALGORITHM \n \"1\" Least Recently Used , \"2\" First In First Out \"3\" ,Least Frequently Used   or \"4\"  Random  :");
     scanf("%d",&cache->replace_alg);


     printf("CHOOSE THE WRITE HIT POLICEY  \n \"1\" write through  or \"2\" write back :");
     scanf("%d",&cache->write_hit_policy);

     printf("CHOOSE THE WRITE MISS POLICEY  \n \"1\" write-allocate  or \"2\" no-write-allocate :");
     scanf("%d",&cache->write_miss_policy);

 }


 //////////////////////////////////////////////////////////////////////////////////////////










///////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////
 void direct_mapping(struct Cache*cache){

       int x;
       x=(cache->memory_size);
       int i,k;
        k=0;
        int hit[200];
        int y;
        y=(cache->cache_size);

        char ch;
        float f_bits;
        float f_r,f_s, f_blocks,f_line ;
        int bits;
        int r,s, blocks,line ,tag;

        int address;
       int count_line=0;
       int count_tag=0;

        int line_hit;
/*
   bool hit_test;
        hit_test=false;
*/
    int hit_test=0;





        f_bits=log2(x);
        bits=ceil(f_bits);
        int arr1[bits];

        printf("\n the all bits %d\n",bits);



         // calculate    line and tag
           f_s=log2(x/4);
           s=ceil(f_s);

           f_r=log2(y/4);
           r=ceil(f_r);

           tag=s-r;



         printf("\n%d",s);
         printf("\n \t the line = %d",r);
         printf("\n \t the tag= %d\n",tag);






         while(1){
         printf("CHOOSE \"r\" for reading \"w\" for writing  or \"e\" to exit :: ");
         scanf("%c",&ch);



         if(ch=='r'){
         printf("enter the address :: ");
         scanf("%d",&address);


          for(i=0;i<bits;i++){

            arr1[i]=address%2;
            address=address/2;

           }

        //// clcuate  the line

        for(i=2;i<r+2;i++){

         count_line+=(arr1[i]*(2^(i-2)));
        //printf("\n%d",count);
         printf("%d",arr1[i]);
        }
         printf("\n the line  %d\n",count_line);
            count_line=0;


                hit[k]=count_line;
                k++;









         ////calclate   the tage

         for(i=r+2;i<bits;i++){

         count_tag+=(arr1[i]*(2^(i-2)));
        //printf("\n%d",count);
         printf("%d",arr1[i]);
        }
         printf("\n the tag  %d\n",count_tag);
          count_tag=0;


            for(i=0;i<k;i++){


               if( line_hit==hit[i])
                hit_test=1;


            }


            if (hit_test==1)
                printf("\n\t hit \n");

            else
                printf("\n\t miss \n");




         }








          else if (ch=='e')
          exit(1);

          }


/*
        f_bits=log2(x);
        bits=ceil(f_bits);
        int arr1[bits];

        printf("%d\n",bits);
*/


     // f_blocks=x/4;     // assume the block has 4 byte
     // f_line=y/4 ;     // assume  the line has 4 byte



/*
      f_s=log2(x/4);
      s=ceil(f_s);

      f_r=log2(y/4);
      r=ceil(f_r);

      tag=s-r;
*/

    // initalize   bits
      for(i=0;i<bits;i++)
          arr1[i]=0;



   //inialize   arr hit

     for(i=0;i<200;i++)
          hit[i]=0;

     for(i=0;i<bits;i++){

         arr1[i]=address%2;
         address=address/2;

     }


     for(i=2;i<r+2;i++){

      //  count+=arr1[i]*2^(i-2);
        //printf("\n%d",count);
        printf("%d",arr1[i]);
     }
//      printf("\n%d",count);



  printf("\n\n");

      for(i=0;i<bits;i++){

        arr1[i]=x%2;
        x=x/2;


      }

      for(i=0;i<bits;i++){

        printf("%d",arr1[i]);
      }



         printf("\n%d",s);
         printf("\n \t the line = %d",r);
         printf("\n \t the tag = %d",tag);







 }






 void full_mapping(struct Cache*cache){



 }



  void set_mapping(struct Cache*cache){





  }


int main(void) {

	struct Cache cache;


      input(&cache);

      if(cache.mapping_fun==1)
	  direct_mapping(&cache);

	  else if (cache.mapping_fun==2)
       full_mapping(&cache);

     else if (cache.mapping_fun==3)
        set_mapping(&cache);



	return EXIT_SUCCESS;

}
