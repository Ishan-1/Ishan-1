#include<stdio.h>
#include<stdlib.h>
typedef struct AVLTreeNode
{
    int data;
    struct AVLTreeNode* left;
    struct AVLTreeNode* right;
    int height;
} TreeNode;
typedef TreeNode* AVLTree;
int getHeight(TreeNode* n)
{
    if(n==NULL)
    {
        return -1;
    }
    return n->height;
}
int maxHeight(TreeNode* a,TreeNode* b)
{
    return (getHeight(a)>getHeight(b))?getHeight(a):getHeight(b);
}
TreeNode* LeftRotate(TreeNode* root)
{
    TreeNode* newRoot=root->left;
    TreeNode* detached=newRoot->right;
    root->left=detached;
    newRoot->right=root;
    root->height=maxHeight(root->left,root->right)+1;
    newRoot->height=maxHeight(newRoot->left,newRoot->right)+1;
    return newRoot;
}
TreeNode* RightRotate(TreeNode* root)
{
    TreeNode* newRoot=root->right;
    TreeNode* detached=newRoot->left;
    root->right=detached;
    newRoot->left=root;
    root->height=maxHeight(root->left,root->right)+1;
    newRoot->height=maxHeight(newRoot->left,newRoot->right)+1;
    return newRoot;
}
TreeNode* RightAndLeftRotate(TreeNode* root)
{
    root->left=RightRotate(root->left);
    root=LeftRotate(root);
    return root;
}
TreeNode* LeftAndRightRotate(TreeNode* root)
{
    root->right=LeftRotate(root->right);
    root=RightRotate(root);
    return root;
}
TreeNode* insert(AVLTree root,int val)
{
    if(root==NULL)
    {
        TreeNode* NewNode=(TreeNode*)malloc(sizeof(TreeNode));
        NewNode->data=val;
        NewNode->left=NULL;
        NewNode->right=NULL;
        NewNode->height=0;
        return NewNode;    
    }
    if(root->data<val)
    {
        root->right=insert(root->right,val);
        if(getHeight(root->right)-getHeight(root->left)==2)
        {
            if(getHeight(root->right->right)>getHeight(root->right->left))
            {
                root=RightRotate(root);
            }
            else if(getHeight(root->right->right)<getHeight(root->right->left))
            {
                root=LeftAndRightRotate(root);
            }
        }
    }
    else
    {
        root->left=insert(root->left,val);
        if(getHeight(root->left)-getHeight(root->right)==2)
        {
            if(getHeight(root->left->left)>getHeight(root->left->right))
            {
                root=LeftRotate(root);
            }
            else if(getHeight(root->left->left)<getHeight(root->left->right))
            {
                root=RightAndLeftRotate(root);
            }
        }
    }
    root->height=maxHeight(root->left,root->right)+1;

    return root;
}