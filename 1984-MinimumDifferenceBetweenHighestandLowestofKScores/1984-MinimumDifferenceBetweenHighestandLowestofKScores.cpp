// Last updated: 1/25/2026, 6:27:43 PM
1class Solution {
2public:
3    int minimumDifference(vector<int>& nums, int k) {
4        sort(nums.begin(),nums.end());
5        int i=0,n=nums.size(),j=k-1;
6        int ans=INT_MAX;
7        while(j<n){
8            ans=min(ans,nums[j]-nums[i]);
9            i++;
10            j++;
11        } 
12        return ans;
13    }
14};
15
16// 1 3 4 6 7 9
17// 9 7 6 4 3 1
18