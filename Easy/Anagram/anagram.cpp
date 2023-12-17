//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        int n = a.size(), m = b.size();
        
        if(n != m) {
            return false;
        }
        int count[256];
        memset(count, 0, sizeof(count));
        for(int i = 0; i < n; i++) {
            count[a[i]]++;
            count[b[i]]--;
        }
        
        for(int i = 0 ;i < 256; i++) {
            if(count[i] != 0){
                return false;
            }
        }
        return true;
        
        // Your code here
        
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends