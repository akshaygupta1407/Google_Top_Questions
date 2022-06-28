/*
https://practice.geeksforgeeks.org/problems/find-the-frequency/1/?page=1&status[]=unsolved&status[]=attempted&company[]=Google&sortBy=submissions
Given a vector of N positive integers and an integer X. The task is to find the frequency of X in vector.
*/
int findFrequency(vector<int> v, int x){
    // Your code here
    int count = 0;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==x)
            count++;
    }
    return count;
}
