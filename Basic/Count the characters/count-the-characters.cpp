//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
        int getCount (string S, int N)
        {
            unordered_map<char,int>m;
            int count=0;
            for(int i=0; i<S.length(); i++){
                if(S[i]!=S[i-1]){
                    m[S[i]]++;
                }
            }
            for(auto it:m){
                if(it.second==N){
                    count++;
                }
            }
            return count;
            //code here.
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        int n; cin >> n;
        
        Solution ob;
        cout <<ob.getCount (s, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends