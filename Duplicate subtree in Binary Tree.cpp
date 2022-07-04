/*
https://practice.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1/?page=1&status[]=unsolved&company[]=Google&sortBy=submissions#
Given a binary tree, find out whether it contains a duplicate sub-tree of size two or more, or not.
*/
class Solution {
  public:
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    unordered_map<string,int>m;
    string dfs(Node *root)
    {
        if(root==NULL)  return "";
        if(!root->left && !root->right)
        {
            return to_string(root->data);
        }
        string s = to_string(root->data) + dfs(root->left) + dfs(root->right);
        m[s]++;
        return s;
    }
    int dupSub(Node *root) {
         // code here
         if(root==NULL) return 0;
         m.clear();
         dfs(root);
         for(auto x : m)
         {
             if(x.second>1) return 1;
         }
         return 0;
    }
};
