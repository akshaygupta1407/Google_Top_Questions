/*
https://practice.geeksforgeeks.org/problems/stock-buy-and-sell-1587115621/1/?page=2&company[]=Google&sortBy=submissions#

The cost of stock on each day is given in an array A[] of size N. Find all the days on which you buy and sell the stock so that in between those days your profit is maximum.
Note: There may be multiple possible solutions. Return any one of them. Any correct solution will result in an output of 1, whereas wrong solutions will result in an output of 0.
Find Local Maximum and LocaL minimum
*/
class Solution{
public:
    //Function to find the days of buying and selling stock for max profit.
    vector<vector<int> > stockBuySell(vector<int> price, int n){
        // code here
        vector<vector<int>>res;
        if(n==1)
        {
            return res;
        }
        int i = 0;
        while(i<n-1)
        {
            while((i<n-1) && (price[i+1]<=price[i]))
            {
                i++;
            }
            if(i==n-1)
            {
                break;
            }
            int buy = i;
            i++;
            while(i<n && price[i] >= price[i-1])
            {
                i++;
            }
            int sell = i-1;
            vector<int>curr = {buy,sell};
            res.push_back(curr);
        }
        return res;
    }
};
