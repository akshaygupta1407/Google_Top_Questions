/*
https://www.codingninjas.com/codestudio/problems/allocate-books_1090540?leftPanelTab=0

Q) You are given N number of books. Every ith book has Ai number of pages.

You have to allocate contiguous books to M number of students. There can be many ways or permutations to do so. In each permutation, one of the M students will be allocated the maximum number of pages. Out of all these permutations, the task is to find that particular permutation in which the maximum number of pages allocated to a student is the minimum of those in all the other permutations and print this minimum value.

Each book will be allocated to exactly one student. Each student has to be allocated at least one book.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

*/
#include<bits/stdc++.h>
bool possible(vector<int> &arr, int n, int m,int currmin)
{
    int students = 1,currsum = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>currmin)    return false;
        if(arr[i]+currsum>currmin)
        {
            students++;
            currsum = arr[i];
            if(students>m)    return false;
        }
        else
        {
            currsum+=arr[i];
        }
    }
    return true;
}
int allocateBooks(vector<int> arr, int n, int m) {
    // Write your code here.
    if(m>n)    return -1;    //no of students greater than the books
    int start = 0,end = 0;
    for(auto x : arr)
    {
        end+=x;
    }
    int res = INT_MAX;
    while(start<=end)
    {
        int mid = (start+end)/2;
        if(possible(arr,n,m,mid))    //if it is possible to give all the students number of pages less than equal to mid
        {
            res = min(res,mid);
            end = mid-1;
        }
        else
        {
            start = mid+1;
        }
    }
    return res;
}
