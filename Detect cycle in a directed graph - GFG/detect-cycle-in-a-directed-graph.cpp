//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool bfs(int i,vector<int> adj[],vector<int> &vis)
    {
        queue<int> qp;
        qp.push(i);
        vis[i]=1;
        while(!qp.empty())
        {
            int x=qp.front();
            qp.pop();
            // vis[x]=0;
            for(auto it:adj[x])
            {
                if(vis[it]==0)
                {
                    vis[it]=1;
                    qp.push(it);
                }
                else
                {
                    return true;
                }
            }
        }
        return false;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    bool dfs(int i,vector<int> adj[],vector<int> &vis,vector<int> &pathvisited)
    {
        vis[i]=1;
        pathvisited[i]=1;
        for(auto it: adj[i])
        {
            if(vis[it]==0)
            {
                int p=dfs(it,adj,vis,pathvisited);
                if(p) return true;
            }
            else
            {
                if(pathvisited[it]==1)
                    return true;
            }
        }
        pathvisited[i]=0;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        vector<int> pathvisited(V,0);
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            {
                bool p=dfs(i,adj,vis,pathvisited);
                if(p) return true;
            }
        }
        return false;
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends