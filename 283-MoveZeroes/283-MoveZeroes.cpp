// Last updated: 4/19/2025, 10:22:02 PM
class Solution {
public:
int getnonzeroidx(int idx,vector<int> & nums){
    for(int i=idx;i<nums.size();i++){
        if(nums[i]!=0)return i;
    }
    return -1;
}
    void moveZeroes(vector<int>& nums) {

        int i=0,j=0;
        int n=nums.size();
        while(i<n){

            j=getnonzeroidx(i,nums);
            if(j==-1)return;
            if(i==j){
                i++;
                j++;
            }else{
                 nums[i]=nums[j];
            nums[j]=0;
            i++;
            }
        }
        
    }

};