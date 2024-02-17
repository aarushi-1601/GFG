//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	string removeDups(string S) 
	{
	    // Your code goes here
	    vector<char>ans;
	   int i=0;
	   while(i<S.length()){
	       
	       if( find(ans.begin(),ans.end(),S[i]) != ans.end()){
	           i++;
	           
	       }
	       else{
	           ans.push_back(S[i]);
	           i++;
	       }
	   }
	   
	   string l="";
	   for(int i=0;i<ans.size();i++){
	       l+=ans[i];
	   }
	   return l;
	}
};

//{ Driver Code Starts.


int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   		
   		Solution ob;
   		cout << ob.removeDups(s) << "\n";
   		
   	}

    return 0;
}
// } Driver Code Ends