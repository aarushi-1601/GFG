//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:
    int f(int ind1,int ind2,string p,string s,vector<vector<int>>&dp)
    {
        //BASE
        if(ind1<0 && ind2<0)
          return 1;
        else if(ind1<0 && ind2>=0)
          return 0;
        else if(ind1>=0 && ind2<0)
        {
            for(int k=0;k<=ind1;k++)
            {
                if(p[k]!='*')
                  return 0;
            }
            return 1;
        }
        
        if(dp[ind1][ind2]!=-1)
          return dp[ind1][ind2];
        if(p[ind1]==s[ind2] || p[ind1]=='?')
          return dp[ind1][ind2]=f(ind1-1,ind2-1,p,s,dp);
        else if(p[ind1]=='*')
        {
            return dp[ind1][ind2] = f(ind1-1,ind2,p,s,dp) || f(ind1,ind2-1,p,s,dp);
        }
    }
    bool match(string wild, string pattern)
    {
        vector<vector<int>> dp(wild.size(),vector<int>(pattern.size(),-1));
        return f(wild.size()-1,pattern.size()-1,wild,pattern,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends