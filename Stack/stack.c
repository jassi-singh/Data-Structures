#include <stdio.h>
#include <stdlib.h>
struct stack
{
  struct stack *pre;
  int data;
}*top;
void push(int);
void pop();
int main()
{
  printf("Initial no. of elements in stack\n");
  int n;
  char str;
  top = NULL;
  scanf("%d",&n);
  push(n);
  do
  {
    printf("Enter 'X' to push & 'O' to pop the elements\n");
    fflush(stdin);
    scanf("%c",&str);
    if(str == 'X')
      push(1);
    else if(str == 'O')
      pop();
  }while(top);
}

void push(int n)
{
  if(n)
  {
    n--;
    struct stack *new;
    new = (struct stack *)malloc(sizeof(struct stack));
    new->pre = top;
    printf("Enter data\n");
    scanf("%d",&(new->data));
    top = new;
    push(n);
  }
}

void pop()
{
  printf("%d \n",top->data);
  top = top->pre;
}
