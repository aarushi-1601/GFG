//{ Driver Code Starts
// C++ program to calculate sum of all numbers present
// in a string containing alphanumeric characters
#include <iostream>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate sum of all numbers present in a string.
    int findSum(string str)
    {
    	int num=0, res=0;
    	for(int i=0; i<str.length(); i++){
    	    while(isdigit(str[i])){
    	        res=res*10+str[i]-'0';
    	        i++;
    	    }
    	    num+=res;
    	    res=0;
    	}
    	return num;
    	// Your code here
    	
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
	// input alphanumeric string
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution obj;
	    cout << obj.findSum(str);
        cout<<endl;
	}
	return 0;
}

// } Driver Code Ends