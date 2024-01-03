//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
    void solve(int n,vector<char>&freq,string &s,vector<string>&ans,string &temp){
        
        if(temp.size()==s.size())
        {
            ans.push_back(temp);
            return;
        }
        
        //conditions
        //iterate over all 
        for(int i=0;i<n;++i)
        {
            if(freq[i]=='0')
            {
                temp.push_back(s[i]);
                freq[i]='1';
                solve(n,freq,s,ans,temp);
                temp.pop_back();
                freq[i]='0';
            }
            
        }
    }
    public:
    //Complete this function
    
    vector<string> permutation(string S)
    {
        //Your code here
         int n=S.size();
       vector<char>freq(n,'0');
       string temp;
       vector<string>ans;
       //{ind,n,freq,S,ans}
       solve(n,freq,S,ans,temp);
       sort(ans.begin(),ans.end());
       return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends