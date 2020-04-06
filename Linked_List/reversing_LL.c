#include <stdio.h>
#include <stdlib.h>
struct list
{
  int data;
  struct list* link;
};
void LinkList(int);
void printlist(struct list*);
void reverse(struct list *,struct list *,struct list *);
void rvrsItration(struct list *pre,struct list *curr,struct list *nxt,int n);
struct list* create();
struct list* ptr=0;
struct list* hd=0;
int main()
{
  int n;
  printf("Enter no. of list you want?\n");
  scanf("%d",&n);
  LinkList(n);
  printlist(hd);
  reverse(NULL,hd,hd->link);
  printlist(hd);
  rvrsItration(NULL,hd,hd->link,n);
  printlist(hd);
  return 0;
}
//.........................Entire Linked List...................................
void LinkList(int n)
{
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
// reversing order of linked list through recurrsion
void reverse(struct list *pre,struct list *curr,struct list *nxt)
{
  curr->link = pre;
  if(nxt!=NULL)
  {
    pre = curr;
    curr = nxt;
    nxt = nxt->link;
    reverse(pre,curr,nxt);
  }else
    hd = curr;
}
// reversing order of LinkList by itteration
void rvrsItration(struct list *pre,struct list *curr,struct list *nxt,int n)
{
  n--;
  while(n--)
  {
    curr->link = pre;
    pre = curr;
    curr = nxt;
    nxt = nxt->link;
  }
  curr->link = pre;
  hd=curr;
}
