/*
Given a binary tree, the task is to find the maximum path sum. The path may start and end at any node in the tree.
https://practice.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1/?page=1&status[]=unsolved&company[]=Google&sortBy=submissions
*/
class Solution {
  public:
    //Function to return maximum path sum from any node in a tree.
    int mx = INT_MIN;
    int helper(Node *root)
    {
        if(root==NULL)  return 0;
        int left = max(0,helper(root->left));
        int right = max(0,helper(root->right));
        mx = max(mx,left+right+root->data);
        return max(left,right)+root->data;
    }
    int findMaxSum(Node* root)
    {
        // Your code goes here
        helper(root);
        return mx;
    }
};
