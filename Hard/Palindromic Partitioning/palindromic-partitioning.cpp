//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPalindrome(string s,int i,int j){
        while(i<j){
            if(s[i]!=s[j])return 0;
            i++;j--;
        }
        return 1;
    }
   int solveMem(string str, int i, int n,vector<int> &dp) {
    
    // base case
    if(i==n)return 0;
 
    if(dp[i]!=-1)
      return dp[i];
    int mini = INT_MAX;

        for(int j=i;j<n;j++){
            if(isPalindrome(str,i,j)){
                int ans = 1 + solveMem(str,j+1,n,dp);
                mini = min(ans,mini);
            }
        }

    return dp[i] = mini;
}
    int palindromicPartition(string str)
    {
        int n =str.length();
        // return solve(str,0,n)-1;
        vector<int> dp(n+1,-1);
        return solveMem(str,0,n,dp)-1;

    }
};
        // code here
 

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends