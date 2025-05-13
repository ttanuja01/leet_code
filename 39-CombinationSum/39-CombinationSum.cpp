// Last updated: 5/13/2025, 6:14:32 PM
class Solution {
public:
   void generatesubsets(  vector<vector<int>>& ans,int n,int i,vector<int>& nums,vector<int>temp,int k,int currSum) {
            if(currSum==k){
            ans.push_back(temp);
            return;
        }
        if(currSum>k || i>=n){
            return;
        }
        temp.push_back(nums[i]);
        generatesubsets(ans,n,i,nums,temp,k,currSum+nums[i]);
        temp.pop_back();
        generatesubsets(ans,n,i+1,nums,temp,k,currSum);
    return ;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         vector<vector<int>>ans;
        vector<int>temp;
        generatesubsets(ans,candidates.size(),0,candidates,temp,target,0);
        return ans;
    }
};