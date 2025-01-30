#include<bits/stdc++.h>
using namespace  std;
int  f(int i,int arr[],int n,int sum,int s);
int main(){
    int n,sum;
    cin>>n;
    cin>>sum;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
   cout<< f(0,arr,n,sum,0);
}
int f(int i,int arr[],int n,int sum,int s){
    if(i==n){
        if(s==sum)return 1;
        else return 0;
    
    }
    
    s+=arr[i];
    int l=f(i+1,arr,n,sum,s);
    s-=arr[i];
   int r= f(i+1,arr,n,sum,s);
   return l+r;
}