// Last updated: 5/18/2025, 12:01:15 PM
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int low=0;
        int high=m-1;
  
        while(low<=high){
            int mid=(low+high)/2;
            if(matrix[mid][0]>target){
                high=mid-1;
            }else if(matrix[mid][0]<target){
                low=mid+1;
            }else{
                return true;
            }
        }
        int r=high;
        if(r<0)return false;
        low=0,high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(matrix[r][mid]>target){
                high=mid-1;
            }else if(matrix[r][mid]<target){
                low=mid+1;
            }else{
                return true;
            }
        }




        return false;
        
    }
};