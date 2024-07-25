class Solution {
public:
vector<vector<int>>m;
    void printsubsequence(vector<int>&v,vector<int>& nums,int i, int n){


        if(i>=n) {
            m.push_back(v);
        return ;}
        printsubsequence(v,nums,i+1,n);
        v.push_back(nums[i]);
        printsubsequence(v,nums,i+1,n);
        v.pop_back();
return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>v;
        int n=nums.size();
         printsubsequence(v,nums,0,n);
         return m;
        
    }
};