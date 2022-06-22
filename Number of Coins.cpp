/*
https://practice.geeksforgeeks.org/problems/number-of-coins1824/1/?page=2&company[]=Google&sortBy=submissions#
Given a value V and array coins[] of size M, the task is to make the change for V cents, given that you have an infinite supply of each of coins{coins1, coins2, ..., coinsm} valued coins. Find the minimum number of coins to make the change. If not possible to make change then return -1.
*/
class Solution{

	public:
	unordered_map<int,int>m;
    int coin(int coins[],int amount,int M)
    {
        if(amount==0)
            return 0;
        if(amount<0)    return -1;
        if(m[amount])   return m[amount];
        int mn = INT_MAX;
        for(int i=0;i<M;i++)
        {
            int c = coins[i];
            int res = coin(coins,amount-c,M);
            if(res>=0 && res<mn)
            {
                mn = res+1;
            }
        }
        return m[amount] = mn==INT_MAX ? -1 : mn;
    }
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    return coin(coins,V,M);
	} 
	  
};
