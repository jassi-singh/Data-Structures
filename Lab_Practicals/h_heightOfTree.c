#include <stdio.h>
#include <stdlib.h>
struct tree {
    struct tree *left;
    struct tree *right;
    int data;
}*t1;
struct tree* form(struct tree*);
void inorder(struct tree*);
int height(struct tree*);
int max(int,int);
int main()
{
    printf("Let create the tree first......\nEnter data of root node\n");
    t1=form(t1);
    printf("INORDER-->\n");
    inorder(t1);
    printf("Height of Tree is %d\n",height(t1));
    return 0;
}

struct tree* form(struct tree *t)
{
    int l,r;
    t = (struct tree *)malloc(sizeof(struct tree));
    scanf("%d",&(t->data));
    printf("Enter 1 if node rooted at %d has left child else 0\n",t->data);
    scanf("%d",&l);
    if(l)
    {
        printf("Enter data of left child rooted at %d\n",t->data);
        t->left=form(t->left);
    }
    else
        t->left = NULL;
    printf("Enter 1 if node rooted at %d has right child else 0\n",t->data);
    scanf("%d",&r);
    if(r)
    {
        printf("Enter data of right child rooted at %d\n",t->data);
        t->right=form(t->right);
    }
    else
        t->right = NULL;
    return t;
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

int height(struct tree *t)
{
    if(t&&(t->left||t->right))
        return 1 + max(height(t->left),height(t->right));
    else
        return 0;
}

int max(int a,int b)
{
    return a>b?a:b;
}
