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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>result ; 
        if( root == nullptr ) return result ; 
        queue<TreeNode*>q ; 
        q.push(root) ; 
        int left_right_flag = true ; 
        while( !q.empty()){
            int size = q.size() ; 
            vector<int>row(size) ;

            for( int i = 0 ; i < size ; i++ ){
                TreeNode*node = q.front() ; q.pop() ; 
                int idx = ((left_right_flag)? i : (size - i -1) ) ; // 0(left) ,1(right).. 
                row[idx] = node->val ;  
                if( node->left != nullptr ){
                    q.push(node->left) ; 
                }
                if( node->right != nullptr ){
                    q.push(node->right) ; 
                }
            }
            left_right_flag = !left_right_flag ; 
            result.push_back(row) ; 
        }
        return result ; 
    }
};