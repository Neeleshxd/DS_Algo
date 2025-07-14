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
    bool solve(TreeNode*root,TreeNode*target,vector<TreeNode*>&temp ){
        if( root == nullptr ) return false  ; 
        temp.push_back(root) ;
        if( root == target ){
        return true ; 
        }
        if (solve(root->left, target, temp) || solve(root->right, target, temp)){
        return true;
    }
        temp.pop_back() ; 
        return false ; 
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>temp1,temp2 ; 
        solve(root, p,temp1) ; 
        solve( root, q,temp2) ; 
        int i = 0 ;
        int j = 0 ;
        TreeNode*ans = nullptr ; 
        while( i < temp1.size() && j < temp2.size()){
            if( temp1[i] == temp2[j]){
            ans = temp1[i] ; 
            }
            i++; 
            j++; 
        }
     return ans ; 
    }
};