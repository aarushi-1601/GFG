//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        int i=0;
       string result;
       while(arr[0][i]!='\0')
       {
           char c=arr[0][i];
           for(int j=0;j<N;j++)
           {
                if( arr[j][i]=='\0'|| c!=arr[j][i])
                {
                    goto bail;
                }
           }
           i++;
           result.push_back(c);
       }
       bail:
        if(!result.length())
        {
            return "-1";
        }
        return result;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends