/*
https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1/?page=2&company[]=Google&sortBy=submissions#
Given a BST and an integer K. Find the Kth Smallest element in the BST. 
*/
class Solution {
  public:
    // Return the Kth smallest element in the given BST
    int m=0,ans = -1;
    void dfs(Node *root)
    {
        if(root==NULL)  return;
        dfs(root->left);
        m--;
        if(m==0)
        {
            ans = root->data;
        }
        dfs(root->right);
    }
    int KthSmallestElement(Node *root, int K) {
        // add code here.
        if(root==NULL)  return 0;
        m = K;
        dfs(root);
        return ans;
    }
};
