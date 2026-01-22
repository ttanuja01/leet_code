// Last updated: 1/23/2026, 12:24:29 AM
1class Solution {
2private:
3    bool isSorted(vector<int>& nums, int n) {
4        for(int i = 1; i < n; i++) {
5            if(nums[i] < nums[i - 1]) return false;
6        }
7        return true;
8    }
9public:
10    int minimumPairRemoval(vector<int>& nums) {
11        int ans = 0, n = nums.size();
12        while(!isSorted(nums, n)) {
13            ans += 1;
14            int min_sum = INT_MAX, pos = -1;
15            for(int i = 1; i < n; i++) {
16                int sum = nums[i - 1] + nums[i];
17                if(sum < min_sum) {
18                    min_sum = sum;
19                    pos = i;
20                }
21            }
22            nums[pos - 1] = min_sum;
23            for(int i = pos; i < n - 1; i++) nums[i] = nums[i + 1];
24            n--;
25        }
26        return ans;
27    }
28};