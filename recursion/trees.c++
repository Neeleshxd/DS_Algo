#include<bits/stdc++.h>
using namespace std;
struct BstNode{//creating the structure of the binary tree 
 BstNode*right;// the pointers to store the adress of left and right nodes
 BstNode*left;
 int data;// the node value 
};

BstNode*GetnewNode(int data){// a method to get the desired node to be inserted or the root node 
    BstNode*newNode=new BstNode();// creating the new node 
    newNode->data=data;//passing the parameter data to the function 
    newNode->left=newNode->right=NULL;
    return newNode;
}
BstNode*Insertroot(BstNode*root,int data ){// method for inserting the node or the root element to the tree 
    if(root==NULL){ // checking if the tree has a root or not 
    root=GetnewNode(data);/// cretion of the root 
    return root;
}else if(data<=root->data){//now if the root is already present than check if the element to be added is smaller than root or not 
   root->left=Insertroot(root->left,data);// create a root to the left 
}else{
    root->right=Insertroot(root->right,data);
}
return root;
}
bool Search(BstNode*root,int data){ // method for checking if the element is present in the binart tree or not 
  if(root==NULL)// if no elements in the root than return false 
    return false;
  if(root->data==data)return true;// else check if root is the data to be found 
  else if(data<=root->data)return Search(root->left,data);// else if not than check if the data to be found is smaller tha root and than perform the search operation again
  else return Search(root->right,data);//else check it in the right side of the tree 
}
int main(){// main function for calling all the methods 
    BstNode*root=NULL;
 root= Insertroot(root,15);// inseting element in the root 
  root=Insertroot(root,10);
 root= Insertroot(root,12);
  root=Insertroot(root,8);
  root=Insertroot(root,20);
  root=Insertroot(root,17);
 root= Insertroot(root,25);
  int number;
  cout<<"Enter the number to be searched ";
  cin>>number;
  if(Search(root,number)==true)cout<<"Found";//searching the element  in the tree 
  else cout<<"Not found ";
}