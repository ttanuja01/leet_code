// Last updated: 5/13/2025, 5:55:33 PM
class Solution {
public:
   void generatesubsets(  vector<vector<int>>& ans,int n,int i,vector<int>& nums,vector<int>temp) {
        if(i==n){
            ans.push_back(temp);
            return;
        }
        generatesubsets(ans,n,i+1,nums,temp);
        temp.push_back(nums[i]);
        generatesubsets(ans,n,i+1,nums,temp);
    return ;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        generatesubsets(ans,nums.size(),0,nums,temp);
        return ans;
        
    }
};