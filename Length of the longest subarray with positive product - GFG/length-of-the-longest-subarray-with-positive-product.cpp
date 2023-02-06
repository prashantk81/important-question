//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int maxLength(vector<int> &nums,int n){
           vector<vector<int>> splitarr;
        vector<int> temp; 
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                splitarr.push_back(temp);
                temp.clear();
            }
            else
            {
                temp.push_back(nums[i]);
            }
        }
        splitarr.push_back(temp);
        int finalans=0;
        for(int i=0;i<splitarr.size();i++)
        {
            vector<int> temp=splitarr[i];
            int neg=0;
            for(int j=0;j<temp.size();j++)
            {
                if(temp[j]<0) neg++;
            }
            if(neg%2==0)
            {
                if(finalans<temp.size())
                { 
                    finalans=temp.size();  
                }          
            }
            else
            {
                int pos=0;
                for(int j=0;j<temp.size();j++)
                {
                    if(temp[j]<0)
                    {
                        pos=j;
                        break;
                    }
                }
                if(finalans<temp.size()-pos-1)
                {
                    finalans=temp.size()-pos-1;
                }
                pos=0;
                for(int j=temp.size()-1;j>=0;j--)
                {
                    if(temp[j]<0)
                    {
                        pos=j;
                        break;
                    }
                }
                if(finalans<pos)
                {
                    finalans=pos;
                }
            }

        }
            return finalans;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends