#include<bits/stdc++.h>
using namespace std;
int linearSearch(int n, int num, vector<int> &arr){
    for(int i=0;i<n;i++){
        if(arr[i]==num){
            cout <<"  "<<i;
        }
    }
}
int main(){
    int n;
    cin>>n;
    int num;
    cin>>num;
    int a;
    vector<int>arr;
    for(int i=0;i<n;i++){
      cin>>a;
      arr.push_back(a);
    }
     int result=linearSearch(n,num,arr);
     
}