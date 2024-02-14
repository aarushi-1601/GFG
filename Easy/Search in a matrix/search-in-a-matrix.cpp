//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
int matSearch (vector <vector <int>> &mat, int N, int M, int X)
{
    // your code here
    int i=0;
    int j=M-1;
//begin from end for first row
//if X is larger then last element of the first row  then jump to next row
// if X is smaller then of the last  element of  that row then keep decrementing the column
   while(i<N && j>=0)
   {
       if(X>mat[i][j])
       {
           i++;
       }
       else if(X<mat[i][j])
       {
           j--;
       }
       else if(X==mat[i][j])
       {
           return 1;
       }
   }
   return 0;
    
}
};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                cin >> arr[i][j];
                
        int x; cin >> x;
        Solution ob;
        cout << ob.matSearch (arr, n, m, x) << endl;
    }
}
// } Driver Code Ends