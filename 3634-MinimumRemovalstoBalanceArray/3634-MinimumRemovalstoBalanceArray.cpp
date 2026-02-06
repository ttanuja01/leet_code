// Last updated: 2/6/2026, 11:37:31 PM
1class Solution {
2public:
3    using ll = long long;
4    static int minRemoval(vector<int>& nums, int k) {
5        sort(nums.begin(), nums.end());
6        if ((ll)nums[0]*k>=nums.back()) return 0;
7        const int n=nums.size();
8        int ans=n;
9        // Initialize r by binary search
10        for (int l=0, r=upper_bound(nums.begin(), nums.end(), nums[0]*k)-nums.begin()-1; r<n; r++) {
11
12            ll target=(nums[r]+k-1)/k;
13            // replace while loop
14            l=lower_bound(nums.begin()+l, nums.begin()+r+1, target)-nums.begin();
15            ans=min(ans, n-(r-l+1));
16        }
17        return ans;
18    }
19};