/*
  https://leetcode.com/problems/valid-parentheses/
  https://www.codingninjas.com/codestudio/problems/valid-parenthesis_795104?leftPanelTab=0
  
  Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto x : s)
        {
            switch(x)
            {
                case '(':
                case '[':
                case '{': st.push(x);
                          break;
                case ')': if(!st.empty() && st.top()=='(')
                            st.pop();
                          else
                              return false;
                            break;
                case '}': if(!st.empty() && st.top()=='{')
                            st.pop();
                          else
                              return false;
                            break;
                case ']': if(!st.empty() && st.top()=='[')
                            st.pop();
                          else
                              return false;
                            break;
                    
            }
        }
        if(st.empty())
            return true;
        return false;
    }
};
