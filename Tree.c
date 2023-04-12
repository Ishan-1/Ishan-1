/* Some info about trees
Traversals:
Pre-order: P->L->R
In-order: L->P->R
Post-order: L->R->P
Level-order: Each levels*/
#include<stdio.h>
#include<stdlib.h>
typedef int DType;
typedef struct TreeNode
{
    DType data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;
typedef TreeNode* Tree;
void Insert(Tree root,DType data)
{
    if(data>root->data)
    {
        if(root->right==NULL)
        {
            root->right=(Tree)malloc(sizeof(TreeNode));
            root->right->data=data;
            root->right->left=NULL;
            root->right->right=NULL;
        }
        else
        {
            Insert(root->right,data);
        }
    }
    else
    {
        if(root->left==NULL)
        {
            root->left=(Tree)malloc(sizeof(TreeNode));
            root->left->data=data;
            root->left->left=NULL;
            root->left->right=NULL;
        }
        else
        {
            Insert(root->left,data);
        }
    }
}
void Print_Inorder(Tree root)
{
    if(root==NULL)
    {
        return;
    }
    Print_Inorder(root->left);
    printf("%d ",root->data);
    Print_Inorder(root->right);
}
int get_depth(Tree root)
{
   if(root==NULL)
   {
    return -1;
   }
   int d_left=get_depth(root->left);
   int d_right=get_depth(root->right);
   return 1+((d_left>d_right)?d_left:d_right);
}
void Mirror_Insert(Tree root,DType data)
{
    if(data<root->data)
    {
        if(root->right==NULL)
        {
            root->right=(Tree)malloc(sizeof(TreeNode));
            root->right->data=data;
            root->right->left=NULL;
            root->right->right=NULL;
        }
        else
        {
            Mirror_Insert(root->right,data);
        }
    }
    else
    {
        if(root->left==NULL)
        {
            root->left=(Tree)malloc(sizeof(TreeNode));
            root->left->data=data;
            root->left->left=NULL;
            root->left->right=NULL;
        }
        else
        {
            Mirror_Insert(root->left,data);
        }
    }
}
void Mirror_Pre(Tree root,Tree mirror)
{
    if(root==NULL)
    {
        return;
    }
    Mirror_Insert(mirror,root->data);
    Mirror_Pre(root->left,mirror);
    Mirror_Pre(root->right,mirror);
}
//Uses pre-order
Tree Mirror_Tree(Tree root)
{
    Tree mirror=(Tree)malloc(sizeof(TreeNode));
    mirror->data=root->data;
    mirror->left=NULL;
    mirror->right=NULL;
    Mirror_Pre(root->left,mirror);
    Mirror_Pre(root->right,mirror);
    return mirror;
}
//Uses post-order
void Mirror_Rec(Tree root)
{
    if(root==NULL)
    {
        return;
    }
    Mirror_Rec(root->left);
    Mirror_Rec(root->right);
    Tree temp=root->left;
    root->left=root->right;
    root->right=temp;
    return;
}
//Same structure and value
int completelyEqual(Tree root1,Tree root2)
{
    if((root1==NULL && root2!=NULL)||(root1!=NULL && root2==NULL))
    {
        return 0;
    }
    else if(root1==NULL && root2==NULL)
    {
        return 1;
    }
    int eq_left=completelyEqual(root1->left,root2->left);
    int eq_right=completelyEqual(root1->right,root2->right);
    if(!eq_left || !eq_right || root1->data!=root2->data)
    {
        return 0;
    }
    return 1;
}
int structurallyEqual(Tree root1,Tree root2)
{
    if((root1==NULL && root2!=NULL)||(root1!=NULL && root2==NULL))
    {
        return 0;
    }
    else if(root1==NULL && root2==NULL)
    {
        return 1;
    }
    int eq_left=structurallyEqual(root1->left,root2->left);
    int eq_right=structurallyEqual(root1->right,root2->right);
    if(!eq_left || !eq_right)
    {
        return 0;
    }
    return 1;
}
int main()
{
    Tree root=(Tree)malloc(sizeof(TreeNode));
    Tree root1=(Tree)malloc(sizeof(TreeNode));
    root->left=NULL;
    root1->left=NULL;
    root->right=NULL;
    root1->right=NULL;
    int n;
    scanf("%d",&n);
    int e;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&e);
        if(i==0)
        {
            root->data=e;
        }
        else
        {
            Insert(root,e);
        }
    }
    Print_Inorder(root);
    printf("\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&e);
        if(i==0)
        {
            root1->data=e;
        }
        else
        {
            Insert(root1,e);
        }
    }
    Print_Inorder(root1);
    printf("\n");
    if(completelyEqual(root,root1))
    {
        printf("Completely equal\n");
    }
    else if(structurallyEqual(root,root1))
    {
        printf("Structurally equal\n");
    }
    else
    {
        printf("Completely unequal\n");
    }
    return 0;
}