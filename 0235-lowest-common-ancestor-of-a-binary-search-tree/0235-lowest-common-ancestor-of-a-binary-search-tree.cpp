/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if( root == nullptr ) return root ; 
       if( root == p || root == q ) return root ; 

       TreeNode*left_side =  lowestCommonAncestor(root->left,p,q) ; 
       TreeNode*right_side =  lowestCommonAncestor(root->right,p,q) ; 
       if(left_side != nullptr && right_side != nullptr ) return root ; 
       if(left_side != nullptr ){
        return left_side; 
       }
       return right_side ; 
    }
};