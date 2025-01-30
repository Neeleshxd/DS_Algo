#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int val;
    struct TreeNode*left;
    struct TreeNode*right;
    TreeNode(int x):val(x),left(NULL),right(NULL){};
};
class solution{
    public:
    vector<vector<int>>travesals(TreeNode*root){
       
        stack<pair<TreeNode*,int>>st;
        vector<int>pre,inodr,post;
        st.push({root,1});
        while(!st.empty()){
            auto it=st.top();
           st.pop();


           if(it.second==1){
            pre.push_back(it.first->val);
            it.second++;
            st.push(it);
            if(it.first->left!=NULL){
                st.push({it.first->left,1});
            }
           }
           else if(it.second==2){
            inodr.push_back(it.first->val);
            it.second++;
            st.push(it);
            if(it.first->right!=NULL){
                st.push({it.first->right,1});
            }
           }else{
            post.push_back(it.first->val);
           }
        }
         vector<vector<int>> res;
        res.push_back(pre);
        res.push_back(inodr);
        res.push_back(post);
        return res;
    }
void Display(TreeNode*root){
    vector<vector<int>> res=travesals(root);
    for(auto it:res){
    for(auto val:it){
        cout << val<<" ";
    }
    cout<<endl;
    }
}
};
int main(){
TreeNode*root =new TreeNode(10);
root->left=new TreeNode(5);
root->left->right= new TreeNode(6);
root->left->left=new TreeNode(4);
root->right=new TreeNode(11);
root->right->left=new TreeNode(9);
root->right->right=new TreeNode(12);
solution s;

s.Display(root);

}