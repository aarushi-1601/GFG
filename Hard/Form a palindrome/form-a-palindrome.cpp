//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int countMin(string str){
        int i;
        int n=str.length();
        vector<int> p[n];
        for(i=0; i<n; i++){
            p[i].resize(n,0);
        }
        for(int gap=1; gap<n; gap++){
            for(int j=0,i=gap;i<n;j++,i++){
                if(str[i]==str[j])
                    p[j][i]=p[j+1][i-1];
                else
                    p[j][i]=min(p[j+1][i],p[j][i-1])+1;
            }
        }
        return p[0][n-1];
    //complete the function here
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends