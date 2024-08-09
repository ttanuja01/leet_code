class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>m;
        vector<int>v;
        for(int i=0;i<nums.size();i++)
        {
            int k=target-nums[i];
            if(m[k])
            {
               v.push_back(m[k]-1);
                v.push_back(i);
            }
            m[nums[i]]=i+1;
        }
        return v;
    }
};