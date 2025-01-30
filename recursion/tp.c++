#include<bits/stdc++.h>
using namespace std;



class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
Node* createTree(vector<int>&arr){
    Node*root=new Node(arr[0]);
    stack<pair<Node*,int>>st;
    st.push({root,1});
    int i=1;
    while(!st.empty()){
        if(st.top().second==1){
            st.top().second++;
            if(arr[i]!=-1){
                st.top().first->left=new Node(arr[i]);
                st.push({st.top().first->left,1});
            }
            i++;
        }
        else if(st.top().second==2){
            st.top().second++;
            if(arr[i]!=-1){
                st.top().first->right=new Node(arr[i]);
                st.push({st.top().first->right,1});
            }
            i++;
        }
        else{
            st.pop();
        }
    }
    return root; 
    
    
    
}