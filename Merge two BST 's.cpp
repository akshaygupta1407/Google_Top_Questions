/*
https://practice.geeksforgeeks.org/problems/merge-two-bst-s/1/?page=1&status[]=unsolved&company[]=Google&sortBy=submissions#
Given two BSTs, return elements of both BSTs in sorted form.


*/
class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
      vector<int>res;
      stack<Node*> s1,s2;
      while(root1 || root2 || !s1.empty() || !s2.empty())
      {
          while(root1)
          {
              s1.push(root1);
              root1 = root1->left;
          }
          while(root2)
          {
              s2.push(root2);
              root2 = root2->left;
          }
          if(s2.empty() || (!s1.empty() && s1.top()->data <= s2.top()->data))
          {
              root1 = s1.top();
              s1.pop();
              res.push_back(root1->data);
              root1 = root1->right;
          }
          else
          {
              root2 = s2.top();
              s2.pop();
              res.push_back(root2->data);
              root2 = root2->right;
          }
      }
      return res;
    }
};
