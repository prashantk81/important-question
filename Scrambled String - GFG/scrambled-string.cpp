//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++

class Solution{
    public:
    int solve(string s1,string s2,unordered_map<string,bool> &mp)
    {
        if(s1.size()==1) return s1==s2;
        if(s1==s2) return true;
        string key=s1+s2;
        if(mp.find(key)!=mp.end()) return mp[key];
        int size=s1.size();
        for(int i=1;i<size;i++)
        {
            if(solve(s1.substr(0,i),s2.substr(0,i),mp) && solve(s1.substr(i),s2.substr(i),mp) || 
                solve(s1.substr(0,i),s2.substr(size-i),mp) && solve(s1.substr(i),s2.substr(0,size-i),mp))
                {
                    return mp[key]=true;
                }
        }
        return mp[key]=false;
    }
    bool isScramble(string s1, string s2){
        unordered_map<string,bool> mp;
        return solve(s1,s2,mp);
    }    
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1>>S2;
        Solution ob;
        
        if (ob.isScramble(S1, S2)) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends