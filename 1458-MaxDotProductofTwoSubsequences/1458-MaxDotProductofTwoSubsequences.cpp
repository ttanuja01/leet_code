// Last updated: 1/8/2026, 10:15:19 PM
1class Solution {
2public:
3    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
4        int n = nums1.size();
5        int m = nums2.size();
6        
7        if (m > n) {
8            return maxDotProduct(nums2, nums1);
9        }
10        
11        vector<int> dp(m + 1, -1e9);
12        
13        for (int i = 1; i <= n; ++i) {
14            int prev_diag = -1e9;
15            
16            for (int j = 1; j <= m; ++j) {
17                int curr_product = nums1[i-1] * nums2[j-1];
18                int temp = dp[j];
19                
20                dp[j] = max({
21                    curr_product,
22                    curr_product + prev_diag,
23                    dp[j],
24                    dp[j-1]
25                });
26                
27                prev_diag = temp;
28            }
29        }
30        
31        return dp[m];
32    }
33};