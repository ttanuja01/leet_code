// Last updated: 4/23/2025, 6:27:01 PM
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
      
        while(s<=e){
            int m=(s+e)/2;
            int middleEle= nums[m];
            if(middleEle==target)return m;
            else if(middleEle>target){
                e=m-1;
            }else{
                s=m+1;
            }   
        }
        return -1;
        
    }
};