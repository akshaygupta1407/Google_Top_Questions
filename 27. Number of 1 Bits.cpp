/*
https://leetcode.com/problems/number-of-1-bits/
https://www.codingninjas.com/codestudio/problems/set-bits_1164179?leftPanelTab=0

Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).
*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n)
        {
            n = n&(n-1);
            count++;
        }
        return count;
    }
};
