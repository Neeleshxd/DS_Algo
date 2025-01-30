#include<bits/stdc++.h>
using namespace std;
vector<int>move(vector<int>&arr,int n){
    int j=-1;
   for(int i=0;i<n;i++){
    if(arr[i]==0){
     j=i;
     break;
    }if(j=-1)return arr;
   }
   for(int i=j+1;i<n;i++){
    if(arr[i]!=0){
        swap(arr[i],arr[j]);
        j++;
    }
   }
     return arr;
}
int main(){
    int n;
    cin>>n;
    int a;
    vector<int>arr;
    for(int i=0;i<n;i++){
        cin>>a;
        arr.push_back(a);
    }
    vector<int>result =move(arr,n);
    for(auto it:result){
        cout<<it<<" ";
    }
}