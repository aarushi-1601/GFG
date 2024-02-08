//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    int dfs( int i, int j, vector<vector<bool>>&vis, vector<vector<int>>&grid, int ans)
    {   
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 or j<0 or i>=n or j>=m or grid[i][j]==0 or vis[i][j]==1) return 0;
        vis[i][j]=true;
        grid[i][j]=ans;
        int count= 1+ dfs(i+1, j, vis, grid, ans)+ dfs(i-1, j, vis, grid, ans)+ dfs(i, j+1, vis, grid, ans)+ dfs(i, j-1, vis, grid, ans);
        return count;
    }

    int largestIsland(vector<vector<int>>& grid) 
    {
        //marking areas of connnected components as :2,3,4,5..
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n, vector<bool>(m,false));
        unordered_map<int,int> mp;;
        int name=2;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1 && !vis[i][j])
                {
                    int count = dfs(i,j,vis,grid,name);
                    mp[name]=count;
                    name++;
                }
            }
        }
        
        ///mapping all connected as {area no, count};
        //get 0 where 1 to be added
        int ans=0;
        for( int i=0; i<n; i++)
        {
            for( int j=0; j<m ;j++)
            {
                if( grid[i][j]==0)
                {
                    int d = (i-1>=0) ? grid[i-1][j] : 0;
                    int u = (i+1<n) ? grid[i+1][j] : 0;
                    int l = (j-1>=0) ? grid[i][j-1] : 0;
                    int r = (j+1<m) ? grid[i][j+1] : 0;
                    
                    set<int>s;
                    s.insert(d);
                    s.insert(u);s.insert(l);s.insert(r);
                    int res=1;
                    for(int val: s){
                        res=res + mp[val];
                    }
                    ans=max(ans, res);
                }
            }
        }
        if(ans==0) return n*m;
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    }
    return 0;
}

// } Driver Code Ends