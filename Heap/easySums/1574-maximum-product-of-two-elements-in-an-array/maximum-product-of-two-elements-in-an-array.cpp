class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<nums.size();i++){
            
            pq.push(nums[i]);
            if(pq.size()>2){
                cout<<pq.top()<<"*";
                pq.pop();
            }
        }
        int x=pq.top();
        pq.pop();
        return (x-1)*(pq.top()-1);
        
    }
};