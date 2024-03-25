/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
//     void func(TreeNode* a, TreeNode* b) {
//         if(b==NULL){
//             return a;
//         }
//         if(a==NULL && b!=NULL){
//             return b;
//         }
//         a->val=a->val+b->val;
//         func(a->left,b->left);
//          func(a->right,b->right);
        
        
       
       
        
//     }
    TreeNode* mergeTrees(TreeNode* a, TreeNode* b) {
        if(b==NULL){
            return a;
        }
        if(a==NULL){
            return b;
        }
        a->val=a->val+b->val;
       TreeNode*l= mergeTrees(a->left,b->left);
        TreeNode*r= mergeTrees(a->right,b->right);
        a->left=l;
        a->right=r;
        return a;
        
    }
};