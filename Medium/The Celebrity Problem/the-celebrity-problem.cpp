//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
         for(int j=0;j<n;j++){
           
             M[j][j]=1;
             int i=0;
             while(  i<n && M[i][j]==1){
                 i++;
             }
             M[j][j]=0;
             if(i==n){
                 i=0;
                 
                 while(M[j][i]==0 && i<n){
                      i++;    
                 }
                 if(i==n){
                     return j;
                 }
             }
         }
         return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends