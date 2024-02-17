//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
  public:
   vector <int> countDistinct (int A[], int n, int k)  {
    vector<int> result;
    unordered_map<int, int> freq;
    int dist = 0;
    for(int i=0; i<k; i++) {
        if(++freq[A[i]] == 1)
            ++dist;
    }
    result.push_back(dist);
    for(int i=k; i<n; i++) {
        if(--freq[A[i-k]] == 0)
            --dist;
        if(++freq[A[i]] == 1)
            ++dist;
        result.push_back(dist);
    }
    return result;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends