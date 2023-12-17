//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        string str;
        
        int j = S.length()-1, count = 0;
        
        while(j>=0){
            
            if(S[j] == '.'){
                str += S.substr(j+1, count);
                str.push_back('.');
                j--;
                count = 0;
            }
            
            if(j==0){
                
                str += S.substr(j, count+1);
                j--;}
                else{
                    j--;
                    count++;
                }
        // code here 
    } 
    return str;
    }
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends