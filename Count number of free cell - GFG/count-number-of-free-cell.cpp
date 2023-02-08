//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr){
      vector<long long int> ans;
      vector<int> row(n+1,0);
      vector<int> col(n+1,0);
      int rt=0;
      int ct=0;
      int totalzero=n*n;
      for(int i=0;i<k;i++)
      {
          if(row[arr[i][0]]==0 && col[arr[i][1]]==0)
          {
                totalzero-=(n+n-ct-rt-1);
                row[arr[i][0]]=1;
                col[arr[i][1]]=1;
                rt++;
                ct++;
                
          }
          else if(row[arr[i][0]]==1 && col[arr[i][1]]==0)
          {
              totalzero-=(n-rt);
              col[arr[i][1]]=1;
              ct++;
          }
          else if(row[arr[i][0]]==0 && col[arr[i][1]]==1)
          {
              totalzero-=(n-ct);
              row[arr[i][0]]=1;
              rt++;
          }
          ans.push_back(totalzero);
      }
      return ans;
  }
      
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> arr(k,vector<int>(2));
        for(int i=0;i<k;i++){
            int x, y;
            cin>>x>>y;
            arr[i][0] = x;
            arr[i][1] = y;
        }
        Solution ob;
        vector<long long int> ans = ob.countZero(n,k,arr);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;    
    }
    
    return 0;
}


// } Driver Code Ends