/*
https://www.codingninjas.com/codestudio/problems/search-in-rotated-sorted-array_1082554?leftPanelTab=0

Problem Statement
You have been given a sorted array/list ARR consisting of ‘N’ elements. You are also given an integer ‘K’.
Now the array is rotated at some pivot point unknown to you. For example, if ARR = [ 1, 3, 5, 7, 8]. Then after rotating ARR at index 3, the array will be ARR = [7, 8, 1, 3, 5].
Now, your task is to find the index at which ‘K’ is present in ARR.
Note :
1. If ‘K’ is not present in ARR then print -1.
2. There are no duplicate elements present in ARR. 
3. ARR can be rotated only in the right direction.
For example, if ARR = [12, 15, 18, 2, 4] and K = 2, then the position at which K is present in the array is 3 (0-indexed).
Follow Up
Can you do this in Logarithmic time and constant additional space? 
Input Format
The first line of input contains an integer 'T' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case contains two single-space separated integers ‘N’ and ‘K’, respectively.

The second line of each test case contains ‘N’ single space-separated integers, denoting the elements of the array/list ARR.
Output Format :
For each test case return the index at which K is present in ARR.
Note:
You do not need to print anything; it has already been taken care of. Just implement the given function.
*/

int findPosition(vector<int>& arr, int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.
    int l = 0, e = n-1;
    while(l<=e)
    {
        int mid = (l+e)/2;
        if(arr[mid]==k)
            return mid;
        if(arr[l]<=arr[mid])
        {
            if(arr[l]<=k && k<=arr[mid])
            {
                e = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        else
        {
            if(arr[mid]<=k && k<=arr[e])
            {
                l = mid+1;
            }
            else
            {
                e = mid-1;
            }
        }
    }
    return -1;
}
