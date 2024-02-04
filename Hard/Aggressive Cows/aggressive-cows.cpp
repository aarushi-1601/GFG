//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
     bool check(vector<int>& stalls,int dist, int k)
    {
        int countCows = 1;
        int last = stalls[0];
        
        for(int i = 1;i<stalls.size();i++)
        {
            if(stalls[i]-last >= dist)
            {
                countCows++;
                last = stalls[i];
            }
        }
        if(countCows >= k)
        {
            return true;
        }
        return false;
    }
    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(),stalls.end());
        int start = 0;
        int end = stalls[n-1] - stalls[0];
        int ans = 1;
        while(start <= end)
        {
            int mid = (start+end)/2;
            
            if(check(stalls,mid,k) == true)
            {
                ans = mid;
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends