#include <stdio.h>
#include <stdlib.h>
struct list
{
  struct list *pre;
  int data;
  struct list *next;
};
void LinkList();
void delete();
void printlist(struct list*);
struct list* create();
struct list *hd,*ptr;
int main()
{
  LinkList();
  printlist(ptr);
  delete();
  printlist(ptr);
}


//.........................Entire Linked List...................................
void LinkList()
{
  int n;
  printf("Enter no. of elements in list you want?\n");
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

//...................Deletion of any Element....................................
void delete()
{
  printf("Enter Element for Deletion\n");
  int n;
  scanf("%d",&n);
  if(n!=hd->data)
  {
    while(ptr->next!=NULL&&n!=ptr->next->data)
    {
      ptr=ptr->next;
    }
    if(ptr->next!=NULL)
    {
        struct list *t = ptr->next;
        ptr->next = ptr->next->next;
        if(t->next!=NULL)
        ptr->next->pre=ptr;
        free(t);
    }else
        printf("There is no %d in Linked List\n",n);
  }else
  {
    hd = hd->next;
    hd->pre=NULL;
    free(ptr);
  }
  ptr = hd;
}
