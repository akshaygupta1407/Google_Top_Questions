/*
https://practice.geeksforgeeks.org/problems/k-largest-elements4206/1/?page=1&status[]=unsolved&status[]=attempted&status[]=bookmarked&company[]=Google&sortBy=submissions#
Given an array Arr of N positive integers, find K largest elements from the array.  The output elements should be printed in decreasing order.
*/
class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	    priority_queue<int>pq;
	    for(int i=0;i<n;i++)
	    {
	        pq.push(arr[i]);
	    }
	    vector<int>res;
	    while(k--)
	    {
	        res.push_back(pq.top());
	        pq.pop();
	    }
	    return res;
	}

};
