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
    int maxSum ; 
    int solve(TreeNode*root){
        if( root == nullptr ){
            return 0 ; 
        }
        int l = solve(root->left) ;
        int r = solve(root->right) ; 
        int left_right_noreturn  = root->val + l + r ;  
        int left_aur_right_me_ek = max(l,r)+root->val  ; 
        int sirf_root = root->val ; 
        maxSum = max({maxSum,left_aur_right_me_ek,sirf_root,left_right_noreturn }) ; 
        return max(left_aur_right_me_ek, sirf_root) ; 
    }
    int maxPathSum(TreeNode* root) {
         maxSum = INT_MIN ;
         solve(root) ;
         return maxSum ; 
    }
};