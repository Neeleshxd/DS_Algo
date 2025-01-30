#include<bits/stdc++.h>
using namespace std ;
vector<int>rotateArray(vector<int>&arr,int n){
    
    int temp=arr[0];
    for(int i=1;i<n;i++){
        arr[i-1]=arr[i];
    }
    arr[n-1]=temp;
    return arr;
}
int main(){
    vector<int>arr;
    int n;
    cin>>n;
    int a;
    for(int i=0;i<n;i++){
        cin>>a;
         arr.push_back(a); }
   vector<int>rotatedArray= rotateArray(arr,n);
    for(auto it:rotatedArray){
        cout<<it<<" ";
    }
}