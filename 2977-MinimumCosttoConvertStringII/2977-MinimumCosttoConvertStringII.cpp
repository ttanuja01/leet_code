// Last updated: 1/31/2026, 12:38:11 AM
1class Solution {
2public:
3    static const unsigned long long INF = ULLONG_MAX;
4    unsigned long long dist[201][201];
5    unsigned long long dp[1001];
6
7    unordered_map<string, int> id;
8    unordered_set<int> lens;
9
10    long long minimumCost(string source, string target,
11                          vector<string>& original,
12                          vector<string>& changed,
13                          vector<int>& cost) {
14
15        int m = original.size();
16        int n = source.size();
17
18        id.clear();
19        lens.clear();
20
21        int sz = 0;
22        memset(dist, 255, sizeof(dist));
23
24        for (int i = 0; i < m; i++) {
25            if (!id.count(original[i])) {
26                id[original[i]] = sz++;
27                lens.insert(original[i].size());
28            }
29            if (!id.count(changed[i])) {
30                id[changed[i]] = sz++;
31            }
32            int u = id[original[i]];
33            int v = id[changed[i]];
34            dist[u][v] = min(dist[u][v], (unsigned long long)cost[i]);
35        }
36
37        for (int i = 0; i < sz; i++) dist[i][i] = 0;
38
39        for (int k = 0; k < sz; k++)
40            for (int i = 0; i < sz; i++)
41                if (dist[i][k] != INF)
42                    for (int j = 0; j < sz; j++)
43                        if (dist[k][j] != INF)
44                            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
45
46        memset(dp, 255, sizeof(dp));
47        dp[0] = 0;
48
49        for (int i = 0; i < n; i++) {
50            if (dp[i] == INF) continue;
51
52            if (source[i] == target[i])
53                dp[i + 1] = min(dp[i + 1], dp[i]);
54
55            for (int L : lens) {
56                if (i + L > n) continue;
57
58                string s = source.substr(i, L);
59                string t = target.substr(i, L);
60
61                if (id.count(s) && id.count(t)) {
62                    unsigned long long d = dist[id[s]][id[t]];
63                    if (d != INF)
64                        dp[i + L] = min(dp[i + L], dp[i] + d);
65                }
66            }
67        }
68
69        return dp[n] == INF ? -1 : dp[n];
70    }
71};