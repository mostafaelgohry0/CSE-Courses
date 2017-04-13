

import random
import time 

numbers=100000    
item = [random.randint(-580,29890) for  c in range (numbers)] 

# the time of insertion  sort 
start=time.time()
insation_sort=(item)
print ("the time of insersion  sort is : ",time.time()-start)


#the time of merge sort is 
start=time.time()
merge_array=(item,numbers)
print ("the time of   merge  sort is   : ",time.time()-start)




#  insertion sort 


def insation_sort(item):
    for j in range(1,len(item)):
        key=item[j]
        i =j-1
        while i>=0 and item[i] >key :
            item[i+1]=item[i]
            i-= 1
        item[i+1]=key 





         # merge  sort  



def merge(item,left,right):
   
    while(i<right and j<left):
        
         if(left_array[i]<=right_array[j]):
             
             item[k]=left_array[i]
             i+=1
         else:
             item[k]=right_array[j]
             j+=1
              
         k+=1
         
         
         
    
    
    
   #check if there elements


    while (i < left):
      
          item[k] = left_array[i];
          i+=1
          k+=1
  
    while (j < right):
      
          item[k] = right_array[j];
          j+=1
          k+=1
      







def merge_array(item,n):
    
   

   
    left=n/2
    right=n/2

   #check the end of split element
    if n<2 :
        return 0

    else:
        mid=n/2

        for i in range (1,mid):
            left_array[i]=array[i];
        

        for i in range (mid,n):
            right_array[i]=array[i];
        


    merge_array(left_array,mid)
    merge_array(right_array,mid)

    merge(array,left,right)


    










