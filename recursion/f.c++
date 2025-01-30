#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void   f(int n,int fact);
int  main(){
    int n;
    cout<<"Enter the number ";
    cin>>n;
    f(n,1);
}
void f(int i,int fact){
if( i< 1){
    cout<<fact;
    return;
}
 f(i-1,fact*i);
}