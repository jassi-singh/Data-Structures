#include <stdio.h>
void bubbleSort(int arr[],int n);
void printArr(int arr[],int n);
void swap(int *xp, int *yp) ;
int main() 
{
    int arr[5] = {2,3,7,1,8};
    printArr(arr,5);
    bubbleSort(arr,5);
    printArr(arr,5);
}

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
void printArr(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d  ",arr[i]);
    }
    printf("\n");
}
void bubbleSort(int arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)       
  
       // Last i elements are already in place    
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
} 