//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
public:
    string rremove(string s){
        int i=0;
        int n = s.length();
        string temp = "";
        while(i<n){
            int j=i+1;
            if(s[i]==s[i-1]||s[i]==s[j]){
                while(s[i]==s[i-1]||s[i]==s[j])
                i++;
            }else{
                temp +=s[i];
                i++;
                // j++;
            }
            
        }

        if(temp.length()==s.length()){
            return temp;
        }
        return rremove(temp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.rremove(s) << "\n";
    }
    return 0;
}
// } Driver Code Ends