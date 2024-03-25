class Solution {
public:
    int maximumWealth(vector<vector<int>>& acc) {
        int s=0;
        for(int i=0;i<acc.size();i++){
            int m=0;
            for(int j=0;j<acc[i].size();j++){
                m+=acc[i][j];
                }
             s=max(s,m);
           
        }
        return s;
        
    }
};