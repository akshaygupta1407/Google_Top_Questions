/*
https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1/?page=1&company[]=Google&sortBy=submissions#
Given an array Arr[] that contains N integers (may be positive, negative or zero). Find the product of the maximum product subarray.
*/
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    long long mxProduct = arr[0],mxValue = arr[0],mnValue = arr[0];
	    for(int i=1;i<n;i++)
	    {
	        if(arr[i]<0)
	            swap(mxValue,mnValue);
	        mxValue = max((long long)arr[i],mxValue*arr[i]);
	        mnValue = min((long long)arr[i],mnValue*arr[i]);
	        mxProduct = max(mxProduct,mxValue);
	    }
	    return mxProduct;
	}
};
