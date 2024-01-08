//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
    int f(int arr[], int ind, int sum , vector<vector<int>> &dp){
        int modulo = 1e9 + 7;
        if(sum == 0) return 1;
        if(ind == 0) return arr[0] == sum;
        if(dp[ind][sum] != -1) return dp[ind][sum]%modulo;
        
        int notpick = f(arr,ind-1,sum,dp);
        int pick =0;
        if(arr[ind] <= sum){
            pick = f(arr,ind-1,sum-arr[ind],dp);
        }
        
        return dp[ind][sum] = (pick%modulo + notpick%modulo)%modulo;
    }
    int perfectSum(int arr[], int n, int sum)
    {
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        sort(arr,arr+n);
        reverse(arr,arr+n);
        return f(arr,n-1,sum,dp);
    }
      
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends