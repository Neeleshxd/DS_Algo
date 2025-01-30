#include<bits/stdc++.h>
using namespace std;
 struct Node{ // defining the structure of the tree 
 int val;
 struct Node*left;
 struct Node*right;
 };
 struct Node*Bt(int val){
    struct Node*newNode= (struct Node*)malloc(sizeof(struct Node));
    newNode->val=val;
    newNode->left=NULL;
    newNode->right=NULL;
    return(newNode);
 }
 struct Node*pre(struct Node*temp){// preorder traversal 
    if(temp!=NULL){
    cout<<temp->val<<" ";
    pre(temp->left);
    pre(temp->right);
    }
    return temp;
 }
 struct Node*in(struct Node*temp){//inorder traversal 
 
    if(temp!=NULL){
        in(temp->left);
        cout<<temp->val<<" ";
        in(temp->right);
    }
    return temp;
 }
 struct Node*post(struct Node*temp){//postorder traversal
    if(temp!=NULL){
        post(temp->left);
        post(temp->right);
        cout<<temp->val<<" ";
    }
    return temp;
 }
int maximumdepth(struct Node* root) { // finding the maximum height of the tree 
    if (root == NULL) {
        return 0;
    }
    int lh = maximumdepth(root->left);
    int rh = maximumdepth(root->right);
    return 1 + max(lh, rh);
}
struct Node*bst(struct Node*root,int val){ // binary search tree function 
      if( root == NULL || root->val == val){ //checking the condtion if root is null or val to find is equal to root value 
            return root;
      }
      if(val < root->val){
          return bst(root->left,val); // recursive calling of bst function with the left node 
      }else{
          return bst(root->right,val);//recursive calling od bst function with the right node 
      }
      return NULL;
}
 
int main(){
    int val;
    cout<<"Enter the value of the root ";
    cin>>val;
 struct Node*root=Bt(val);
 stack<Node*>st;//creation of the stack
 st.push(root);//pushes the root element in the stack
 while(!st.empty()){
    struct Node*temp=st.top();
    st.pop();
    cout<<"Enter the left child of the node "<<  temp->val <<" or (-1) for NULL  ";
    cin>>val;
    if(val!=-1){
     temp->left=Bt(val);
     st.push(temp->left);
    }
    cout<<"Enter the right child of the node "<< temp->val <<" or (-1) for NULL ";
    cin>>val;
    if(val!=-1){
        temp->right=Bt(val);
        st.push(temp->right);
    }
 } 

 cout<<"height of the tree is :";
 cout<<maximumdepth(root)<<endl ;
 cout<<"Enter the element to be searched in the bt ";
 cin>>val;
 struct Node *result=bst(root,val);
 if(result==NULL){
    cout<<"Element not in the tree ";
 }
 else{
    cout<<"Element found in the binary search tree "<<endl;
 }
  cout<<"Preorder traversal:";
 cout<<pre(root)<<endl;
 cout<<"Inorder traversal :";
 cout<<in(root)<<endl;
 cout<<"Postorder traversal :";
 cout<<post(root)<<endl;
 }