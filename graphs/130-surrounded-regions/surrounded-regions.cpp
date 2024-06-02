class Solution {
public:
    void dfs(vector<vector<char>>& board,vector<vector<char>>& vis,int m,int n,int i,int j){
        if(i<0 || i>=m || j<0 || j>=n)return;
        if(vis[i][j]=='O')return ;
         if(board[i][j]=='X')return ;
        vis[i][j]='O';
        dfs(board,vis,m,n,i+1,j);
        dfs(board,vis,m,n,i-1,j);
        dfs(board,vis,m,n,i,j+1);
        dfs(board,vis,m,n,i,j-1);
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<char>>vis(m,vector<char>(n,'X'));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                 // cout<<((i==0 || i==m-1) &&(j==0 || j==n-1))<<endl;
                if((i==0 || i==m-1) || (j==0 || j==n-1)){
                    if(vis[i][j]=='X' && board[i][j]=='O'){
                        cout<<i<<j<<endl;
                        dfs(board,vis,m,n,i,j);
                    }
                }
            }
        }
        board=vis;
        
        
    }
};