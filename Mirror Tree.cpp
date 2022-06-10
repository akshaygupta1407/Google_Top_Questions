/*
https://practice.geeksforgeeks.org/problems/mirror-tree/1/?page=1&company[]=Google&sortBy=submissions

Given a Binary Tree, convert it into its mirror.
*/
class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        // code here
        if(node==NULL)
        return;
        swap(node->left,node->right);
        mirror(node->left);
        mirror(node->right);
    }
};
