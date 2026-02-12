// Last updated: 2/12/2026, 6:49:21 PM
1class Solution {
2public:
3    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
4        int n = size(arr), r = lower_bound(begin(arr), end(arr) - k, x) - begin(arr), l= r - 1;
5        while(k--){
6            if(r>=n || (l>=0 && (x- arr[l]<=arr[r]-x)))l--;
7            else r++;
8        }
9        return vector<int>(begin(arr) + l + 1, begin(arr) + r);
10    }
11};