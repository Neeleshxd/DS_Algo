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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>result ; 
        if( root == nullptr ) return result ; 
        queue<pair<TreeNode*,int>>q ; 
        q.push({root,0}) ;// root,level 
        map<int,int>mp ; // level->node-val 
        while(!q.empty()){
            auto p = q.front() ;q.pop() ;  // pair access 
            int level = p.second ;
           TreeNode*node = p.first ; 
           mp[level] = node->val ; 
           if( node->left != nullptr ){
            q.push({node->left,level+1}) ; 
           }
           if(node->right != nullptr ){
            q.push({node->right,level+1}) ; 
           }
        }
        for(auto&it:mp){
            result.push_back(it.second) ; 
        }
        return result ; 
    }
};