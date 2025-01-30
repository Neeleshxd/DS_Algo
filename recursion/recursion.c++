#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void myFunction(int i, int n);

int main(){
    int n;
    cout<<"Enter the time u want to print ";
    cin>>n;
 myFunction(n,0);

    return 0;
}
void  myFunction(int i,int sum){
    if(i<1){
    cout<<sum;
        return;    
    }
    myFunction(i-1,sum+i);
    
}