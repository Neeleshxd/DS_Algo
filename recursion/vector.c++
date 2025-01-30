#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v;
    cout<<"Enter the element in the vector :";
for(int i=0;i<4;i++){// through iteration we print the values of the vector 
    int a;
   cin>>a;
   v.push_back(a);
   
}
for(int i=0;i<4;i++){
    printf(" %d  ",v[i]);
}
}