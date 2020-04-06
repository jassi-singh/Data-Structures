#include <stdio.h>
#include <stdlib.h>
struct list
{
  int data;
  struct list* link;
};
void LinkList();
void printlist(struct list*);
void reverseprint(struct list*);
struct list* create();
void move();
struct list* ptr=0;
struct list* hd=0;
int main()
{
  LinkList();
  printlist(ptr);
  reverseprint(ptr);
  move();
  printlist(ptr);
  return 0;
}
//.........................Entire Linked List...................................
void LinkList()
{
  int n;
  printf("Enter no. of list you want?\n");
  scanf("%d",&n);
  printf("Enter data of lists\n");
  for(int i=0;i<n;i++)
  {
    if(i==0)
    {
    hd = create();
    ptr=hd;
    }else
    {
        ptr->link=create();
        ptr=ptr->link;
    }
  }
  ptr->link=NULL;
  ptr=hd;
}
//..........................Creating a linked list Element......................
struct list* create()
{
  struct list * form;
  form = (struct list*)malloc(sizeof(struct list));
  scanf("%d",&(form->data));
  return form;
}
//............................. Printing of list................................
void printlist(struct list*p)
{
  if(p==hd)
    printf("Your List is...........\n");
  if(p!=NULL)
  {
    printf("%d\n",p->data);
    p=p->link;
    printlist(p);
  }
}
//................Moving of any Element from one index to other.................
void move()
{
  int n,m;
  printf("Enter index to exchange.\n");
  scanf("%d %d",&n,&m);
  m=m-n;
  n = n-2;
  struct list *t1,*t2,*t3;
  if(n>-1)
  {
    while(n--)
      ptr = ptr->link;
    t1 = ptr;
    while(m--)
      ptr=ptr->link;
    t2 = ptr;
    t3 = t1->link;
    t1->link = t2->link;
    t2->link = t3;
    t3 = t1->link->link;
    t1->link->link = t2->link->link;
    t2->link->link = t3;
  }else
  {
    m--;
    while(m--)
    {
      ptr=ptr->link;
    }
    t1 = ptr->link;
    t2 = hd->link;
    hd->link = ptr->link->link;
    ptr->link = hd;
    t1->link = t2;
    hd = t1;
  }
  ptr = hd;
}
// reverse printf;
void reverseprint(struct list*p)
{
  if(p==hd)
    printf("Your List in reverse order...........\n");
  if(p!=NULL)
  {
    struct list *t = p;
    p=p->link;
    printlist(p);
    printf("%d\n",t->data);
  }
}
