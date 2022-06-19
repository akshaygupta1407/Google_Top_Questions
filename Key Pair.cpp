/*
https://practice.geeksforgeeks.org/problems/key-pair5616/1/?page=2&company[]=Google&sortBy=submissions#
Given an array Arr of N positive integers and another number X. Determine whether or not there exist two elements in Arr whose sum is exactly X.
*/
class Solution{
public:	
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    // code here
	    unordered_map<int,int>mpp;
	    for(int i=0;i<n;i++)
	    {
	        int target = x - arr[i];
	        if(mpp.find(target)!=mpp.end()) return true;
	        mpp[arr[i]]++;
	    }
	    return false;
	}
};
