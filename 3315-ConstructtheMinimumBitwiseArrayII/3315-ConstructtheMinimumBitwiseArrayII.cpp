// Last updated: 1/21/2026, 8:40:13 PM
1class Solution {
2public:
3    vector<int> minBitwiseArray(vector<int>& nums) {
4        vector<int> sol;
5        for(auto x : nums){
6            if(x % 2 == 0){
7                sol.push_back(-1);
8            }
9            else{
10                int t = 0;
11                while(x & (1 << t)) t ++;
12                sol.push_back(x ^ (1 << (t - 1)));
13            }
14        }
15        return sol;
16    }
17};