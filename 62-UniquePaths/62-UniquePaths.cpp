// Last updated: 5/18/2025, 8:40:55 AM
class Solution {
public:
    int findAllUniquePaths(int i, int j, int m, int n, int& c,
                           vector<vector<int>>& v) {
        if (i < 0 || j < 0)
            return 0;
        if (v[i][j] != 0)
            return v[i][j];
        if (i == 0 && j == 0) {
            return v[i][j] = 1;
        }
        return v[i][j] = findAllUniquePaths(i - 1, j, m, n, c, v) +
                         findAllUniquePaths(i, j - 1, m, n, c, v);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> v(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                v[i][j]=v[i-1][j]+v[i][j-1];

            }
        }
        return v[m-1][n-1];
    }
};
// 1 0
// 0 0
// 0 1
