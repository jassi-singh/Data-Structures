#include <stdio.h>
#include <stdlib.h>
struct list
{
  int data;
  struct list* link;
};
void LinkList();
void printlist(struct list*);
struct list* create();
void delete();
struct list* ptr=0;
struct list* hd=0;
int main()
{
  LinkList();
  printlist(ptr);
  delete();
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

//...................Deletion of any Element from any Index.....................
void delete()
{
  printf("Enter index for Deletion\n");
  int n;
  scanf("%d",&n);
  n=n-2;
  if(n!=-1)
  {
    while(n--)
    {
      ptr=ptr->link;
    }
    struct list *t = ptr->link;
    ptr->link = ptr->link->link;
    free(t);
  }else
  {
    hd = hd->link;
    free(ptr);
  }
  ptr = hd;
}
