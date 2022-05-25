/*
Q) You are given an array “ARR” of size N. Your task is to find out the sum of maximum and minimum elements in the array.
Sample Input 1:
2
7
1 2 4 5 6 6 6 
6
-1 -4 5 8 9 3
Sample Output 1:
7
5
*/
//code
#include<bits/stdc++.h>
int sumOfMaxMin(int arr[], int n){
	// Write your code here.
    int sum = 0;
    int mx = INT_MIN,mn = INT_MAX;
    for(int i=0;i<n;i++)
    {
        mx = max(mx,arr[i]);
        mn = min(mn,arr[i]);
    }
    return mx+mn;
}
