#include<bits/stdc++.h>
using namespace std;
 vector<int> subsetSum(vector<int> &num);
int main(){
    int n;
    cout<<"Enter the size ";
    cin>>n;
    vector<int> inputVector;
    for(int i=0;i<n;i++){// through iteration we print the values of the vector 
    int a;
   cin>>a;
   inputVector.push_back(a);
   }
   vector<int>result=subsetSum(inputVector);
}
 vector<int> subsetSum(vector<int> &num){
   
    
 }
