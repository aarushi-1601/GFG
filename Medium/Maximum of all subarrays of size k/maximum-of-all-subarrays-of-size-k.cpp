//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        int i =0,j=0;
        int m=0,g;
        vector<int> ans;
        while(j<n){
            
            if(j<k){
                if(arr[j]>m){
                    m=arr[j];
                    g=j;
                }
                
            }
            else{
                ans.push_back(m);
                i++;
                if(arr[j]>arr[g]){
                m= arr[j];
                g=j;
                }
                else if(arr[j]<arr[g]&& i<=g){
                    m = arr[g];
                }
                
                else{
                    int k = i;
                    m = arr[k];
                    while(k<=j){
                        if(arr[k]>m){
                           m = arr[k];
                           g=k;
                        }
                        k++;
                    }
                }
                
            }
            j++;
        }
        ans.push_back(m);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends