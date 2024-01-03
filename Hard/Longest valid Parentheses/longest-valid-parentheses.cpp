//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxLength(string S){
        // code here
        int left = 0, right = 0, ans = 0;
        
        for (int i=0; i < S.length(); i++) {
            
            if (S[i] == '(')
                left++;
            
            else if (S[i] == ')')
                right++;
        
            if (left == right)
                ans = max(ans, 2*left);
            
            else if (right > left) {
                left = 0;
                right = 0;
            }
        }
        
        left =0;
        right =0;
        for (int i=S.length() - 1; i >= 0; --i) {
            
            if (S[i] == '(')
                left++;
            
            else if (S[i] == ')')
                right++;
            if (left == right)
                ans = max(ans, 2*left);
            
            else if (right < left) {
                left = 0;
                right = 0; 
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.maxLength(S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends