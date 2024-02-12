//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool solve(vector<int>arr,int sum,int i,vector<vector<int>>&dp)
    {
        if(sum<0)
        return 0;
        if(i==arr.size()){
            if(sum==0)
            return true;
        else
            return false;
        }
        
        if(sum==0)
        return true;
        if(dp[i][sum]!=-1)
        return dp[i][sum];
        //take
       
        bool  take=solve(arr,sum-arr[i],i+1,dp);
        bool nottake=solve(arr,sum,i+1,dp);
        return dp[i][sum]=take || nottake;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        vector<vector<int>>dp(arr.size(),vector<int>(sum+1,-1));
       return solve(arr,sum,0,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends