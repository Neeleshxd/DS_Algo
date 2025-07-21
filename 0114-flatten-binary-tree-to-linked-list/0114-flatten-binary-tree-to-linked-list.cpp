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
    void flatten(TreeNode* root) {
        if( root == nullptr ) return ;
        if( root->left == nullptr && root->right == nullptr ) return ; 
        TreeNode*curr = root ;
        while(curr){
            TreeNode *temp = curr->right;
            if (curr->left == nullptr){
                {
                   curr = curr->right ;  
                }
        }else{
            TreeNode*leftchild =  curr->left ;
            while(leftchild->right != nullptr ){
                leftchild = leftchild->right ; 
            }
            leftchild->right = temp ; 
            TreeNode*temp1 = curr ;
            curr= curr->left ; 
            temp1->right = nullptr ; 
            temp1->left =nullptr ; 
            temp1->right = curr ; 
        }
    }
    }
};