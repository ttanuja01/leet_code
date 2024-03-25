class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int c=0;
        for(auto it=m.begin();it!=m.end();it++){
            if(it->second>1){
                int n=it->second;
                c=c+((n*(n-1))/2);
            }
        }
        return c;
        
    }
};