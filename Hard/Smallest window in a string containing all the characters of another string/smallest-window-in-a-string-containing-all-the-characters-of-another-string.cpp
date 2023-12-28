//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        int pString[26];
        memset(pString, 0, sizeof(pString));
        int P_unique_Char = 0;
        
        int n = s.size();
        int Sstring_window[26];
        memset(Sstring_window, 0, sizeof(Sstring_window));
        int S_char_get = 0;
        int i = 0;
        int j = 0;
        int start = -1;
        int mini = INT_MAX;
        
        // For Output answer
        string ans = "";
        
        for(auto i : p){
            pString[i-'a']++;
        }
        for(int i = 0; i<26; i++){
            if(pString[i] != 0){
                P_unique_Char++;
            }
        }
        
        while(j < n){
            int index = s[j]-'a';
            Sstring_window[index]++;
            if(Sstring_window[index] == pString[index]){
                S_char_get++;
            }
            
            while(S_char_get == P_unique_Char){
                if(mini > j-i+1){
                    mini = j-i+1;
                    start = i;
                }
                Sstring_window[s[i]-'a']--;
                if(Sstring_window[s[i]-'a'] < pString[s[i]-'a']){
                    S_char_get--;
                }
                    i++;
            }
            
            j++;
        }
        
        if(start == -1){
            return "-1";
        }
        
        for(int k = start; k < start+mini; k++){
            ans += s[k];
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends