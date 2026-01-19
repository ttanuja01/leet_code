// Last updated: 1/19/2026, 10:36:12 PM
1class Solution {
2public:
3    int getRect(const vector<vector<int>>& P, int x1, int y1, int x2, int y2) {
4        return P[x2][y2] - P[x1 - 1][y2] - P[x2][y1 - 1] + P[x1 - 1][y1 - 1];
5    }
6
7    int maxSideLength(vector<vector<int>>& mat, int threshold) {
8        int m = mat.size(), n = mat[0].size();
9        vector<vector<int>> P(m + 1, vector<int>(n + 1));
10        for (int i = 1; i <= m; ++i) {
11            for (int j = 1; j <= n; ++j) {
12                P[i][j] = P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1] +
13                          mat[i - 1][j - 1];
14            }
15        }
16
17        int r = min(m, n), ans = 0;
18        for (int i = 1; i <= m; ++i) {
19            for (int j = 1; j <= n; ++j) {
20                for (int c = ans + 1; c <= r; ++c) {
21                    if (i + c - 1 <= m && j + c - 1 <= n &&
22                        getRect(P, i, j, i + c - 1, j + c - 1) <= threshold) {
23                        ++ans;
24                    } else {
25                        break;
26                    }
27                }
28            }
29        }
30        return ans;
31    }
32};