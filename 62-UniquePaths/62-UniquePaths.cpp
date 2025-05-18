// Last updated: 5/18/2025, 8:33:53 AM
class Solution {
public:
    int findAllUniquePaths(int i,int j,int m,int n,int &c, vector<vector<int>>&v){
        if(i<0 || j<0)return 0;
        if(v[i][j]!=0)return v[i][j];
        if(i==0 && j==0){
            return v[i][j]=1;
        }
        return v[i][j]= findAllUniquePaths(i-1,j,m,n,c,v)+ findAllUniquePaths(i,j-1,m,n,c,v);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>v(m,vector<int>(n,0));
        int count=0;
       return findAllUniquePaths(m-1,n-1,m,n,count,v);
        // return count;
    }
};
// 1 0
// 0 0
// 0 1
