/*
https://leetcode.com/problems/majority-element/
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element = nums[0],count = 1;
        for(int i=1;i<nums.size();i++)
        {
            if(count==0)
            {
                element = nums[i];
            }
            if(element==nums[i])
                count++;
            else
                count--;
        }
        return element;
    }
};

/*
https://www.codingninjas.com/codestudio/problems/majority-element_842495?leftPanelTab=0
You have been given an array/list 'ARR' consisting of 'N' integers. Your task is to find the majority element in the array. If there is no majority element present, print -1.
Note:
A majority element is an element that occurs more than floor('N' / 2) times in the array.
*/
#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
	// Write your code here.
    int element = arr[0],count = 1;
    for(int i=1;i<n;i++)
    {
        if(count==0)
        {
            element = arr[i];
        }
        if(element==arr[i])
        {
            count++;
        }
        else
        {
            count--;
        }
        
    }
    count = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==element)
            count++;
    }
    if(count>n/2)
        return element;
    return -1;
}
