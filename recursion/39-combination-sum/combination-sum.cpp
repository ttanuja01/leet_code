class Solution {
public:
     vector<vector<int>>v;
     void generatesum(int i,int target,vector<int>res,vector<int>c){
         if(target==0){
             v.push_back(res);
             return;
         }
         if(i>=c.size() || target<0){
            return;
         }
         
          generatesum(i+1,target,res,c);
         res.push_back(c[i]);
         generatesum(i,target-c[i],res,c);
         res.pop_back();
          
         
         
         
         
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // vector<vector<int>>v;
        vector<int>res;
        generatesum(0,target,res,candidates);
        return v;
    }
};