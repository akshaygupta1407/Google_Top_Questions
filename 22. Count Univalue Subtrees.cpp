/*
https://www.codingninjas.com/codestudio/problems/unival-trees_697311?leftPanelTab=0

You are given a binary tree. Return the count of unival sub-trees in the given binary tree. In unival trees, all the nodes, below the root node, have the same value as the data of the root.
For example: for the binary tree, given in the following diagram, the number of unival trees is 5.
*/
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
bool dfs(BinaryTreeNode<int> *root,int &count)
{
    if(root==NULL)
        return true;
    bool a1 = true,a2 = true,a3,a4;
    if(root->left)
    {
        a1 = root->data == root->left->data;
    }
    if(root->right)
    {
        a2 = root->data == root->right->data;
    }
    a3 = dfs(root->left,count);
    a4 = dfs(root->right,count);
    bool isUni = a1 && a2 && a3 && a4;
    count+=isUni;
    return isUni;
}
int countUnivalTrees(BinaryTreeNode<int> *root)
{
    // Write your code here.
    int count = 0;
    dfs(root,count);
    return count;
}
