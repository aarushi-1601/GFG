//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solvertab(int x, int N, int arr[], vector<vector<int>> &dp) {
        
        for (int i = 0; i < N; i++) {
            dp[0][i] = 1;
        }
    
        for (int i = 1; i <= x; i++) {
            for (int j = 0; j < N; j++) {
                int take = (i - arr[j] >= 0) ? dp[i - arr[j]][j - 1] : 0;
                int nottake = (j >= 1) ? dp[i][j - 1] : 0;
                dp[i][j] = take || nottake;
            }
        }
    
        return dp[x][N - 1];
    }

    
    int equalPartition(int N, int arr[]) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += arr[i];
        }
    
        if (sum % 2 != 0) {
            return 0; // If the sum is odd, it cannot be partitioned into equal subsets
        }
    
        vector<vector<int>> dp((sum / 2) + 1, vector<int>(N + 1, 0));
    
        return solvertab(sum / 2, N, arr, dp) ? 1 : 0;
    }

};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends