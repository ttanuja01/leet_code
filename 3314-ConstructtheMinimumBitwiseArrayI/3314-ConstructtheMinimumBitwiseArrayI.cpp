// Last updated: 1/20/2026, 10:54:37 PM
1class Solution {
2public:
3    vector<int> minBitwiseArray(vector<int>& nums) {
4        vector<int> res;
5        for (auto& n : nums) {
6            if (n & 1) {
7                auto z = ((n + 1) & ~n) >> 1;
8                res.push_back(n & ~z);
9            } else
10                res.push_back(-1);
11        }
12        return res;
13    }
14};