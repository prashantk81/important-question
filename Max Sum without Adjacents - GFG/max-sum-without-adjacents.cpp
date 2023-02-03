//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int maxsum(int *arr,int n, int i,vector<int> &dp)
	{
	    if(i>=n)
	    {
	        return 0;
	    }
	    if(dp[i]!=-1) return dp[i];
	    int pick=0;
	    int notpick=0;
	    pick=arr[i]+maxsum(arr,n,i+2,dp);
	    notpick=maxsum(arr,n,i+1,dp);
	    return dp[i]=max(pick ,notpick);
	}
	int findMaxSum(int *arr, int n) {
	    vector<int> dp(n,-1);
	    return maxsum(arr,n,0,dp);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends