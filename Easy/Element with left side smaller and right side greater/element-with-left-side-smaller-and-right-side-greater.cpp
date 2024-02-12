//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findElement(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) cin >> a[i];
        cout << findElement(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends


int findElement(int arr[], int n) {
    vector<int> greater(n,arr[n-1]);
    for(int i=n-2; i>=0; i--)
        greater[i] = min(greater[i+1], arr[i]);
    for(int i=1; i<n-1; i++) {
        if(arr[i] >= arr[i-1] && arr[i] <= greater[i+1])
            return arr[i];
        arr[i] = max(arr[i-1], arr[i]);
    }
    return -1;
}