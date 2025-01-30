#include<bits/stdc++.h>
#include<iostream>
using namespace std;
vector<int> rotateArray(vector<int> &arr, int k) {
  int n = arr.size();
   k = k % n;
  reverse(arr.begin(), arr.begin()+k );  // Use arr.end() - k here
  reverse(arr.begin() + k, arr.end());
  reverse(arr.begin(), arr.end());
  return arr;
}

int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> arr;
    int a;
    for(int i=0;i<n;i++){
        cin>>a;
        arr.push_back(a);
        }
        cout<<"Rotated array ";
    vector<int>result=rotateArray(arr,k);
    for(auto it:result){
        cout<<it<<" ";
    }
}