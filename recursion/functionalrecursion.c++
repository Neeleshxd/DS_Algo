#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int f(int n);
int  main(){
    int n;
    cout<<"Enter the value ";
    cin>>n;
    cout<<f(n);
}
int   f(int n){
   if(n==0){
    return 0;
   }
   return n+f(n-1);//it checks the condition for n=0 
}