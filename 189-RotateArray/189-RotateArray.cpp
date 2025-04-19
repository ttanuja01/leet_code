// Last updated: 4/19/2025, 10:07:35 PM
class Solution {
public:
    void rv(vector<int>& nums, int i,int j){
        while(i<=j){
            int t=nums[i];
            nums[i]=nums[j];
            nums[j]=t;
            i++;
            j--;
        }

    }
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        rv(nums,0,nums.size()-1);
        rv(nums,0,k-1);
        rv(nums,k,nums.size()-1);
    }
};