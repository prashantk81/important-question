//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minOperation(string s) {
        // code here
        int size=s.size();
        int half=size/2;
        int red=0;
        while(half>=1)
        {
            string str1=s.substr(0,half);
            string str2=s.substr(half,half);
            // cout<<str1<<" "<<str2<<endl;
            if(str1==str2)
            {
                red=half-1;
                break;
            }
            half-=1;
        }
        return size-red;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends