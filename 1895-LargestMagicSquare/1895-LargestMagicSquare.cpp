// Last updated: 1/18/2026, 12:51:56 PM
1class Solution {
2public:
3    int largestMagicSquare(vector<vector<int>>& grid) {
4        int m = grid.size();
5        int n = grid[0].size();
6
7        vector<vector<int>> rSum(m, vector<int>(n, 0));
8        vector<vector<int>> cSum(m, vector<int>(n, 0));
9
10        for (int i = 0; i < m; i++) {
11            for (int j = 0; j < n; j++) {
12                if (j == 0) {
13                    rSum[i][j] = grid[i][j];
14                } else {
15                    rSum[i][j] = rSum[i][j - 1] + grid[i][j];
16                }
17            }
18        }
19        for (int i = 0; i < m; i++) {
20            for (int j = 0; j < n; j++) {
21                if (i == 0) {
22                    cSum[i][j] = grid[i][j];
23                } else {
24                    cSum[i][j] = cSum[i - 1][j] + grid[i][j];
25                }
26            }
27        }
28
29        for (int side = min(m, n); side >= 2; side--) {
30            for (int i = 0; i+side <= m; i++) {
31                for (int j = 0; j+side <= n; j++) {
32                    bool allSame = true;
33                    int rowSum =
34                        rSum[i][j + side - 1] - (j > 0 ? rSum[i][j - 1] : 0);
35                    for (int k = i + 1; k < i + side; k++) {
36                        int sum = rSum[k][j + side - 1] - (j > 0 ? rSum[k][j - 1] : 0);
37                        if (sum !=rowSum) {
38                            allSame = false;
39                            break;
40                        }
41                    }
42                    if (!allSame)
43                        continue;
44
45                    int colSum =
46                        cSum[i + side - 1][j] - (i > 0 ? cSum[i - 1][j] : 0);
47                        if(rowSum!=colSum)continue;
48                    for (int k = j + 1; k < j + side; k++) {
49                        int sum = cSum[i+side-1][k] -(i > 0 ? cSum[i - 1][k] : 0);
50                        if (sum != colSum) {
51                            allSame = false;
52                            break;
53                        }
54                    }
55                    if (!allSame)
56                        continue;
57                    int diag=0,antidiag=0;
58                    for(int k=0;k<side;k++){
59                        diag+=grid[i+k][j+k];
60                        antidiag+=grid[i+k][j+side-1-k];
61                    }
62                    if(rowSum == diag && antidiag ==rowSum)return side;
63
64                }
65            }
66        }
67
68        return 1;
69    }
70};