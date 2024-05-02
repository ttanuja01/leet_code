class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int,int>m;
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            if(m[0-nums[i]]>0){
                if(nums[i]<0)nums[i]*=-1;
                ans=max(ans,nums[i]);
            }else{
                m[nums[i]]++;
            }
        }
        return ans;
        
    }
};