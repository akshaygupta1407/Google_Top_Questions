/*
Given a binary tree, connect the nodes that are at same level. You'll be given an addition nextRight pointer for the same.

Initially, all the nextRight pointers point to garbage values. Your function should set these pointers to point next right for each node.

https://practice.geeksforgeeks.org/problems/connect-nodes-at-same-level/1/?page=2&company[]=Google&sortBy=submissions#
*/
class Solution
{
    public:
    //Function to connect nodes at same level.
    void connect(Node *root)
    {
       // Your Code Here
       queue<Node*>q;
       q.push(root);
       while(!q.empty())
       {
           Node *dummy = new Node();
           int size = q.size();
           while(size--)
           {
               Node* node = q.front();
               q.pop();
               if(node->left)
               {
                   q.push(node->left);
                   dummy->nextRight = node->left;
                   dummy = dummy->nextRight;
               }
               if(node->right)
               {
                   q.push(node->right);
                   dummy->nextRight = node->right;
                   dummy = dummy->nextRight;
               }
           }
       }
    }    
      
};
