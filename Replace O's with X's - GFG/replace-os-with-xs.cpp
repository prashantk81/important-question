//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
bool pathexist(int i,int j,int m,int n)
    {
        return (i>=0 && i<m && j>=0 && j<n);
    }
    void dfs(vector<vector<char>>& board,vector<vector<int>> &vis,int i,int j,int m,int n)
    {
        vis[i][j]=1;
        if(pathexist(i+1,j,m,n) && board[i+1][j]=='O' && vis[i+1][j]==0)
        {
            dfs(board,vis,i+1,j,m,n);
        }
        if(pathexist(i,j+1,m,n) && board[i][j+1]=='O' && vis[i][j+1]==0)
        {
            dfs(board,vis,i,j+1,m,n);
        }
        if(pathexist(i-1,j,m,n) && board[i-1][j]=='O' && vis[i-1][j]==0)
        {
            dfs(board,vis,i-1,j,m,n);
        }
        if(pathexist(i,j-1,m,n) && board[i][j-1]=='O' && vis[i][j-1]==0)
        {
            dfs(board,vis,i,j-1,m,n);
        }
    }
    vector<vector<char>> fill(int m, int n, vector<vector<char>> board)
    {
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            if(board[i][0]=='O' && vis[i][0]==0)
            {
                dfs(board,vis,i,0,m,n);
            }
            if(board[i][n-1]=='O' && vis[i][n-1]==0)
            {
                dfs(board,vis,i,n-1,m,n);
            }
        }
        for(int j=0;j<n;j++)
        {
            if(board[0][j]=='O' && vis[0][j]==0)
            {
                dfs(board,vis,0,j,m,n);
            }
            if(board[m-1][j]=='O' && vis[m-1][j]==0)
            {
                dfs(board,vis,m-1,j,m,n);
            }
        }
        vector<vector<char>> ans(m,vector<char>(n,'X'));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O' && vis[i][j]==1)
                {
                    ans[i][j]='O';
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends