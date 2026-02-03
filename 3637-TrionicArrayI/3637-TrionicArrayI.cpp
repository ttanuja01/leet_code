// Last updated: 2/3/2026, 11:37:38 PM
1class Solution {
2public:
3    bool isTrionic(vector<int>& nums) {
4        int n = nums.size(), i = 0;
5
6        while (i + 1 < n && nums[i] < nums[i + 1]) i++;
7        if (i == 0 || i == n - 1) return false;
8        
9        int p = i;
10
11        while (i + 1 < n && nums[i] > nums[i + 1]) i++;
12        if (i == p || i == n - 1) return false;
13        
14
15        while (i + 1 < n && nums[i] < nums[i + 1]) i++;
16        return i == n - 1;
17    }
18};