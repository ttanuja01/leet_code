// Last updated: 3/1/2026, 9:01:27 PM
1class Solution {
2public:
3
4    void dfs(vector<vector<char>>& grid,vector<vector<int>>& vis,int i,int j,int m,int n){
5        if(i<0 || i>=m || j<0 ||j>=n || vis[i][j]==1 || grid[i][j]=='0') return ;
6        vis[i][j]=1;
7        dfs(grid,vis,i+1,j,m,n);
8         dfs(grid,vis,i-1,j,m,n);
9          dfs(grid,vis,i,j+1,m,n);
10           dfs(grid,vis,i,j-1,m,n);
11           return ;
12
13    }
14    int numIslands(vector<vector<char>>& grid) {
15        int m=grid.size(),n=grid[0].size();
16        int ans=0;
17        vector<vector<int>> vis(m, vector<int>(n,0));
18
19        for(int i=0;i<m;i++){
20            for(int j=0;j<n;j++){
21                if(vis[i][j]==0 && grid[i][j]=='1'){
22                    ans++;
23                    dfs(grid,vis,i,j, m, n);
24                }
25            }
26        }
27        return ans;
28        
29    }
30};