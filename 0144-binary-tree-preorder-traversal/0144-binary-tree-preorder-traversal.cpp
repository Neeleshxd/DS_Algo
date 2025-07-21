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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>result ; 
        if( root == nullptr ) return {} ; 
        TreeNode*curr = root ; 
        while(curr){
            TreeNode*temp = curr->right ; 
          if( curr->left == nullptr){
            result.push_back(curr->val) ;
            curr = curr->right ; 
          }else{
            TreeNode*leftchild = curr->left ; 
            while( leftchild->right != nullptr){
            leftchild = leftchild->right ; 
        }
        result.push_back(curr->val) ; 
        leftchild->right = temp ; 
        TreeNode*temp1 = curr ; 
        curr = curr->left ; 
        temp1->right = nullptr ; 
        }
 }
        return result ; 
    }
};