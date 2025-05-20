// Last updated: 5/20/2025, 8:57:08 AM
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;
        vector<int> ans;
        int  total = matrix.size() * matrix[0].size();
        while (ans.size()< total) {

            for (int i = left; i <= right && ans.size()< total; i++)
                ans.push_back(matrix[top][i]);
                top++;
            for (int i = top; i <=bottom && ans.size()< total; i++)
                ans.push_back(matrix[i][right]);
                      right--;
            for (int i = right; i >= left && ans.size()< total; i--)
                ans.push_back(matrix[bottom][i]);
bottom--;
            for (int i = bottom; i >= top && ans.size()< total; i--)
                ans.push_back(matrix[i][left]);

                            left++;

        }
        return ans;
    }
};