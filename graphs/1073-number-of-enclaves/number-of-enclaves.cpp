class Solution {
public:
    void dfs(vector<vector<int>>& board,vector<vector<int>>& vis,int m,int n,int i,int j){
        if(i<0 || i>=m || j<0 || j>=n)return;
        if(vis[i][j]==1)return ;
         if(board[i][j]==0)return ;
        vis[i][j]=1;
        dfs(board,vis,m,n,i+1,j);
        dfs(board,vis,m,n,i-1,j);
        dfs(board,vis,m,n,i,j+1);
        dfs(board,vis,m,n,i,j-1);
    }
    int numEnclaves(vector<vector<int>>& board) {
         int m=board.size();
        int n=board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                 // cout<<((i==0 || i==m-1) &&(j==0 || j==n-1))<<endl;
                if((i==0 || i==m-1) || (j==0 || j==n-1)){
                    if(vis[i][j]==0 && board[i][j]==1){
                        // cout<<i<<j<<endl;
                        dfs(board,vis,m,n,i,j);
                    }
                }
            }
        }
        int c=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                 // cout<<((i==0 || i==m-1) &&(j==0 || j==n-1))<<endl;
                // if((i==0 || i==m-1) || (j==0 || j==n-1)){
                    if(vis[i][j]==0 && board[i][j]==1){
                        // cout<<i<<j<<endl;
                        c++;
                    }
                // }
            }
        }
        return c;
       
        
    }
};