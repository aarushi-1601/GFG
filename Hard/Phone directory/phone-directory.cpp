//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
         vector<vector<string>> ans;
        set<string> ss;
        vector<string> vs;
        string s1;
        for(int i=0;i<s.length();i++){
            s1+=s[i];
            for(int j=0;j<n;j++){
                if(contact[j].find(s1)!=-1) ss.insert(contact[j]);
            }
            for(auto i:ss) vs.push_back(i);
            if(vs.empty()) ans.push_back({"0"});
            else ans.push_back(vs);
            vs.clear();
            ss.clear();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < ans.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends