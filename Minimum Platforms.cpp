/*
https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1/?page=1&company[]=Google&sortBy=submissions#
Given arrival and departure times of all trains that reach a railway station. Find the minimum number of platforms required for the railway station so that no train is kept waiting.
Consider that all the trains arrive on the same day and leave on the same day. Arrival and departure time can never be the same for a train but we can have arrival time of one train equal to departure time of the other. At any given instance of time, same platform can not be used for both departure of a train and arrival of another train. In such cases, we need different platforms.
TC - O(n)
SC - O(1)
*/
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int platform = 1,mx = 1,i = 1,j = 0;
    	while(i<n && j<n)
    	{
    	    if(arr[i]<=dep[j])
    	    {
    	        platform++;
    	        i++;
    	    }
    	    else
    	    {
    	        platform--;
    	        j++;
    	    }
    	    mx = max(mx,platform);
    	}
    	return mx;
    }
};
