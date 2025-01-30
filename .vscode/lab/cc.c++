#include<bits/stdc++.h>
using namespace std;

void f(vector<int>&arr,int n,int parent){
    if(parent>=n)return;
    cout<<"Node: "<<arr[parent]<<endl;
    int left=2*parent+1;
    int right=2*parent+2;
    if(left<n){
        cout<<"Left child: "<<arr[left]<<endl;
    }
    if(right<n){
        cout<<"Right child: "<<arr[right]<<endl;
    }
    f(arr,n,left);
    f(arr,n,right);
}

void display_tree(vector<int>&arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int main(){
    int n;
    cin>>n;
    vector<int>arr;
    int a;
    for(int i=0;i<n;i++){
        cin>>a;
        arr.push_back(a);
    }
    int parent ;
    cin>>parent;
    f(arr,n,parent);
    n = arr.size(); // update n to reflect the new size of the vector



    // Print the updated tree data
    display_tree(arr, n);
}