class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int mind = INT_MAX;
        int val =nums[0];
        for(int i=0;i<nums.size();i++){
            int d;
            if(nums[i]>0){
               d=nums[i];
            }else{
                d=-1*nums[i];
            }
            if(d<=mind ){
                if(d==mind){
                    val=max(val,nums[i]);
                }
                else{
                    val=nums[i];
                }
                 mind=d;
                
            }
        }
        return val;
        
    }
};