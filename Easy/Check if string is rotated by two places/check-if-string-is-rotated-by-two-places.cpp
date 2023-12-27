//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        // Your code here
         int n1= str1.length();
        int n2= str2.length();
        if(str1[0]==str2[n2-2] || str1[n1-2]==str2[0]){
            if(str1[1]==str2[n2-1] || str1[n1-1]==str2[1]){
                if(str1.substr(0, n1-2)==str2.substr(2, n2-2) ||  str1.substr(2, n1-2)== str2.substr(0, n2-2))
                    return true;
                
            }
        }
        return false;
    }

};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends