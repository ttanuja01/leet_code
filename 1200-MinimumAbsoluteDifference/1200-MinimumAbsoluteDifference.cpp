// Last updated: 1/26/2026, 5:10:10 PM
1class Solution {
2public:
3    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
4        sort(arr.begin(),arr.end());
5        int ans=INT_MAX;
6        for(int i=1;i<arr.size();i++){
7            ans=min(ans,arr[i]-arr[i-1]);
8        }
9vector<vector<int>>res;
10         for(int i=1;i<arr.size();i++){
11            if(arr[i]-arr[i-1]==ans){
12                vector<int>v;
13                v.push_back(arr[i-1]);
14                v.push_back(arr[i]);
15                 res.push_back(v);
16            }
17           
18        }
19        return res;
20    
21    }
22};