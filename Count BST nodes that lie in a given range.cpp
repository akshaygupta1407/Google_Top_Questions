/*
https://practice.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1/?page=2&company[]=Google&sortBy=submissions#
Given a Binary Search Tree (BST) and a range l-h(inclusive), count the number of nodes in the BST that lie in the given range.

The values smaller than root go to the left side
The values greater and equal to the root go to the right side
*/
class Solution{
public:
    int ans = 0;
    void dfs(Node *root,int l,int h)
    {
        if(root==NULL)  return;
        dfs(root->left,l,h);
        if(root->data>=l && root->data<=h) ans++;
        dfs(root->right,l,h);
    }
    int getCount(Node *root, int l, int h)
    {
      // your code goes here  
        if(root==NULL)    return 0;
        dfs(root,l,h);
        return ans;
    }
};
