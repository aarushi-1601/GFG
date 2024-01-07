//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
     int findFirstOccurance(int arr[], int n, int x){
      int s=0;
        int e=n-1;
        int ans=-1;
        
        while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid]==x){
        ans=mid;
        e=mid;
        }
      if(arr[mid]<x){
        s=mid+1;
        }
        else{
        e=mid-1;
        }
        }
        return ans;
  }
  
int findLastOccurance(int arr[],int n,int target){
  int s=0;
  int e=n-1;
  int ans=-1;
  while(s<=e){
    int mid=s+(e-s)/2;
  if(arr[mid]==target){
    ans=mid;
    s=mid+1;
  }
  else if(arr[mid]<target){
    s=mid+1;
  }
  else{
    e=mid-1;
  }
  }
  return ans;
}
     vector<int> find(int arr[], int n , int x )
    {
        // code here
        vector<int>v; 
        v.push_back(findFirstOccurance(arr,n,x));
        v.push_back(findLastOccurance(arr,n,x));
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends