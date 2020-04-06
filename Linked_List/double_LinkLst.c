#include <stdio.h>
#include <stdlib.h>
struct list
{
  struct list *pre;
  int data;
  struct list *next;
};
void LinkList();
void insert();
void traverse(int);
void printlist(struct list*);
struct list* create();
struct list *hd,*ptr;
int main()
{
  LinkList();
  printlist(ptr);
  insert();
  printlist(ptr);
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
        ptr->next=create();
        ptr=ptr->next;
    }
  }
  ptr->next=NULL;
  ptr=hd;
}
//........................create double_link list fn........................//
struct list* create()
{
  struct list * form;
  form = (struct list*)malloc(sizeof(struct list));
  scanf("%d",&(form->data));
  form->pre = ptr;
  return form;
}
//.............printing in list .............................///
void printlist(struct list* ptr)
{
  printf("Your list going fwd..\n");
  while(ptr->next!=NULL)
  {
    printf("%d ",ptr->data);
    ptr = ptr->next;
  }
  printf("%d\n",ptr->data);
  printf("Your list going bwd..\n");
  while(ptr->pre)
  {
    printf("%d ",ptr->data);
    ptr = ptr->pre;
  }
  printf("%d\n",ptr->data);
}
// ..............traverse in list..........................\//
void traverse(int n)
{
  if(n>0)
  {
    ptr=ptr->next;
    traverse(n-1);
  }
}
//....................inserting any Element..................................//
void insert()
{
  printf("Enter after which index to insert\n");
  int n;
  scanf("%d",&n);
  traverse(n-1);
  printf("Enter data of lists\n");
  struct list *new = create();
  if(n)
  {
    ptr->next->pre = new;
    new->next=ptr->next;
    ptr->next = new;
  }else
  {
    new->pre = NULL;
    new->next = hd;
    hd->pre = new;
    hd = new;
  }
  ptr = hd;
}
