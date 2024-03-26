class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        vector<int>ans;
        while(pq.size()>0){
        int x=pq.top();
        pq.pop();
        int y=pq.top();
        pq.pop();
        ans.push_back(y);
        ans.push_back(x);
        }
        return ans;
        
    }
};