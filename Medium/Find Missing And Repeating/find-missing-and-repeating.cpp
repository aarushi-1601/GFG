//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        vector<int>v(n,0);
       int miss = 0; 
        int repeat = 0; 

        for(int i=0;i<n;i++){
            v[arr[i]-1]++;
        }
        for(int i=0;i<n;i++){
            if(v[i]==0){
                miss=i+1;
            }
            else if(v[i]==2){
                repeat=i+1;
            }
        }

        return {repeat, miss};
    
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends