//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int closestNumber(int N , int M) {
        int rem=N%M;
        if(rem==0) return N;
        
        int i=N,j=N;
        while(true){
            if(i%M==0)
                return i;
                 i--;
            if(j%M==0)
                return j;
                 j++;    
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M;
        
        cin>>N>>M;

        Solution ob;
        cout << ob.closestNumber(N,M) << endl;
    }
    return 0;
}
// } Driver Code Ends