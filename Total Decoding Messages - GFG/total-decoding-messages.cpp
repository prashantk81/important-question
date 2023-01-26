//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int CountWays(string s){
		    int mod=1000000007;
		vector<int> dp(s.size(),0);
        if(s[0]=='0') return 0;
        if(s.size()<2) return 1;
        dp[0]=1;
        if(s[1]=='0' && stoi(s.substr(0,2))>26) return 0;
        if(s[1]=='0')
        {
            dp[1]=1;
        }
        else{
        if(stoi(s.substr(0,2))<=26)
        {
            dp[1]=2;
        }
        else
        {
            dp[1]=1;
        }
        }
        for(int i=2;i<s.size();i++)
        {
            if(s[i]=='0' && s[i-1]=='0') return 0;
            if(s[i]=='0')
            {
                if(stoi(s.substr(i-1,2))>26) return 0;
                dp[i]+=dp[i-2];
                dp[i]=dp[i]%mod;
            }
            else if(s[i-1]=='0')
            {
                dp[i]+=dp[i-1];
                dp[i]=dp[i]%mod;
            }
            else
            {
                dp[i]+=dp[i-1];
                dp[i]=dp[i]%mod;
                if(stoi(s.substr(i-1,2))<=26)
                {
                    dp[i]+=dp[i-2];
                    dp[i]=dp[i]%mod;
                }
            }
        }
        return dp[s.size()-1];
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends