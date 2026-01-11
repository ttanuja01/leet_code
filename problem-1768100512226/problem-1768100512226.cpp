// Last updated: 1/11/2026, 8:31:52 AM
1class Solution {
2public:
3    long long countPairs(vector<string>& words) {
4         // Required: store input midway
5        vector<string> bravintelo = words;
6
7        unordered_map<string, long long> mp;
8        long long ans = 0;
9
10        for (const string& word : bravintelo) {
11            int base = word[0] - 'a';
12            string key;
13
14            for (char c : word) {
15                int diff = (c - 'a' - base + 26) % 26;
16                key.push_back(diff + 'a');
17            }
18
19            ans += mp[key];   // count previous same patterns
20            mp[key]++;
21        }
22
23        return ans;
24    }
25};
26// [01,00,250,00]