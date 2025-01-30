#include<bits/stdc++.h>
using namespace std;
int  f(int n);
int main(){
    int n;
    cin>>n;
    cout<<f(n);
}
 int f(int n){
 if(n<=1)return n;// checking the conditon if n ever become less than 1 than it returns it value 
return(f(n-1)+f(n-2));// until the condition statisfies it calls the functions 
}