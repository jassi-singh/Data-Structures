#include <stdio.h>
#include <stdlib.h>
struct tree {
    struct tree *left;
    struct tree *right;
    int data;
}*t;
void form_bst(struct tree*);
int height(struct tree*);
int max(int,int);
void inorder(struct tree*);
int unbalance(struct tree*);
int main()
{
    t = (struct tree *)malloc(sizeof(struct tree));
    t->data = 1;
    t->left = NULL;
    t->right = NULL;
    form_bst(t);
    inorder(t);
    printf("%d",height(t));
}

void form_bst(struct tree *root)
{
    int a[5]= {2,3,4,5,6};
    for(int i=0;i<5;i++)
    {
        struct tree *t = root;
        struct tree *pre = root;
        while(t)
        {
            pre = t;
            if(a[i]>t->data)
                t = t->right;
            else
                t = t->left;
        }
        t = (struct tree *)malloc(sizeof(struct tree));
        if(a[i]>pre->data)
            pre->right = t;
        else
            pre->left = t;
        t->data = a[i];
        t->left = NULL;
        t->right = NULL;
    }

}

int height(struct tree *t)
{
    if(t&&(t->left||t->right))
        return 1 + max(height(t->left),height(t->right));
    else
        return 1;
}

int max(int a,int b)
{
    return a>b?a:b;
}

int unbalance(struct tree *t)
{
    int count=0;
    while(t)
    {
        if((height(t->left)-height(t->right) >= -1) && (height(t->left)-height(t->right) <= 1))
            count;
        else
            count++;
        t = t->left;
    }

    return count;
}

void inorder(struct tree *t)
{
    if(t != NULL)
    {
        if(t->left != NULL)
            inorder(t->left);

    printf("%d\n",t->data);

        if(t->right != NULL)
            inorder(t->right);
    }
}
