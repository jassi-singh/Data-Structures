#include <stdio.h>
#include <stdlib.h>
int enque(int arr[],int n,int f,int r);
int deque(int arr[],int n,int f,int r);
int main()
{
  int n;
  int f=0,r=0;
  printf("Enter no. of Queue\n");
  scanf("%d",&n);
  int arr[n+1];
  char c;
  do {
    fflush(stdin);
      printf("Enter 'E' for enque, 'D' for deque, 'O' for stop\n");
      scanf("%c",&c);
      if(c == 'E')
        r = enque(arr,n,f,r);
      if(c == 'D')
        f = deque(arr,n,f,r);
  } while(c != 'O');
}
int enque(int arr[],int n,int f,int r)
{
  r = (r+1)%n;
  if(f==r)
  {
    printf("Queue is full\n");
    if(r==0)
    {
      r = n - 1;
    }else
    {
      r--;
    }
  }else
  {
    printf("Enter data for Queue\n");
    scanf("%d",&arr[r]);
  }

  return r;
}
int deque(int arr[],int n,int f,int r)
{
  if(f==r)
  {
    printf("Queue is empty\n");
  }else
  {
       f = (f+1)%n;
       printf("%d\n",arr[f]);
  }
  return f;
}
