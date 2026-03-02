// Last updated: 3/2/2026, 8:28:37 PM
1class Solution {
2public:
3    vector<int> topKFrequent(vector<int>& nums, int k) {
4     vector<int>v;
5     unordered_map<int,int>m;
6     priority_queue<pair<int,int>>pq;
7     for(int i=0;i<nums.size();i++){
8        m[nums[i]]++;
9     }
10    for(auto i:m){
11        pq.push({i.second,i.first});
12    }
13    while(pq.size()>0 && k){
14        v.push_back(pq.top().second);
15        pq.pop();
16        k--;
17    }
18     return v;   
19    }
20};