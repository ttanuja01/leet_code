// Last updated: 5/15/2025, 11:11:16 AM
class Solution {
public:
    void generateSUbSets(vector<int>& nums,int n ,int i, vector<vector<int>>&ans,   vector<int> temp){
        if(i>=n){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
         generateSUbSets(nums,n,i+1,ans,temp);
         temp.pop_back();
        generateSUbSets(nums,n,i+1,ans,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        generateSUbSets(nums,nums.size(),0,ans,temp);
        return ans;
        
    }
};