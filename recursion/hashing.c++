#include<bits/stdc++.h>
using namespace std;
int main(){
    int n ;
    cin>>n;
    int q;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int hash[13]={0};
    for(int i=0;i<n;i++){
         hash[arr[i]]=1;
    }
    cin>>q;
    while(q--){
        int number;
        cin>>number;
        cout<<hash[number]<<endl;
    }
    return 0;
}