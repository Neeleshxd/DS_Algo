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
    TreeNode*solve(vector<int>& preorder, vector<int>& inorder,int start ,int& idx ,int end ){
        if( start > end ) return nullptr ; 

        int rootval = preorder[idx] ;
        int i = start ; 
        for(; i <= end ; i++ ){
            if( rootval == inorder[i]){
                break ; 
            }
        }
         idx++; 
         TreeNode*root = new TreeNode(rootval) ; 
         root->left= solve(preorder,inorder,start,idx,i-1) ; 
         root->right = solve(preorder,inorder,i+1,idx,end) ; 
        
        return root ; 
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size() ; 
        int idx = 0 ; 
        return solve(preorder,inorder,0,idx,n-1) ; 
    }
};