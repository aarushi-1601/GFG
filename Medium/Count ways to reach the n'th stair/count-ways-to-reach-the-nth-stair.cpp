//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int mod=1000000007;

    int countWays(int n)
    {
        // your code here
        vector<int>dp(n+2);
        dp[n]=1;
        dp[n+1]=0;
        
        for(int i=n-1;i>=0;i--){
            dp[i]=(dp[i+1]+dp[i+2])%mod;
        }
        return dp[0];
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends