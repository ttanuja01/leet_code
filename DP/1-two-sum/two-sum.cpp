class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>m;
        vector<int>v;
        for(int i=0;i<nums.size();i++)
        {
            int k=target-nums[i];
            if(m.find(k)!=m.end())
            {
               v.push_back(m[k]);
                v.push_back(i);
            }
            m[nums[i]]=i;
        }
        return v;
    }
};