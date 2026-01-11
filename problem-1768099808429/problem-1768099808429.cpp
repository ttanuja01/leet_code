// Last updated: 1/11/2026, 8:20:08 AM
1class Solution {
2public:
3    int residuePrefixes(string s) {
4        unordered_set<char> seen;
5        int count = 0;
6
7        for (int i = 0; i < s.size(); i++) {
8            seen.insert(s[i]);
9            int mod = (i + 1) % 3;
10
11            // length % 3 == 0 can NEVER be valid
12            if (mod != 0 && seen.size() == mod) {
13                count++;
14            }
15        }
16        return count;
17    }
18};