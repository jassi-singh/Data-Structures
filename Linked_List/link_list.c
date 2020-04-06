#include <stdio.h>
#include <stdlib.h>
struct list
{
  int num;
  struct list* next;
};
int main()
{
  struct list* head;
  struct list* ptr;
  struct list* first;
  struct list* second;
  head = (struct list*)malloc(sizeof(struct list));
  second = (struct list*)malloc(sizeof(struct list));
  first = (struct list*)malloc(sizeof(struct list));
  head->num=1;
  head->next=first;
  first->num=2;
  first->next=second;
  second->num=3;
  second->next=NULL;
  ptr=head;
  while(ptr!=NULL)
  {
    printf("%d\n",ptr->num);
    ptr=ptr->next;
  }
  return 0;
}
