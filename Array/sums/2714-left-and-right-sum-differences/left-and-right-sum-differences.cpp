#include <cmath>
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int>l;
        
        int n=nums.size();
        l.push_back(0);
        for(int i=0;i<n-1;i++){
            l.push_back(l[i]+nums[i]);
        }
        vector<int>r;
        r.push_back(0);
        for(int i=nums.size()-1;i>0;i--){
            r.push_back(r[n-i-1]+nums[i]);
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            ans.push_back(abs(l[i]-r[n-i-1]));
        }
        return ans;
        
    }
};
