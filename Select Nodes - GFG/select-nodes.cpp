//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int dfs(vector<int> adj[],vector<int> &vis,int curr,int &ans)
    {
        vis[curr]=1;
        int isselect=0;
        for(auto it:adj[curr])
        {
            if(vis[it]==0)
            {
                if(!dfs(adj,vis,it,ans))
                {
                    isselect=1;
                }
            }
        }
        if(isselect)
            {
               ans++;
            }
        
        return isselect;
        
    }
    int countVertex(int N, vector<vector<int>>edges){
        vector<int> adj[N+1];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(N+1,0);
        int ans=0;
        dfs(adj,vis,1,ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<vector<int>>edges;
        for(int i = 0; i < N-1; i++){
            int x,y;
            cin >> x >> y;
            vector<int> edge;
            edge.push_back(x);
            edge.push_back(y);
            edges.push_back(edge);
        }
        
        Solution ob;
        cout << ob.countVertex(N, edges) << endl;
    }
    return 0; 
} 
// } Driver Code Ends