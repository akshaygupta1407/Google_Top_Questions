/*
Given a non-negative number represented as a list of digits, add 1 to the number (increment the number represented by the digits). The digits are stored such that the most significant digit is first element of array.
https://practice.geeksforgeeks.org/problems/plus-one/1/?page=1&difficulty[]=0&status[]=unsolved&status[]=attempted&status[]=bookmarked&company[]=Google&sortBy=submissions#
*/
class Solution {
  public:
    vector<int> increment(vector<int> digits ,int N) {
        // code here
        bool carry = true;
        
        for(int i=N-1; i >= 0 && carry; i--) {
            carry = (++digits[i]%=10) == 0;
        }

        if(carry) {
            digits.insert(digits.begin(), 1);
        }
    
        return digits;
    }
};
