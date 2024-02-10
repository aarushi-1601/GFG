//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    long long int oneterm(vector<long long int>& nums,int n, int i){
        long long int p=1;
        for(int j=0;j<n;j++){
            if(j==i){
                if(j==n-1){
                    return p;
                }
                j++;
            }
            p*=nums[j];
        }
        return p;
    }
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
        vector<long long int>ans;
        for(int i=0;i<n;i++){
            ans.push_back({oneterm(nums,n,i)});
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends