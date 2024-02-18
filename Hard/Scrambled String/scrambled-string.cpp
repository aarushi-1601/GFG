//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++

class Solution{
    public:
 bool solve(string &s1,string &s2,map<pair<string,string>,bool>&dp){
        pair<string,string>p={s1,s2};
        if(dp.find(p)!=dp.end()){
            return dp[p];
        }
        int n=s1.size();
        if(s1==s2){
            return dp[p]=true;
        }
        // if(n<=1){   No need of this part of the code
        //     return dp[p]=false;
        // }
        bool flag=false;

        for(int i=1;i<=n-1;i++){
            //partition at i-->lenght of left part will be i+1 and length of right part is n-i-1;
            string l1 = s1.substr(0,i);
            string r1 = s1.substr(i,n-i);
            string l2 = s2.substr(0,i);
            string r2 = s2.substr(i,n-i);

            string l10 = s1.substr(0,i);
            string r10 = s1.substr(i,n-i);
            string l20 = s2.substr(0,n-i);
            string r20 = s2.substr(n-i,i);
            if((solve(l1,l2,dp) && solve(r1,r2,dp))||(solve(l10,r20,dp) && solve(r10,l20,dp))){
                flag=true;
                break;
            }
        }
        return dp[p]=flag;
    }
    bool isScramble(string s1, string s2) {
        map<pair<string,string>,bool>dp;
        if(s1.size()!=s2.size()){
            return true;
        }
        return solve(s1,s2,dp);
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1>>S2;
        Solution ob;
        
        if (ob.isScramble(S1, S2)) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends