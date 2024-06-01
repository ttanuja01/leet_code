class Solution {
public:
    void dfs(vector<vector<char>>&grid,vector<vector<int>>&vis,int m,int n,int i,int j){
        if(i<0 || j<0)return ;
        if(i>=m || j>=n) return ;
        if(grid[i][j]=='0' || vis[i][j]==1)return ;
         vis[i][j]=1;
                    dfs(grid,vis,m,n,i-1,j);
                     dfs(grid,vis,m,n,i+1,j);
                          dfs(grid,vis,m,n,i,j-1);
                          dfs(grid,vis,m,n,i,j+1);
    }

    int numIslands(vector<vector<char>>& grid) {
      
    int ans=0;
        int m=grid.size();
        int n =grid[0].size();
           std::vector<std::vector<int>> vis(m, std::vector<int>(n, 0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    ans+=1;
                  dfs(grid,vis,m,n,i,j);
                }
}
           
        }
        return ans;
        
    }
};