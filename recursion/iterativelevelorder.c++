#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int val;
    struct TreeNode*left;
    struct TreeNode*right;
    TreeNode(int x):val(x),left(NULL),right(NULL){};
};
class Solution{
    public:
 vector<int>levelorder(TreeNode*root){
    vector<int>result;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        TreeNode*temp=q.front();
        q.pop();
        if(temp->left!=NULL)
        q.push(temp->left);
        
        if(temp->right!=NULL)
            q.push(temp->right);
            result.push_back(temp->val);
 }
    return result;
 }
 vector<int>preorder(TreeNode*root){
    vector<int>answer;
    stack<TreeNode*>st;
    st.push(root);
    while(!st.empty()){
        int size=st.size();
        TreeNode*temp=st.top();
        st.pop();
        answer.push_back(temp->val);
        if(temp->right!=NULL)
        st.push(temp->right);
        if(temp->left!=NULL)
        st.push(temp->left);
    }
    return answer;
 }
 vector<int>inorder(TreeNode*root){
  vector<int>answer;
   stack<TreeNode*>st;
   TreeNode*temp=root;
   while(true){
    if(temp!=NULL){
    st.push(temp);
    temp=temp->left;
   }
   else {
    if(st.empty()==true)break;//if stack is empty then break the loop since we have visted all the nodes
    temp=st.top();
    st.pop();
    answer.push_back(temp->val);
    temp=temp->right;
   }
   
 }
 return answer;
 }
};
int main(){
    Solution a;
    TreeNode*root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(7);
    root->left->left=new TreeNode(3);
    root->left->right=new TreeNode(4);
    root->left->right->left=new TreeNode(5);
    root->left->right->right=new TreeNode(6);
 vector<int>answer=a.inorder(root);
 for(int i=0;i<answer.size();i++){
      cout<<answer[i]<<" "<<endl;
 }
 return 0;
}