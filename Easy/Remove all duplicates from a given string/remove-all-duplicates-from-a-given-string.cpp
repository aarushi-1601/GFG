//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	string removeDuplicates(string str) {
	    string ans="";
	    ans.push_back(str[0]);
	    for(int i=1; i<str.length(); i++){
	        if(ans.find(str[i])==string::npos){
	            ans.push_back(str[i]);
	        }
	    }
	    return ans;
	    // code here
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends