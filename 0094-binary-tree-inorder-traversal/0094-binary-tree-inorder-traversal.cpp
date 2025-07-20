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
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode*curr = root ; 
        vector<int>result ; 
        while(curr != nullptr ){
 
            if( curr->left == nullptr ){ // L ,V ,R 
                 result.push_back(curr->val) ; 
                 curr = curr->right ; 
            }else{
                TreeNode*leftchild = curr->left ; 
                while( leftchild->right != nullptr ){
                    leftchild = leftchild->right ; 
                }
                leftchild->right = curr ; 
                TreeNode*temp = curr ; 
                curr = curr->left ; 
                temp->left = nullptr ; 
            }
        }
        return result ; 
    }
};