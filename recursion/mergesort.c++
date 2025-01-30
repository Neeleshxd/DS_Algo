#include<bits/stdc++.h>
using namespace std;
void mergesort(int low ,int high ,vector<int>&arr);
void merge(int low ,int high ,int mid,vector<int>&arr){
vector<int>temp;
int left=low;
int right=mid+1;
while(left<=mid && right<=high){
    if(arr[left]<=arr[right]){
    temp.push_back(arr[left]);
    left++;}
    else {temp.push_back(arr[right]);
    right++;
}}
while(left<=mid){
    temp.push_back(arr[left]);
    left++;
}
while(right<=high){
    temp.push_back(arr[right]);
    right++;
}
for(int i=low;i<=high;i++){arr[i]=temp[i-low];
 
}
}
void mergesort(int low ,int high, vector<int>&arr){
    if(low==high)return;
    int mid=(low+high) / 2;
    mergesort(low,mid,arr);
    mergesort(mid+1,high,arr);
    return merge(low,high,mid,arr);
}
int main(){
int n,low,high ;
cin>>n;
vector<int>arr;
int a;
for(int i=0;i<n;i++){
cin>>a ;
arr.push_back(a);
}
mergesort(0,n-1,arr);
high=n-1;
cout<<"sorted array ";
for(int i=0;i<=high;i++){
    cout<<arr[i]<<" ";
}
}
