#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct tree {
    struct tree *left;
    struct tree *right;
    char data[20];
}*t;
void form_bst(struct tree*,char a[][20]);
void preorder(struct tree*);
void insert(struct tree*,char val[20]);
int main()
{
    char a[5][20]={"Arthi", "Christy", "Dorothy", "Fraser", "Eliza"};
    t = (struct tree *)malloc(sizeof(struct tree));
    strcpy(t->data,a[0]);
    t->left = NULL;
    t->right = NULL;
    form_bst(t,a);
    preorder(t);
    printf("\n");
    insert(t,"David");
    preorder(t);
}

void form_bst(struct tree *root,char a[][20])
{
    for(int i=1;i<5;i++)
    {
        struct tree *t = root;
        struct tree *pre = root;
        while(t)
        {
            pre = t;
            if(strcmp(a[i],t->data)==1)
                t = t->right;
            else
                t = t->left;
        }
        t = (struct tree *)malloc(sizeof(struct tree));
        if(strcmp(a[i],pre->data)==1)
            pre->right = t;
        else
            pre->left = t;
        strcpy(t->data,a[i]);
        t->left = NULL;
        t->right = NULL;
    }

}

void insert(struct tree* t,char val[20])
{
    struct tree * pre = t;
    while(t)
        {
            pre = t;
            if(strcmp(val,t->data)==1)
                t = t->right;
            else
                t = t->left;
        }
        t = (struct tree *)malloc(sizeof(struct tree));
        if(strcmp(val,pre->data)==1)
            pre->right = t;
        else
            pre->left = t;
        strcpy(t->data,val);
        t->left = NULL;
        t->right = NULL;
}

void preorder(struct tree *t)
{
    if(t)
    {

        
        if(t->left != NULL)
            preorder(t->left);

        printf("%s  ",t->data);

        if(t->right != NULL)
            preorder(t->right);
    }
}
