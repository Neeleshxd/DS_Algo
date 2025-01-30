#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    struct Node*left;
    struct Node*right;
};
struct Node* bst(int val){
    struct Node*temp=(struct Node*)malloc(sizeof(struct Node));
    temp->val=val;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void inorder(struct Node*temp){

    if(temp!=NULL){
        inorder(temp->left);
        cout<<temp->val<<" ";
        inorder(temp->right);
    }
    
}
struct Node*Search(struct Node*root,int val){// function to find the node is in the tree or not 
    if(  root == NULL || root->val == val){
     return root;
    }
    if(val < root->val){
        return Search(root->left,val);
    }
    else if(val > root->val){
        return Search(root->right,val);
    }
    return NULL;
}
struct Node*Insert(struct Node*root,int val){// function to insert element in the binary tree 
 if(root==NULL)return bst(val);
 if(val< root->val){
    root->left=Insert(root->left,val);
 }
 else if(val>root->val){
    root->right=Insert(root->right,val);
 }
 return root;
}

int height(struct Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        int lh = height(root->left);
        int rh = height(root->right);
        return 1 + max(lh, rh);
    }
}
struct Node*findlastright(struct Node*root){
    if(root->right== NULL){
     return root;
    }
    return findlastright(root->right);
}
struct Node* helper(struct Node* root) {
    if (root->left == NULL) {
        return root->right;
    } else if (root->right == NULL) {
        return root->left;
    }
    struct Node* rightchild=root->right;
    struct Node* lastRight = findlastright(root->left);
    lastRight->right = rightchild;
    return root->left;
}
struct  Node*Delete(struct Node*root,int key){
struct Node*curr=root;
 if(root==NULL){
    return NULL;
 }if(root->val==key){
    return helper(root);
 }
 while(root!=NULL){
    if(root->val > key){
    if(root->left!=NULL&& root->left->val==key){//if it is the root to be deleted than call the helper function
        root->left=helper(root->left);
        break;
    }else{
        root=root->left;
    }
 }else{
    if(root->right!=NULL&& root->right->val==key){
        root->right=helper(root->right);
        break;
    }else{
        root=root->right;
    }
 }
}
return curr;
}struct Node*kthsmallest(struct Node*root,int &k){//function for finding the kth smallest element in the bsttree 
    if(root==NULL)
        return NULL;
    
    struct Node*leftsmallest=kthsmallest(root->left,k);
    if(leftsmallest!=NULL)
        return leftsmallest;
    
     k--;
        if(k==0)
            return root;
            
    return kthsmallest(root->right,k);
        
    }
    struct Node*kthLargest(struct Node*root,int &k){//finding the largest element in the tree 
        if(root==NULL){
        return NULL;
        }
        struct Node*rightlargest=kthLargest(root->right,k);
        if(rightlargest!=NULL)
            return rightlargest;
        
             k--;
        if(k==0){
         return root;
        }
       return kthLargest(root->left,k);
    }
    
int main(){
    int val;
    int key;
    int k;
    struct Node* root = NULL;
    root = Insert(root, 8);//updation of the root after inserting the elements 
    root = Insert(root, 3);
    root = Insert(root, 1);
    root = Insert(root, 6);
    root = Insert(root, 7);
    root = Insert(root, 10);
    root = Insert(root, 14);
    root = Insert(root, 4);
    cout << "Inorder traversal: ";
    inorder(root);
    printf("\n");
    cout<<"Enter the element to be searched in the binary tree ";
    cin>>val;
    struct Node* result =Search(root,val);
    if(result==NULL){
        cout<<"The element is not found in the tree  "<<"\n";
    }else{
        cout<<"The element is present in the tree "<<"\n";
    }
    int Height=height(root);
    cout<<"The height of the tree is :"<<Height<<"\n";
    cout<<"Enter the element to be deleted from the tree ";
    cin>>key;
    root=Delete(root,key);
    cout<<"Inorder after traversal is ";
    inorder(root);
    cout<<"Enter the value of k :";
    cin>>k;
    struct Node* v=kthsmallest(root,k);
    cout<<"The kth smallest element of the tree is : "<<v->val<<"\n";
    struct Node* r=kthLargest(root,k);
    cout<<"The kth largest element of the tree is :"<<r->val;
    return 0;
}