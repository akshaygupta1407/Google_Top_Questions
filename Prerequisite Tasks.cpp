/*
There are a total of N tasks, labeled from 0 to N-1. Some tasks may have prerequisites, for example to do task 0 you have to first complete task 1, which is expressed as a pair: [0, 1]
Given the total number of tasks N and a list of prerequisite pairs P, find if it is possible to finish all tasks.
*/
class Solution {
public:
    bool cycle(unordered_map<int,list<int>>&h,vector<int>&visited,int src)
    {
        if(visited[src]==2) return true;
        visited[src] = 2;
        for(auto x : h[src])
        {
            if(visited[x]!=1)
            {
                if(cycle(h,visited,x))  return true;
            }
        }
        visited[src] = 1;
        return false;
    }
	bool isPossible(int n, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    unordered_map<int,list<int>>h;
	    vector<int>visited(n,0);
	    for(auto x : prerequisites)
	    {
	        int u = x.first,v = x.second;
	        h[u].push_back(v);
	    }
	    for(int i=0;i<n;i++)
	    {
	        if(visited[i]==0)
	        {
	            if(cycle(h,visited,i))  return false;
	        }
	    }
	    return true;
	    
	}
};
