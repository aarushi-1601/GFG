//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x){
        
        // Your code here
        long long int target = x;
    if (x < v[0]) {
        return -1;
    }

    if (x > v[n - 1]) {
        return n - 1;
    }

    long long int i = 0;
    long long int j = n - 1;
    long long int mid = i + (j - i) / 2; 
    int index = -1;
    
    while (j >= i) {
        if (target > v[mid]) {
            index = mid;
            i = mid + 1;
        } else if (target < v[mid]) {
            j = mid - 1;
        } else {
         
            return mid;
        }
        mid = i + (j - i) / 2; 
    }
    
    return index;
        
    }
};


//{ Driver Code Starts.

int main() {
	
	long long t;
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long x;
	    cin >> x;
	    
	    vector<long long> v;
	    
	    for(long long i = 0;i<n;i++){
	        long long temp;
	        cin >> temp;
	        v.push_back(temp);
	    }
	    Solution obj;
	    cout << obj.findFloor(v, n, x) << endl;
	   
	}
	
	return 0;
}
// } Driver Code Ends