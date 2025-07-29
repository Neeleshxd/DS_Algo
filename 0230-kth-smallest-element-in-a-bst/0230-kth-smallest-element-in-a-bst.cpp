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
    void inorder(TreeNode*root,int k ,int& counter ,int& kth_smallest ){
        if( !root || counter >= k ) return ; 
        inorder(root->left,k,counter,kth_smallest) ; 
        counter++; 
        if( counter == k  ){
            kth_smallest = root->val ; 
            return ;  
        }
        inorder(root->right,k,counter,kth_smallest) ; 
    }
    int kthSmallest(TreeNode* root, int k) {
        int kth_smallest = INT_MIN ; 
        int counter = 0 ; 
        inorder(root,k,counter,kth_smallest) ; 
        return kth_smallest ; 
    }
};