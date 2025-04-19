// Last updated: 4/19/2025, 9:59:28 PM
class Solution {
public:
    bool check(vector<int>& nums) {
         int count = 0;
    int n = nums.size();

    for (int i = 0; i < n; ++i) {
        // Compare current element with next, wrapping around
        if (nums[i] > nums[(i + 1) % n]) {
            count++;
            if (count > 1) return false;
        }
    }

    return true;
    }
};
// 3 4 5 6 8 7 2 1 3 4