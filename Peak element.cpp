/*
An element is called a peak element if its value is not smaller than the value of its adjacent elements(if they exists).
Given an array arr[] of size N, Return the index of any one of its peak elements.
Note: The generated output will always be 1 if the index that you return is correct. Otherwise output will be 0. 
*/

// M1
/*
TC - O(N)
SC- O(1)
*/
class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
       // Your code here
       if(arr[0] > arr[1])
       return 0;
       if(arr[n-1] > arr[n-2])
       return n-1;
       for(int i=1;i<n-1;i++)
       {
           if(arr[i] > arr[i-1] && arr[i] >arr[i+1])
           return i;
       }
       return 0;
    }
};


/*
M2
TC - O(logn)
SC - O(1)
*/
class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
       // Your code here
       int s = 0,e = n-1,mid=0;
       while(s<=e)
       {
           mid = s + (e-s)/2;
           if((mid==0 || arr[mid]>=arr[mid-1]) && (mid==n-1 || arr[mid]>=arr[mid+1]))
           break;
           if(mid>0 && arr[mid-1] > arr[mid])
           {
               e = mid-1;
           }
           else
           {
               s = mid+1;
           }
       }
       return mid;
    }
    
};
