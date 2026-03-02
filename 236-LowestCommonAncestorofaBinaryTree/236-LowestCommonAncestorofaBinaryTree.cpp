// Last updated: 3/2/2026, 9:11:04 PM
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
8 * };
9 */
10class Solution {
11public:
12    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
13        if(p==NULL || q==NULL || root==NULL) return NULL;
14        if(root->val == p->val || root->val == q->val) return root;
15        TreeNode * l= lowestCommonAncestor(root->left,p,q);
16         TreeNode * r= lowestCommonAncestor(root->right,p,q);
17         if(l!=NULL && r!=NULL)return root;
18         if(l!=NULL)return l;
19         if(r!=NULL)return r;
20
21        return NULL;
22        
23    }
24};