#include <stdio.h>
#include <stdlib.h>
struct list
{
  int num;
  struct list* next;
};
int main()
{
  struct list l1,l2,l3;
  (&l1)->num=1;
  l1.next=&l2;
  l2.num=2;
  l2.next=&l3;
  l3.num=3;
  l3.next=NULL;
  struct list* head;
  struct list* ptr;
  head=&l1;
  ptr=head;
  while(ptr->next)
  {
    printf("%d\n",ptr->num);
    ptr=ptr->next;
  }
  printf("%d\n",ptr->num);
  struct list l4;
  l4.num=5;
  l4.next=NULL;
  ptr->next=&l4;
  ptr=head;
  while(ptr!=NULL)
  {
    printf("%d\n",ptr->num);
    ptr=ptr->next;
  }
  return 0;
}
