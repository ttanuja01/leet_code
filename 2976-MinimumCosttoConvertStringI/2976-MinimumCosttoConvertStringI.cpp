// Last updated: 1/29/2026, 6:27:33 PM
1#include <vector>
2#include <string>
3#include <algorithm>
4using namespace std;
5
6class Solution {
7public:
8    long long minimumCost(string source, string target,
9 vector<char>& original, vector<char>& changed, vector<int>& cost) {
10        long long dist[26][26];
11        const long long INF = 1e14;
12
13        for (int i = 0; i < 26; ++i) {
14            for (int j = 0; j < 26; ++j) {
15                dist[i][j] = (i == j) ? 0 : INF;
16            }
17        }
18
19        for (size_t i = 0; i < original.size(); ++i) {
20            int u = original[i] - 'a';
21            int v = changed[i] - 'a';
22            dist[u][v] = min(dist[u][v], (long long)cost[i]);
23        }
24
25        for (int k = 0; k < 26; ++k) {
26            for (int i = 0; i < 26; ++i) {
27                if (dist[i][k] == INF) continue;
28                for (int j = 0; j < 26; ++j) {
29                    if (dist[k][j] != INF) {
30                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
31                    }
32                }
33            }
34        }
35
36        long long totalCost = 0;
37        int n = source.length();
38
39        for (int i = 0; i < n; ++i) {
40            int u = source[i] - 'a';
41            int v = target[i] - 'a';
42            if (u == v) continue;
43            if (dist[u][v] == INF) return -1;
44            totalCost += dist[u][v];
45        }
46
47        return totalCost;
48    }
49};