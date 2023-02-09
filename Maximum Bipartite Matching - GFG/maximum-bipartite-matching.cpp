//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(vector<vector<int>>&G,int idx,vector<bool>&used,vector<int>&jobs)
    {
        for(int i=0;i<G[0].size();i++)
        {
            if(G[idx][i]==1 && !used[i])
            {
                used[i]=true;
                if(jobs[i]==-1 || dfs(G,jobs[i],used,jobs))
                {
                    jobs[i]=idx;
                    return true;
                }
            }
        }
        return false;
    }
	int maximumMatch(vector<vector<int>>&G){
	    int m=G.size();
	    int n=G[0].size();	
	    vector<int> jobs(n,-1);
	    int res=0;
	    for(int i=0;i<m;i++)
	    {
	        vector<bool> used(n,false);
	        if(dfs(G,i,used,jobs)) res++;
	    }
	    return res;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int m, n;
		cin >> m >> n;
		vector<vector<int>>G(m, vector<int>(n, 0));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				cin >> G[i][j];
		}
		Solution obj;
		int ans = obj.maximumMatch(G);
		cout << ans << "\n";    
	}
	return 0;
}
// } Driver Code Ends