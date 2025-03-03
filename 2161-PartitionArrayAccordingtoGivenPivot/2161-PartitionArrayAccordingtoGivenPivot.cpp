class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n =nums.size();
        int npivots=0;
        vector<int>res;
        for(int i=0;i<n;i++){
            if(nums[i]==pivot)npivots++;
            else if(nums[i]<pivot)res.push_back(nums[i]);
        }
        while(npivots--)res.push_back(pivot);
         for(int i=0;i<n;i++){
            if(nums[i]>pivot)res.push_back(nums[i]);
        }
        return res;
        
    }
};