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
    void dfs(vector<vector<int>> &grid,vector<vector<int>> &vis,int i,int j,int m,int n)
    {
        vis[i][j]=1;
        if(pathexist(i+1,j,m,n) && grid[i+1][j]==1 && vis[i+1][j]==0)
        {
            dfs(grid,vis,i+1,j,m,n);
        }
        if(pathexist(i-1,j,m,n) && grid[i-1][j]==1 && vis[i-1][j]==0)
        {
            dfs(grid,vis,i-1,j,m,n);
        }
        if(pathexist(i,j+1,m,n) && grid[i][j+1]==1 && vis[i][j+1]==0)
        {
            dfs(grid,vis,i,j+1,m,n);
        }
        if(pathexist(i,j-1,m,n) && grid[i][j-1]==1 && vis[i][j-1]==0)
        {
            dfs(grid,vis,i,j-1,m,n);
        }
    }
    int numberOfEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            if(grid[i][0]==1 && vis[i][0]==0)
            {
                dfs(grid,vis,i,0,m,n);
            }
            if(grid[i][n-1]==1 && vis[i][n-1]==0)
            {
                dfs(grid,vis,i,n-1,m,n);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(grid[0][i]==1 && vis[0][i]==0)
            {
                dfs(grid,vis,0,i,m,n);
            }
            if(grid[m-1][i]==1 && vis[m-1][i]==0)
            {
                dfs(grid,vis,m-1,i,m,n);
            }
        }
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1 && vis[i][j]==0)
                {
                    ans++;
                }
            }
        }
        return ans;
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
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends