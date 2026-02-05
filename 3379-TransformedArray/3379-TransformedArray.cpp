// Last updated: 2/5/2026, 11:43:15 PM
1class Solution {
2public:
3    vector<int> constructTransformedArray(vector<int>& A) {
4        int n = A.size();
5        
6        vector<int> res;
7        for (int i = 0; i < n; i++)
8            res.push_back(A[(((i + A[i]) % n) + n) % n]);
9
10        return res;
11    }
12};