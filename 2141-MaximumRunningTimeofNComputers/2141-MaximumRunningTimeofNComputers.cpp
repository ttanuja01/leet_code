// Last updated: 12/1/2025, 6:23:19 PM
1class Solution {
2public:
3    long long maxRunTime(int n, vector<int>& batteries) {
4        long long totalEnergy = 0;
5        for (int b : batteries) totalEnergy += b;
6
7        sort(batteries.begin(), batteries.end());
8
9        for (int i = batteries.size() - 1; i >= 0; i--) {
10            if (batteries[i] > totalEnergy / n) {
11                totalEnergy -= batteries[i];
12                n--;
13            } else break;
14        }
15
16        return totalEnergy / n;
17    }
18};