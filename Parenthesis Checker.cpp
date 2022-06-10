/*
Given an expression string x. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
For example, the function should return 'true' for exp = “[()]{}{[()()]()}” and 'false' for exp = “[(])”.
https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1/?page=1&company[]=Google&sortBy=submissions#
*/
class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char>s;
        for(auto ch : x)
        {
            switch(ch)
            {
                case '(':
                case '{':
                case '[': s.push(ch);
                          break;
                case ')' : if(!s.empty() && s.top()=='(')
                            {
                                s.pop();
                            }
                            else
                            return false;
                            break;
                case '}' : if(!s.empty() && s.top()=='{')
                            {
                                s.pop();
                            }
                            else
                            return false;
                            break;
                case ']' : if(!s.empty() && s.top()=='[')
                            {
                                s.pop();
                            }
                            else
                            return false;
                            break;
            }
        }
        if(s.empty())
        return true;
        return false;
    }

};
