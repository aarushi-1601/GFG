//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
  public:
    int minDist(int a[], int n, int x, int y) {
        // code here
         vector<int> v1,v2;
        for(int i=0;i<n;i++){
            if(a[i]==x) v1.push_back(i);
            if(a[i]==y) v2.push_back(i);
        }
        if(!v1.size() or !v2.size()) return -1;
        int min=INT_MAX;
        for(int i=0;i<v1.size();i++){
            for(int j=0;j<v2.size();j++){
                if(abs(v2[j]-v1[i])<min) min=abs(v2[j]-v1[i]);
                if(v2[j]-v1[i]>min) break;
            }
        }
        return min;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}

// } Driver Code Ends