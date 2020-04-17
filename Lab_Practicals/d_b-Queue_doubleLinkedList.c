#include <stdio.h>
#include <stdlib.h>
struct list
{
  struct list *pre;
  int data;
  struct list *next;
}*hd,*ptr;
void LinkList();
struct list* create();
struct list* enque(struct list*,struct list*);
struct list* deque(struct list*,struct list*);
int main()
{
  LinkList();
  struct list *f=hd,*r=hd;
  char c;
  do {
    fflush(stdin);
      printf("Enter '1' for enque, '2' for deque, '0' for stop\n");
      scanf("%c",&c);
      if(c == '1')
        r = enque(f,r);
      if(c == '2')
        f = deque(f,r);
  } while(c != '0');
}
struct list* enque(struct list* f,struct list* r)
{
  r = r->next;
  if(f==r)
  {
    printf("Queue is full\n");
    r=r->pre;
  }else
  {
    printf("Enter data for Queue\n");
    scanf("%d",&(r->data));
  }
  return r;
}
struct list* deque(struct list* f,struct list* r)
{
  if(f==r)
  {
    printf("Queue is empty\n");
  }else
  {
       f = f->next;
       printf("Data is %d\n",f->data);
  }
  return f;
}

void LinkList()
{
  int n;
  printf("Enter no. empty box in Queue\n");
  scanf("%d",&n);
  for(int i=0;i<=n;i++)
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
  hd->pre=ptr;
  ptr->next=hd;
  ptr=hd;
}
//........................create double_link list fn........................//
struct list* create()
{
  struct list * form;
  form = (struct list*)malloc(sizeof(struct list));
  form->pre = ptr;
  return form;
}
