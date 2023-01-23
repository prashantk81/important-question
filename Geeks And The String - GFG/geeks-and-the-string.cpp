//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        s=s+"$";
        string res="";
        int count=0,flag=1;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==s[i+1])
            {
                count++;
            }
            else
            {
                count++;
                if(res.size() && res.back()==s[i]) count+=1;
                if(count%2!=0)
                {
                    count=0;
                    if(res.size()==0 || res.back()!=s[i])
                    {  
                        res.push_back(s[i]);
                    }
                }
                else
                {
                    if(res.size() && res.back()==s[i])
                    {
                        res.pop_back();
                    }
                    count=0;
                }
            }
        }
        if(res.back()=='$')
        {
            res.pop_back();
        }
        if(res.size()==0) return "-1";
        return res;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends