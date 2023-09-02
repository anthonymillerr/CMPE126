#include<iostream>
using namespace std;

int recursiveSequentialSearch(int *array,int size,int x){
   
   if(size==0)
      return -1;
   
   else{
      if(array[size-1]==x)
         return size;
      else
         recursiveSequentialSearch(array,size-1,x);
      
   }
}

int recursiveBinarySearch(int *array,int left,int right,int n){
   static int count =0;
   
   if(right-left<15){
      int pos=recursiveSequentialSearch(array,right,n);
      count+=right-pos;
      cout<<"The Number Of Comparisions Are:"<<count;
      return pos;
      
   }
     if(right>=left){
        count++;
      int mid=(left +right)/2;

      if(array[mid]==n){
         cout<<"The Number Of Comparisions Are:"<<count;
         return mid;
      }
      
      if(array[mid]>n)
         return recursiveBinarySearch(array,left,mid-1,n);

      else 
         return recursiveBinarySearch(array,mid+1,right,n);
     }
     cout<<"/n The Number Of Comparisions Are:"<<count;
     return -1;
}

int main(){
   int num1,num2;
   int array[1000];
   for(int i=0;i<1000;i++){
      array[i]=rand()%1000;
   }
   sort(array,array+1000);
   cout<<"\nFind An Element Using Binary Search: ";
   cin>>num2;
   int result=recursiveBinarySearch(array,0,1000,num2);
   cout<<"\nNumber Found At Position: "<< result;

   return 0;

}
