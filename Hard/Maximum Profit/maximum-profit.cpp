//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        // code here
        vector<int> curr(2*K+1,0);
        vector<int> next(2*K+1,0);
        for(int index = N-1; index >= 0; index--){
            for(int operationNo = 0; operationNo < 2*K; operationNo++){
                int profit = 0;
                if(operationNo % 2 == 0){
                    int buynow = -A[index] + next[operationNo+1];
                    int skipnow = 0 + next[operationNo];
                    profit = max(buynow,skipnow);
                } else {
                    int sellnow = A[index] + next[operationNo+1];
                    int skipnow = 0 + next[operationNo];
                    profit = max(sellnow,skipnow);
                }
                curr[operationNo] = profit;
            }
            next = curr;
        }
        return next[0];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends