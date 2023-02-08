//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool pathexist(int i,int j,int m,int n)
    {
        return i>=0 && j>=0 && i<m && j<n;
    }
    void dfs(int i,int j,int m,int n,vector<vector<int>> &grid,vector<vector<int>>&vis,set<vector<pair<int,int>>> &st,int basei,int basej,vector<pair<int,int>>&vt)
    {
        vis[i][j]=1;
        vt.push_back({basei-i,basej-j});
        if(pathexist(i+1,j,m,n) && grid[i+1][j]==1 && vis[i+1][j]==0)
        {
            dfs(i+1,j,m,n,grid,vis,st,basei,basej,vt);
        }
        if(pathexist(i-1,j,m,n) && grid[i-1][j]==1 && vis[i-1][j]==0)
        {
            dfs(i-1,j,m,n,grid,vis,st,basei,basej,vt);
        }
        if(pathexist(i,j+1,m,n) && grid[i][j+1]==1 && vis[i][j+1]==0)
        {
            dfs(i,j+1,m,n,grid,vis,st,basei,basej,vt);
        }
        if(pathexist(i,j-1,m,n) && grid[i][j-1]==1 && vis[i][j-1]==0)
        {
            dfs(i,j-1,m,n,grid,vis,st,basei,basej,vt);
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        set<vector<pair<int,int>>> st;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1 && vis[i][j]==0)
                {
                    vector<pair<int,int>> vt;
                    dfs(i,j,m,n,grid,vis,st,i,j,vt);
                    st.insert(vt);
                }
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends