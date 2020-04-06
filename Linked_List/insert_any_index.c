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
void newList();
struct list* ptr=0;
struct list* hd=0;
int main()
{
  LinkList();
  printlist(ptr);
  newList();
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
void newList()
{
  printf("Enter index after which Insertion is Done\n");
  int n;
  scanf("%d",&n);
  printf("Enter new List Element\n");
  struct list* new;
  new=create();
  for(int i=1;i<n;i++)
  {
    ptr=ptr->link;
  }
  if(n>0)
  {
    struct list* temp=ptr->link;
    ptr->link=new;
    new->link=temp;
  }else
  {
    new->link=hd;
    hd=new;
  }
  ptr = hd;
}
