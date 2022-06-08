/*
https://leetcode.com/problems/sum-root-to-leaf-numbers/
You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children.
*/
// m1
class Solution {
public:
    int sum = 0;
    void dfs(TreeNode *root,string curr)
    {
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL)
        {
            char ch = root->val + '0';
            curr+=ch;
            sum+=stoi(curr);
            return;
        }
        char ch = root->val + '0';
        dfs(root->left,curr + ch);
        dfs(root->right,curr + ch);
        curr.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        dfs(root,"");
        return sum;
    }
};
//m2
class Solution {
public:
    int dfs(TreeNode *root,int sum)
    {
        if(root==NULL)
            return 0;
        if(root->left==NULL && root->right==NULL)
        {
           return sum*10 + root->val;
        }
        return dfs(root->left,sum*10 + root->val) + dfs(root->right,sum*10 + root->val);
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root,0);
    }
};
