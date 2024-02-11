//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int evenlyDivides(int N){
      int len=floor(log10(N)+1); 
      int count=0;
      int num;
      int temp=N; 
      for(int i=len;i>0;i--)  
      {
           num=temp%10;
           if(num!=0 && N%num==0)
           {
                count=count+1; 
                
            }
            temp=temp/10; 
       }
        return count;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.evenlyDivides(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends