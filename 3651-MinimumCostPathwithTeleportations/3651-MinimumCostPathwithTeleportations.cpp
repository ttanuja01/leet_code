// Last updated: 1/29/2026, 6:28:46 PM
1const int M=1e4+1, NN=6400;
2const int INF=1e9+7;
3
4// Using an array version for linked list to replace x_pos[M]
5static int xList[M], nxt[NN];
6
7static unsigned dp[2][NN]; 
8static unsigned suffixMin[M]; 
9
10class Solution {
11public:
12    static inline int idx(int i, int j, int c) { return i*c+j; }
13
14    static int minCost(vector<vector<int>>& grid, int k) {
15        const int r=grid.size(), c=grid[0].size(), N=r*c;
16
17        if (xList[0]!=-1) // fill all with -1 at 1st times
18            memset(xList, -1, sizeof(xList));
19
20        int xMax=0;
21        // Group indices by values of grid
22        for (int i=0; i<r; i++) {
23            for (int j=0; j<c; j++) {
24                const int x=grid[i][j], p=idx(i, j, c);
25                nxt[p]=xList[x];// insert node at 1st place
26                xList[x]=p;
27                if (x>xMax) xMax=x;
28            }
29        }
30
31        //Initialize DP for 0th row
32        fill(dp[0], dp[0]+N, INF);
33
34        dp[0][0]=0;
35        for (int i=0; i<r; i++) {
36            for (int j=0; j<c; j++) {
37                int pos=idx(i, j, c);
38                if (i>0) 
39                    dp[0][pos]=min(dp[0][pos], dp[0][pos-c]+grid[i][j]);
40                if (j>0) 
41                    dp[0][pos]=min(dp[0][pos], dp[0][pos-1]+grid[i][j]);
42            }
43        }
44
45        // DP with t Teleports
46        for (int t=1; t<= k;t++) {
47            // &1 trick used here
48            const bool curr=t&1, prev=(t-1)&1;
49
50            // Compute suffixMin[x] 
51            unsigned currMin=INF;
52            for (int x=xMax; x>=0; x--) {
53                // trasverse the linked list 
54                for (int e=xList[x]; e!=-1; e=nxt[e]) {
55                    currMin=min(currMin, dp[prev][e]);
56                }
57                suffixMin[x]=currMin;// teleport
58            }
59
60            // Update cells for current teleport 
61            for (int i=0; i<r; i++) {
62                for (int j = 0; j < c; j++) {
63                    const int pos=idx(i, j, c);
64                    const int x=grid[i][j];
65
66                    // best result with fewer teleports or by teleport
67                    unsigned best=min(dp[prev][pos], suffixMin[x]);
68
69                    // step from up or Left
70                    if (i>0) best=min(best, dp[curr][pos-c]+x);
71                    if (j>0) best=min(best, dp[curr][pos-1]+x);
72
73                    dp[curr][pos]=best;
74                }
75            }
76        }
77        // Reset for the next test case
78        memset(xList, -1, sizeof(int)*(xMax+1));
79        return dp[k&1][N-1];
80    }
81};