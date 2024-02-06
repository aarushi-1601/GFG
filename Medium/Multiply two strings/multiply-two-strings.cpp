//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    void additon(vector<int> &ans, vector<int> res, int n)
    {
        int c = 0;
        for(int i= 0; i<n; i++)
        {
            int k = ans[i] + res[i];
            k = k+c;
            ans[i] = k%10;
            c = k/10;
        }
    }
    string multiplyStrings(string s1, string s2) {
        bool flag = true;
        if(s1[0] == '-' and s2[0] != '-')
        {
            s1[0] = '0';
            flag = false;
        }
        if(s2[0] == '-' and s1[0] != '-')
        {
            s2[0] = '0';
            flag = false;
        }
        if(s1[0] == '-' and s2[0] == '-')
        {
            s1[0] = '0';
            s2[0] = '0';
        }  // the above are only for checking the negative value of s1 //and s2 and also convert the '-' to '0' for easy problem solving
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        int m = s1.length();
        int n = s2.length();
        vector<int> ans(m+n,0); // max size of product
        for(int i = 0;i<m; i++)
        {
            vector<int> res(m+n,0); 
            int c = 0;
            int j;
            for(j = 0; j<n; j++)
            {
                int k = (s1[i]-'0')*(s2[j]-'0');
                k = k+c;
                res[i+j] = k%10;
                c = k/10;
            }
            res[i+j] = c; // if any carry left 
            additon(ans,res,m+n);
        }
        reverse(ans.begin(),ans.end());
        string res = "";
        bool f = false;
        for(int i = 0; i<m+n; i++)
        {
            if((f == false) and (ans[i] == 0))
            {
                f = false;
            }
            else
            {
                f = true;
                res = res + (char)(ans[i]+'0');
            }
        }
        if(res.length() == 0)
        return "0";
        if(flag == false)
        {
            res = '-' + res;
        }
        return res;
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends