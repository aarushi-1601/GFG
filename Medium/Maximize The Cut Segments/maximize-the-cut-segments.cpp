//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
  int solveMem(int n, int x, int y, int z, vector<int> &dp) {
        if(n < 0) return INT_MIN;
        
        if(n == 0) return 0;
        
        if(dp[n] != INT_MIN) return dp[n];
        
        int a = solveMem(n-x, x, y, z, dp) + 1;
        int b = solveMem(n-y, x, y, z, dp) + 1;
        int c = solveMem(n-z, x, y, z, dp) + 1;
        
        return dp[n] = max(a, max(b, c));
    }
 
    //Tabulation
    int solveTab(int n, int x, int y, int z) {
        vector<int> dp(n+1, -1);
        
        dp[0] = 0;
        
        for(int i=1; i<=n; ++i) {
            int a= -1, b= -1, c= -1;
            if(i-x >= 0 && dp[i-x] != -1) 
                a = dp[i-x] + 1;
                
            if(i-y >= 0 && dp[i-y] != -1) 
                b = dp[i-y] + 1;
                
            if(i-z >= 0 && dp[i-z] != -1) 
                c = dp[i-z] + 1;
                
            dp[i] = max(a, max(b, c));
        }
        
        return dp[n] < 0 ? 0 : dp[n]; 
    }
    
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        // vector<int> dp(n+1, INT_MIN);
        // int ans = solveMem(n, x, y, z, dp);
        // return ans < 0 ? 0 : ans; 
        
        return solveTab(n, x, y, z);
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends