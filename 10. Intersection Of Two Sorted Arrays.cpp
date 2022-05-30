/*
https://www.codingninjas.com/codestudio/problems/intersection-of-2-arrays_1082149?leftPanelTab=0

Taking two pointers where pointer1 will point to arr1 and pointer2 will point arr2
Compare each value. If both are same, push it in the vector else increase the pointer of that one which has smaller value
*/
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	// Write your code here.
    vector<int>res;
    int s1 = 0,s2 = 0;    //two pointers
    while(s1<n && s2<m)
    {
        if(arr1[s1]==arr2[s2])
        {
            res.push_back(arr1[s1]);
            s1++;
            s2++;
        }
        else if(arr1[s1]<arr2[s2])
        {
            s1++;
        }
        else
        {
            s2++;
        }
    }
    if(res.empty())
        res.push_back(-1);
    return res;
}
