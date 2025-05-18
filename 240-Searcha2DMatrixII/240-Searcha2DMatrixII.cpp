// Last updated: 5/18/2025, 12:36:07 PM
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0;
        int j=matrix[0].size()-1;
        int n=j+1;
        int m=matrix.size();
        while(i>=0 && j>=0 && i<m && j<n){
            cout<<i<<" "<<j<<endl;
            int val= matrix[i][j];
            if(val==target)return true;
            if(val<target)i++;
            else j--;
        }
        return false;
    }
};