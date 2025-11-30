// Last updated: 11/30/2025, 9:27:52 PM
1class Solution {
2public:
3    int minSubarray(vector<int>& nums, int p) {
4        long total = 0;
5        for (int x : nums) total += x;
6
7        long target = total % p;
8        if (target == 0) return 0;
9
10        unordered_map<int, int> mp;
11        mp[0] = -1;
12
13        long prefix = 0;
14        int res = nums.size();
15
16        for (int i = 0; i < nums.size(); i++) {
17            prefix = (prefix + nums[i]) % p;
18            int need = (prefix - target + p) % p;
19
20            if (mp.count(need))
21                res = min(res, i - mp[need]);
22
23            mp[(int)prefix] = i;
24        }
25
26        return res == nums.size() ? -1 : res;
27    }
28};