// Last updated: 4/19/2025, 10:12:28 PM
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0;
        int temp=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1)temp++;
            else{
                ans=max(ans,temp);
                temp=0;
            }
        }
         ans=max(ans,temp);
        return ans;
        
    }
};