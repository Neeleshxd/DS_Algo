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
    int leftheight(TreeNode*root){
        TreeNode*temp = root ; 
        int lh = 0; 
        while(temp){
         lh++;
         temp = temp->left ; 
        }
        return lh ; 
    }
    int rightheight(TreeNode*root){
        TreeNode*temp = root ; 
        int rh = 0; 
        while(temp){
         rh++;
         temp = temp->right ; 
        }
        return rh ; 
    }
    int countNodes(TreeNode* root) {
        if( root == nullptr ) return 0 ; 

        int lh = leftheight(root) ;
        int rh = rightheight(root) ; 

        if( lh == rh ){
            return pow(2,lh) -1 ; 
        }
        return 1 + countNodes(root->left) + countNodes(root->right) ;  
    }
};