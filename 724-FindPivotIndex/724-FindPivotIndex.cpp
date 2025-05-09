// Last updated: 5/9/2025, 9:58:47 PM
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int>ls;
        int n=nums.size();
        if(n==0)return -1;
        ls.push_back(nums[0]);
        for(int i=1;i<n;i++){
            ls.push_back(ls[i-1]+nums[i]);
        }
        int rs=0;
        int ans=-1;
                for(int i=n-1;i>=0;i--){
                    rs+=nums[i];
            if(rs==ls[i]){ans=i;}
        }
        return ans;
        
    }
};

// 1 8 11 17 22 28
// 28 27 20 17 11 6

// 1 3 6
// 6 5 3

// 2 3 2
// 2  0 -1