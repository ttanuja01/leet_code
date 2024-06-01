class Solution {
public:
    void dfs(vector<vector<int>>& img,int i,int j,int c,int m ,int n,vector<vector<int>>& vis,int val){ 
        if(i<0 || j<0)return ;
        if(i>=m || j>=n)return ;
        if(img[i][j]!=val || vis[i][j]==1) return ;
       
        vis[i][j]=1;
         img[i][j]=c;
        dfs(img,i+1,j,c,m,n,vis,val);
          dfs(img,i-1,j,c,m,n,vis,val);
          dfs(img,i,j+1,c,m,n,vis,val);
          dfs(img,i,j-1,c,m,n,vis,val);
        
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m =image.size();
        int n =image[0].size();
           std::vector<std::vector<int>> vis(m, std::vector<int>(n, 0));
        // if(image[0][0]==0)return vis;
        dfs(image,sr,sc,color,m,n,vis,image[sr][sc]);
        return image;
    }
};