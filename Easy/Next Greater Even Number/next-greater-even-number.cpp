//{ Driver Code Starts
#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long getNextEven(string x)
    {
        long long c=stoll(x);
        while(next_permutation(x.begin(), x.end())){
            int t=x[x.length()-1]-'0';
            if(t%2==0 && stoll(x)>c){
                return stoll(x);
            }
        }
        return -1;
        // Your code goes here   
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin >> t;
	while(t--){
    	string x;
    	cin >> x;
    	Solution ob;
        cout<< ob.getNextEven(x) <<endl;
	}
	
	return 0;
}
// } Driver Code Ends