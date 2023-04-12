#include<stdio.h>
#include<stdlib.h>
typedef int DType;
typedef struct TreeNode
{
    DType min;
    DType max;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;
typedef TreeNode* Tree;
void Insert(Tree root,DType min,DType max)
{
    if(min>root->max)
    {
        if(root->right==NULL)
        {
            root->right=(Tree)malloc(sizeof(TreeNode));
            root->right->min=min;
            root->right->max=max;
            root->right->left=NULL;
            root->right->right=NULL;
        }
        else
        {
            Insert(root->right,min,max);
        }
    }
    else if(max<root->min)
    {
        if(root->left==NULL)
        {
            root->left=(Tree)malloc(sizeof(TreeNode));
            root->left->min=min;
            root->left->max=max;
            root->left->left=NULL;
            root->left->right=NULL;
        }
        else
        {
            Insert(root->left,min,max);
        }
    }
}
void Print_Tree(Tree root)
{
    if(root==NULL)
    {
        return;
    }
    Print_Tree(root->left);
    printf("%d-%d\n",root->min,root->max);
    Print_Tree(root->right);
}
Tree FindNode(Tree root,int key)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(key<root->min)
    {
        return FindNode(root->left,key);
    }
    else if(key>root->max)
    {
        return FindNode(root->right,key);
    }
    else
    {
        return root;
    }
}
int main()
{
    Tree root=(Tree)malloc(sizeof(TreeNode));
    root->left=NULL;
    root->right=NULL;
    int n;
    int min,max;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&min,&max);
        if(i==0)
        {
            root->min=min;
            root->max=max;
        }
        else
        {
            Insert(root,min,max);
        }
    }
    Print_Tree(root);
    int key;
    scanf("%d",&key);
    Tree node=FindNode(root,key);
    if(node)
    {
        printf("Node with range %d-%d found\n",node->min,node->max);
    }
    else
    {
        printf("No node with this element in range found\n");
    }
    return 0;
}