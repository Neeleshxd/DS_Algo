#include<bits/stdc++.h>
using namespace std;
void  f(int i,int arr[],vector<int>& ds,int n );
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    vector<int>ds;
   f(0,arr,ds,n);
}
void f(int i,int arr[],vector<int>&ds,int n){
    if(i==n){
    for(auto it:ds){
     cout<<it<<" ";
    }if(ds.size()==0)cout<<"{}";
    cout<<endl;
     return ;
    }
    ds.push_back(arr[i]);
    f(i+1,arr,ds,n);
    ds.pop_back();
    f(i+1,arr,ds,n);
    
}