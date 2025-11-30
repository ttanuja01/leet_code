// Last updated: 11/30/2025, 8:06:54 AM
1class Solution {
2public:
3    int maxDistinct(string s) {
4        int sum=0;
5        unordered_map<char,int>m;
6        for(int i=0;i<s.length();i++){
7            m[s[i]]++;
8        }
9        // cout<<m.size();
10        return m.size();
11        
12    }
13};