#include <stdio.h>
#include <stdlib.h>
struct tree {
    struct tree *left;
    struct tree *right;
    int data;
}*t1;
void form_bst(struct tree*);
void inorder(struct tree*);
int height(struct tree*);
int max(int,int);
int main()
{
    printf("Let create the tree first......\nEnter data of root node\n");
    t1 = (struct tree *)malloc(sizeof(struct tree));
    scanf("%d",&(t1->data));
    t1->left = NULL;
    t1->right = NULL;
    form_bst(t1);

    printf("INORDER-->\n");
    inorder(t1);
    printf("Height of Tree is %d\n",height(t1));
    return 0;
}

void form_bst(struct tree *root)
{
    int n;
    printf("Enter number of elements in BST\n");
    scanf("%d",&n);
    printf("Enter Elements\n");
    for(int i=0;i<n;i++)
    {
        int d;
        scanf("%d",&d);
        struct tree *t = root;
        struct tree *pre = root;
        while(t)
        {
            pre = t;
            if(d>t->data)
                t = t->right;
            else
                t = t->left;
        }
        t = (struct tree *)malloc(sizeof(struct tree));
        if(d>pre->data)
            pre->right = t;
        else
            pre->left = t;
        t->data = d;
        t->left = NULL;
        t->right = NULL;
    }

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
