class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>v;
        if(nums.size()==0)return v;
        v.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            v.push_back(v[i-1]+nums[i]);
            
        }
        return v;
        
    }
};