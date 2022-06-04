/*
https://www.codingninjas.com/codestudio/problems/maximum-distance_1170523?leftPanelTab=0
https://practice.geeksforgeeks.org/problems/maximum-index3307/1/

Given an array Arr[] of N positive integers. The task is to find the maximum of j - i subjected to the constraint of Arr[i] <= Arr[j].
Example 1:

Input:
N = 9
Arr[] = {34, 8, 10, 3, 2, 80, 30, 33, 1}
Output: 6
Explanation: In the given array Arr[1] <
Arr[7]  satisfying the required condition
(Arr[i] <= Arr[j])  thus giving the
maximum difference of j - i which is
6(7-1).
*/

class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        // code here
        vector<int>Leftmn(n),Rightmx(n);
        Leftmn[0] = arr[0];
        for(int i=1;i<n;i++)
        {
            Leftmn[i] = min(Leftmn[i-1],arr[i]);
        }
        Rightmx[n-1] = arr[n-1];
        for(int i=n-2;i>=0;i--)
        {
            Rightmx[i] = max(Rightmx[i+1],arr[i]);
        }
        int i=0,j=0;
        int mx = -1;
        while(i<n && j<n)
        {
            if(Leftmn[i]<=Rightmx[j])
            {
                mx = max(mx,j-i);
                j++;
            }
            else
            {
                i++;
            }
        }
        return mx;
    }

};
