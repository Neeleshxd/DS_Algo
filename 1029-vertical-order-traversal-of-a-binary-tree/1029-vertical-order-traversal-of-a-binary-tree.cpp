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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,int>>>todo ; 
        todo.push({root,{0,0}}) ; 
        map<int,map<int,multiset<int>>>nodes ; 
        while( !todo.empty()){
            auto p = todo.front() ; 
            todo.pop() ; 
            TreeNode*front = p.first ; 
            int x = p.second.first ;  // vertical position 
            int y = p.second.second ; // horizontal position 
          nodes[x][y].insert(front->val) ; 
          if(front->left != nullptr ){
            todo.push({front->left,{
                x-1,
                y+1
            }});
        }
        if(front->right != nullptr ){
            todo.push({front->right,{
                x+1,
                y+1
            }});
        }
    }
    vector<vector<int>>result ; 
    for( auto p : nodes){
        vector<int>col ; 
        for( auto c : p.second ){
           col.insert(col.end(),c.second.begin(),c.second.end()) ; 
        }
         result.push_back(col) ; 
    }
    return result ; 
    }
};