//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    long long int mincost(int idx,int prev,int n,int r[],int g[],int b[],vector<vector<long long int>> &dp)
    {
        if(idx==n)
        {
            return 0;
        }
        if(dp[idx][prev]!=-1) return dp[idx][prev];
        long long int ans1=INT_MAX;
        long long int ans2=INT_MAX;
        if(prev==0)
        {
            ans1=g[idx]+mincost(idx+1,1,n,r,g,b,dp);
            ans2=b[idx]+mincost(idx+1,2,n,r,g,b,dp);
            // return dp[idx][prev]=min(g[idx]+mincost(idx+1,1,n,r,g,b,dp),b[idx]+mincost(idx+1,2,n,r,g,b,dp));
        }
        else if(prev==1)
        {
            ans1=r[idx]+mincost(idx+1,0,n,r,g,b,dp);
            ans2=b[idx]+mincost(idx+1,2,n,r,g,b,dp);
            // return dp[idx][prev]=min(r[idx]+mincost(idx+1,0,n,r,g,b,dp),b[idx]+mincost(idx+1,2,n,r,g,b,dp));
        }
        else
        {
            ans1=r[idx]+mincost(idx+1,0,n,r,g,b,dp);
            ans2=g[idx]+mincost(idx+1,1,n,r,g,b,dp);
            // return dp[idx][prev]=min(r[idx]+mincost(idx+1,0,n,r,g,b,dp),g[idx]+mincost(idx+1,1,n,r,g,b,dp));
        }
        return dp[idx][prev]=min(ans1,ans2);
        
    }
    long long int distinctColoring(int N, int r[], int g[], int b[]){
        vector<vector<long long int>> dp(N,vector<long long int>(3,-1));
        // long long int ans=mincost(0,3,N,r,g,b,dp);
        long long int ans1=INT_MAX;
        long long int ans2=INT_MAX;
        long long int ans3=INT_MAX;
        ans1=r[0]+mincost(1,0,N,r,g,b,dp);
        ans2=g[0]+mincost(1,1,N,r,g,b,dp);
        ans3=b[0]+mincost(1,2,N,r,g,b,dp);
        return min(ans1,min(ans2,ans3));
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
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends