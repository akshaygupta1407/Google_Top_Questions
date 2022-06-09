/*
Write a function to print all divisors of a number.
https://www.codingninjas.com/codestudio/problems/print-all-divisors-of-a-number_1164188?leftPanelTab=0
*/

#include <bits/stdc++.h>

using namespace std;

    //Write your printDivisors function here
void printDivisors(int n)
{
    vector<int>res;
    for(int i=1;i<=sqrt(n);i++)
    {
        if(n%i==0)
        if(n/i==i)
        {
            cout<<i<<" ";
        }
        else
        {
            cout<<i<<" ";
            res.push_back(n/i);
        }
    }
    for(int i = res.size()-1;i>=0;i--)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int n;
    cin >> n;
    printDivisors(n);
    return 0;
}
