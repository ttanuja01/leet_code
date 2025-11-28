// Last updated: 11/28/2025, 6:05:33 PM
1class Solution {
2public:
3    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
4        vector<vector<int> > G(n);
5        for(auto edge : edges){
6            G[edge[0]].push_back(edge[1]);
7            G[edge[1]].push_back(edge[0]);
8        }
9        stack <int> S;
10        vector<int> parent(n);
11        
12        auto DFS = [&](int u, int p, auto &&DFS) -> void{
13            parent[u] = p;
14            S.push(u);
15            for(auto v : G[u]){
16                if(v == p) continue;
17                DFS(v, u, DFS);
18            }
19        };
20        DFS(0, -1, DFS);
21        vector<long long> sum(n);
22        for(int i = 0; i < n; i ++){
23            sum[i] = values[i];
24        }
25        int ans = 0;
26        while(!S.empty()){
27            int u = S.top();
28            S.pop();
29            if(sum[u] % k == 0){
30                ans += 1;
31            }
32            else{
33                sum[parent[u]] += sum[u];
34            }
35        }
36        return ans;
37    }
38};