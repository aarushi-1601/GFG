//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
void addtosolution(vector<vector<int>> &ans,vector<vector<int>> &board,int n){
vector<int> tem;
for(int i =0;i<n;i++){
for(int j =0;j<n;j++){
   if(board[j][i])
tem.push_back(j+1);
}
 
}
ans.push_back(tem);
}
bool issafe(int r, int c,vector<vector<int>> &board,int n){
int x=r;
int y =c;
//row checking
while(y>=0){
if(board[x][y] == 1) return false;
y--;
}
//uppar daigonal
x=r;
y =c;
while(x>=0 and y>=0){
if(board[x][y] == 1) return false;
x--;
y--;
}
//lower diagonal
x=r;
y =c;
while(x<n and y>=0){
if(board[x][y] == 1) return false;
x++;
y--;
}
return true;
}
void solve(int col,vector<vector<int>> &ans,vector<vector<int>> &board,int n){
if(col == n){
addtosolution(ans,board,n);
return;
}
for(int r =0;r<n;r++){
                if (issafe(r, col, board, n)) {
                        board[r][col] = 1;
                        solve(col + 1, ans, board, n);
                        board[r][col] = 0;
                }
        }
}
    vector<vector<int>> nQueen(int n) {
       vector<vector<int>> ans;
       vector<vector<int>> ans1(n,vector<int>(1,-1));
       if(n==1){
        vector<vector<int>> ans2(n,vector<int>(1,1)); 
        ans2.resize(1,vector<int>(0));
        return ans2;
       }
       
       ans1.resize(0,vector<int>(0));
       vector<vector<int>>board(n,vector<int>(n,0));
       solve(0,ans,board,n);
       if(n==3||n==2) return ans1;
       return ans;
       
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends