// Last updated: 5/18/2025, 11:33:32 AM
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        int m= og.size();
        int n= og[0].size();
          if (og[0][0] == 1 || og[m - 1][n - 1] == 1) return 0;
                vector<vector<int>> v(m, vector<int>(n, 0));
                v[0][0]=1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(og[i][j]==0){
                        if (i > 0) v[i][j] += v[i - 1][j];
            if (j > 0) v[i][j] += v[i][j - 1];
                }

            }
        }
        return v[m-1][n-1];
        
    }
};