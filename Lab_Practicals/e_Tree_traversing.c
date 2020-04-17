#include <stdio.h>
#include <stdlib.h>
struct tree {
    struct tree *left;
    struct tree *right;
    char data;
}*t1;
struct tree* form(struct tree*);
void preorder(struct tree*);
void inorder(struct tree*);
void postorder(struct tree*);
int main()
{
    printf("Let create the tree first......\nEnter data of root node\n");
    t1=form(t1);
    printf("PREORDER-->\n");
    preorder(t1);
    printf("INORDER-->\n");
    inorder(t1);
    printf("POSTORDER-->\n");
    postorder(t1);
    return 0;
}

struct tree* form(struct tree *t)
{
    int l,r;
    t = (struct tree *)malloc(sizeof(struct tree));
    fflush(stdin);
    scanf("%c",&(t->data));
    printf("Enter 1 if node rooted at %c has left child else 0\n",t->data);
    scanf("%d",&l);
    if(l)
    {
        printf("Enter data of left child rooted at %c\n",t->data);
        t->left=form(t->left);
    }
    else
        t->left = NULL;
    printf("Enter 1 if node rooted at %c has right child else 0\n",t->data);
    scanf("%d",&r);
    if(r)
    {
        printf("Enter data of right child rooted at %c\n",t->data);
        t->right=form(t->right);
    }
    else
        t->right = NULL;
    return t;
}

void preorder(struct tree *t)
{
    if(t != NULL)
    {
        printf("%c\n",t->data);
        if(t->left != NULL)
            preorder(t->left);

        if(t->right != NULL)
            preorder(t->right);
    }
}

void inorder(struct tree *t)
{
    if(t != NULL)
    {
        if(t->left != NULL)
            inorder(t->left);

    printf("%c\n",t->data);

        if(t->right != NULL)
            inorder(t->right);
    }
}

void postorder(struct tree *t)
{
    if(t != NULL)
    {
        if(t->left != NULL)
            postorder(t->left);

        if(t->right != NULL)
            postorder(t->right);

        printf("%c\n",t->data);
    }
}
