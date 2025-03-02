class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int>m;
        for(int i=0;i<nums1.size();i++){
            m[nums1[i][0]]+=nums1[i][1];
        }
        for(int i=0;i<nums2.size();i++){
            m[nums2[i][0]]+=nums2[i][1];
        }
        vector<vector<int>>res;
        for(auto itr: m){
            vector<int>v;
            v.push_back(itr.first);
            v.push_back(itr.second);
            res.push_back(v);
        }
        return res;
    }
};