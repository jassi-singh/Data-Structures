#include <stdio.h>
void selection_sort(int [],int);
void swap(int [],int,int);
int main()
{
    int n;
    printf("Enter Size of Array\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter Data of Array\n");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    selection_sort(arr,n);
    for(int i=0;i<n;i++)
        printf("%d  ",arr[i]);
}

void selection_sort(int arr[],int n)
{
    printf("Sorted Array is\n");
    for(int i=0;i<n;i++)
    {
        int min = i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[min]>arr[j])
                min = j;
        }
        swap(arr,i,min);
    }
}

void swap(int arr[],int i,int j)
{
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}
