//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    void bfs(queue<int> &qp,vector<int> adj[],vector<int> &ans,vector<int> &indegree)
    {
        while(!qp.empty())
        {
            int x=qp.front();
            qp.pop();
            ans.push_back(x);
            for(auto it:adj[x])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    qp.push(it);
                }
            }
        }
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                indegree[it]++;
            }
        }
        queue<int> qp;
        for(int i=0;i<V;i++)
        {
            if(!indegree[i]) qp.push(i);
        }
        vector<int> ans;
        bfs(qp,adj,ans,indegree);
        if(ans.size()==V) return false;
        return true;
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