//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    // code here
        int lar2=0;
        int lar=arr[0];
        int c = 0;
        for(int i=0;i<n;i++){
            if(arr[i]>lar){
                lar2 = lar;
                lar = arr[i];
            }
            else if(arr[i]<lar && arr[i]>lar2){
                lar2 = arr[i];
            }
            if(arr[i]==lar){ 
                c++;
            }
        }
        
        if(c==n && arr[0]!=arr[n-1]){
            lar2 = arr[0];
        }
        if(c==n && arr[0]==arr[n-1]){
            lar2 = -1;
        }
        return lar2;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.print2largest(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends