//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        int i=0; 
        int count= 0;
        int max= 0;
        while(i<n){
            if(i== n- 1){
                return count;
            }
            if(arr[i]== 0){
                return -1;
            }
            max= i+ arr[i];
            if(max>=n- 1){
                count++;
                return count;
            }
            for(int j= i+ 1; j< i+ arr[i]; j++){
                if(j+ arr[j]> max+ arr[max] and arr[j]!= 0){
                    max= j;
                }
            }
            count++;
            i= max;
            
        }
        return count;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends