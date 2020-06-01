#include <stdio.h>
void insertion_sort(int [],int);
int main()
{
    int n;
    printf("Enter Size of Array\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter Data of Array\n");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    insertion_sort(arr,n);
    for(int i=0;i<n;i++)
        printf("%d  ",arr[i]);
}

void insertion_sort(int arr[],int n)
{
    printf("Sorted Array is\n");
    for(int i=0;i<n;i++)
    {
        int temp = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}
