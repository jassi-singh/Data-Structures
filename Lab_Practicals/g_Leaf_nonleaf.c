#include <stdio.h>
#include <stdlib.h>
struct tree {
    struct tree *left;
    struct tree *right;
    char data;
}*t1;
struct tree* form(struct tree*);
void preorder(struct tree*);
int nonleaf(struct tree*);
int leaf(struct tree*);
int main()
{
    printf("Let create the tree first......\nEnter data of root node\n");
    t1=form(t1);
    printf("Tree in PREORDER-->\n");
    preorder(t1);
    printf("No. of Leaf Nodes in tree are %d and Leaf nodes are %d\n",nonleaf(t1),leaf(t1));
    return 0;
}

struct tree* form(struct tree *t)
{
    int l,r;
    t = (struct tree *)malloc(sizeof(struct tree));
    fflush(stdin);
    scanf("%c",&(t->data));
    printf("Enter 1 if node rooted at %c has left child if not 0\n",t->data);
    scanf("%d",&l);
    if(l)
    {
        printf("Enter data of left child rooted at %c\n",t->data);
        t->left=form(t->left);
    }
    else
        t->left = NULL;
    printf("Enter 1 if node rooted at %c has right child if not 0\n",t->data);
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

int nonleaf(struct tree *t)
{
    if(t&&(t->left||t->right))
        return 1 + nonleaf(t->left) + nonleaf(t->right);
    else
        return 0;
}

int leaf(struct tree *t)
{
    if(t)
        if((t->left||t->right))
            return 0 + leaf(t->left) + leaf(t->right);
        else
            return 1;
    else
        return 0;
}
