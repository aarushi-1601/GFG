//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &s) {
        // code here
         int result = 0;
   std::map<char,int> roman = { 
        {'I', 1},
        {'V', 5}, 
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000} 
        };
 
        for(int i=0; i<s.size(); i++) {
        int temp=0;
        auto it = roman.find(s[i]);
        auto itn = roman.find(s[i+1]);
        if(it!=roman.end()) {
        temp+= it->second;
        if(itn!=roman.end()){
        if(itn->second > temp) {
        temp = itn->second - temp;
        i++;
        }
 
        }
        }
        result+=temp;
        }
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends