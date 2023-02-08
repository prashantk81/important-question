//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfs(int node,vector<int> adj[],vector<int> &vis)
    {
        queue<pair<int,int>> qp;
        qp.push({node,-1});
        vis[node]=1;
        while(!qp.empty())
        {
            int x=qp.front().first;
            int par=qp.front().second;
            qp.pop();
            for(auto it:adj[x])
            {
                if(vis[it]==-1)
                {
                    vis[it]=1;
                    qp.push({it,x});
                }
                else
                {
                   if(par!=it) return true; 
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V,-1);
        for(int i=0;i<V;i++)
        {
            if(vis[i]==-1)
            {
                bool p=bfs(i,adj,vis);
                if(p) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends