//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  vector<int> safeNode;
    bool dfs(int idx,vector<int> adj[],vector<int>&vis,vector<int>&path)
    {
        vis[idx]=1;
        path[idx]=1;
        for(auto it:adj[idx])
        {
            if(vis[it]==0)
            {
                bool p=dfs(it,adj,vis,path);
                if(!p)
                {
                    return false;
                }
            }
            else
            {
                if(path[it]==0)
                {
                    safeNode.push_back(it);
                }
                else
                {
                    return false;
                }
            }
        }
        path[idx]=0;
        safeNode.push_back(idx);
        return true;
    }
    vector<int> eventualSafeNodes(int n, vector<int> adj[]) {
        vector<int> vis(n,0);
        vector<int> pathvis(n,0);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                dfs(i,adj,vis,pathvis);
            }
        }
        sort(safeNode.begin(),safeNode.end());
        safeNode.erase(unique(safeNode.begin(),safeNode.end()),safeNode.end());
        return safeNode;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends