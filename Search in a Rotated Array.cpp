/*
https://practice.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1/?page=1&difficulty[]=0&status[]=unsolved&status[]=attempted&status[]=bookmarked&company[]=Google&sortBy=submissions
Given a sorted and rotated array A of N distinct elements which is rotated at some point, and given an element key. The task is to find the index of the given element key in the array A.
*/
class Solution{
    public:
    int search(int A[], int l, int h, int key){
    //complete the function here
        while(l<=h)
        {
            int mid = l + (h-l)/2;
            if(key==A[mid])  return mid;
            if(A[l] <= A[mid])
            {
                if(A[l]<=key && key<=A[mid])
                {
                    h = mid-1;
                }
                else
                {
                    l = mid+1;
                }
            }
            else
            {
                if(A[mid]<=key && key<=A[h])
                {
                    l = mid+1;
                }
                else
                {
                    h = mid-1;
                }
            }
        }
        return -1;
    }
};
