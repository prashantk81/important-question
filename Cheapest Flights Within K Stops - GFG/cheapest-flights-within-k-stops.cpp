//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        vector<pair<int,int>>adj[n];
        for(int i=0;i<flights.size();i++)
        {
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        vector<int> vis(n+1,-1);
        queue<pair<int,pair<int,int>>> qp;
        qp.push({0,{src,0}});
        vector<int> dist(n,1e9);
        dist[src]=0;
        // int fare=1e9;
        // dfs(adj,vis,src,dst,k,0,fare);
        while(!qp.empty())
        {
            auto it=qp.front();
            qp.pop();
            int stops=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            if(stops>k) continue;
            for(auto itr:adj[node])
            {
                int adjnode=itr.first;
                int edw=itr.second;
                if(cost+edw<dist[adjnode] && stops<=k)
                {
                    dist[adjnode]=cost+edw;
                    qp.push({stops+1,{adjnode,cost+edw}});
                }
            }
        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends