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
    int countNodes(TreeNode* root) {
        if( root == nullptr ) return 0 ; 

        queue<TreeNode*>q ;
        q.push(root) ; 
        int count = 0; 
        while(!q.empty()){
            TreeNode*curr = q.front() ; q.pop() ;
            count++; 
            if( curr->left != nullptr ){
                q.push(curr->left) ; 
            }
            if(curr->right != nullptr ){
                q.push(curr->right) ; 
            }
        }
        return count ; 
    }
};