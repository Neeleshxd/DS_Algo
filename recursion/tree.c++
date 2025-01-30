#include <bits/stdc++.h>
using namespace std;
struct Node{//creation of node
 int data;
 struct Node*left;
 struct Node*right;
 Node(int val){//creation of constructor
    data=val;
    left=NULL;
    right=NULL;
 }
};
void preorder(Node*node){//root,left,right
    if(node==NULL){
        return;
    }
    cout<<node->data<<" ";
    preorder(node->left);
    preorder(node->right);
}
void inorder(Node*node){//left root right
    if(node==NULL){
        return;
    }
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}
void postorder(Node*node){//left right root
    if(node==NULL){
        return;
    }
    postorder(node->left);
    postorder(node->right);
    cout<<node->data<<" ";
}
int main(){
    struct Node*root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->right=new Node(4);
    inorder(root);
    postorder(root);
    return 0;
}
