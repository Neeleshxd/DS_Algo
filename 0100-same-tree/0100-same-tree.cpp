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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if( p == nullptr &&  q == nullptr ) return true ; 
        if( p == nullptr || q == nullptr ) return false ; 
        queue<TreeNode*>que1 ;
        queue<TreeNode*>que2 ; 
        que1.push(p) ;
        que2.push(q) ; 
        while(!que1.empty() && !que2.empty()){
            TreeNode*front1 = que1.front() ;que1.pop(); 
            TreeNode*front2 = que2.front() ;que2.pop();

            if( front1->val != front2->val ) {
                return false ; 
            } 
            if(front1->left != nullptr && front2->left != nullptr ){
                que1.push(front1->left) ; 
                que2.push(front2->left) ; 
            }else if(front1->left != nullptr || front2->left != nullptr){
                return false ; 
            }
            if(front1->right != nullptr && front2->right != nullptr ){
                que1.push(front1->right) ; 
                que2.push(front2->right) ;
            }else if (front1->right != nullptr || front2->right != nullptr){
                return false ; 
            }
        }
        return true ; 
    }
};