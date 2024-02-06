//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    int dfs(int node,vector<int>g[],vector<int>&vis){
        vis[node]=1;
        int ans=g[node].size();
        for(auto i:g[node]) if(!vis[i]) ans+=dfs(i,g,vis);
        return ans;
    }
    
    int isCircle(int n, vector<string> A)
    {
        vector<int>g[26],indeg(26,0),outdeg(26,0);
        for(auto i:A){
            g[i.front()-'a'].push_back(i.back()-'a');
            indeg[i.back()-'a']++;
            outdeg[i.front()-'a']++;
        }
        for(int i=0;i<26;i++){
            if(indeg[i]!=outdeg[i]) return false;
        }
        vector<int>vis(26,0);
        return n==dfs(A[0][0]-'a',g,vis);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<string> A;
        string s;
        
        for(int i = 0;i < N; i++)
        {
            cin>>s;
            A.push_back(s);
        }
        
        Solution ob;
        cout<<ob.isCircle(N, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends