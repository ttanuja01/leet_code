// Last updated: 1/7/2026, 10:22:13 PM
1class Solution {
2public:
3    static const int MOD = 1e9 + 7;
4    long long totalSum = 0;
5    long long maxProductVal = 0;
6
7    // First DFS: compute total sum
8    long long getTotalSum(TreeNode* root) {
9        if (!root) return 0;
10        return root->val + getTotalSum(root->left) + getTotalSum(root->right);
11    }
12
13    // Second DFS: compute subtree sums and maximize product
14    long long dfs(TreeNode* root) {
15        if (!root) return 0;
16
17        long long left = dfs(root->left);
18        long long right = dfs(root->right);
19
20        long long subSum = root->val + left + right;
21
22        // Try cutting above this node
23        maxProductVal = max(
24            maxProductVal,
25            subSum * (totalSum - subSum)
26        );
27
28        return subSum;
29    }
30
31    int maxProduct(TreeNode* root) {
32        totalSum = getTotalSum(root);
33        dfs(root);
34        return maxProductVal % MOD;
35    }
36};