/*
https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1/?page=1&company[]=Google&sortBy=submissions#

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
*/
class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
       if(root->data == n1 || root->data == n2)   return root;
       if(root->left==NULL && root->right==NULL)    return NULL;
       Node *l = NULL, *r = NULL;
       if(root->left)
       {
           l = lca(root->left,n1,n2);
       }
       if(root->right)
       {
           r = lca(root->right,n1,n2);
       }
       if(l&&r)
            return root;
       return l==NULL ? r : l;
    }
};
