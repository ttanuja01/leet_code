// Last updated: 11/17/2025, 11:20:10 AM
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {

        int fi=0,j=nums.size()-1;
        for(int i=0;i<=j;i++){
            if(nums[i]==1){
                fi=i;
                break;
            }
        }  
        int m=fi+1;
        while(m<=j){
            if(nums[m]==1){
                if(m-fi<=k){
                    return false;
                }else{
                    fi=m;
                    m++;
                }
            }else{
                m++;
            }
        }
        return true;
    }
};