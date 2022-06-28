/*
https://practice.geeksforgeeks.org/problems/minimum-sum4058/1/?page=1&status[]=unsolved&status[]=attempted&company[]=Google&sortBy=submissions#
Given an array Arr of size N such that each element is from the range 0 to 9. Find the minimum possible sum of two numbers formed using the elements of the array. All digits in the given array must be used to form the two numbers.


*/
class Solution{   
public:
    string solve(int arr[], int n) {
        // code here
        sort(arr,arr+n);
        string s1 = "",s2 = "";
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                s1 += (arr[i]+'0');
            }
            else
            {
                s2+= (arr[i]+'0');
            }
        }
        int j = s1.length()-1,k = s2.length()-1;
        int carry = 0;
        string ans = "";
        while(j>=0 && k>=0)
        {
            int sum = (s1[j]-'0') + (s2[k]-'0') + carry;
            ans += to_string(sum%10);
            carry=sum/10;
            k--;
            j--;
        }
        while(j>=0)
        {
            int sum = (s1[j]-'0') + carry;
            ans += to_string(sum%10);
            carry=sum/10;
            j--;
        }
        while(k>=0)
        {
            int sum = (s2[k]-'0') + carry;
            ans += to_string(sum%10);
            carry=sum/10;
            k--;
        }
        if(carry>=0)
        {
            ans+=to_string(carry);
        }
        while(!ans.empty() && ans.back()=='0')
        {
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
