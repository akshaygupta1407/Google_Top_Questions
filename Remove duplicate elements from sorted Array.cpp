/*
https://practice.geeksforgeeks.org/problems/remove-duplicate-elements-from-sorted-array/1/?page=1&company[]=Google&sortBy=submissions#
Given a sorted array A[] of size N, delete all the duplicates elements from A[].
Note: Don't use set or HashMap to solve the problem.


*/
class Solution{
public:
    int remove_duplicate(int a[],int n){
        // code here
        if(n==0)
        return 0;
        
        int i=0;
        for(int j=1;j<n;j++)
        {
            if(a[i]!=a[j])
            {
                i++;
                a[i] = a[j];
            }
        }
        return i+1;
    }
};
