//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        string lowercase="";
        string uppercase="";
        
        for(int i=0;i<n;i++)
        {
            if('a'<=str[i] && str[i]<='z')
            {
                lowercase+=str[i];
            }
            else
            {
                uppercase+=str[i];
            }
        }
        sort(lowercase.begin(),lowercase.end());
        sort(uppercase.begin(),uppercase.end());
        string result="";
        int p=0;
        int q=0;
        for(int i=0;i<n;i++)
        {
            if('a'<=str[i] && str[i]<='z')
            {
                result+=lowercase[p++];
            }
            else
            {
                result+=uppercase[q++];
            }
        }
        return result;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends