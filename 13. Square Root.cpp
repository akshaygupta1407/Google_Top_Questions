/*
https://leetcode.com/problems/sqrtx/

Given a non-negative integer x, compute and return the square root of x.

Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.

Note: You are not allowed to use any built-in exponent function or operator, such as pow(x, 0.5) or x ** 0.5.

Using Binary Search
*/
class Solution {
public:
    int mySqrt(int x) {
        long long s = 0,e = x;
        int ans = 0;
        while(s<=e)
        {
            long long mid = (s+e)/2;
            if(mid*mid==x)
                return mid;
            if(mid*mid > x)
            {
                e = mid-1;
            }
            else
            {
                ans = mid;
                s = mid+1;
            }
        }
        return ans;
    }
};
