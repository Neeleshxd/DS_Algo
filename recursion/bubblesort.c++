#include<bits/stdc++.h>
using namespace std;
void bubbleSort(int arr[],int n){
  for(int i=0;i<n-1;i++){
    for(int j=0;j<n-1;j++){
        if(arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
        }
    }
  }
}
void printArray(int arr[],int n){
 for(int i=0;i<n;i++)cout<<arr[i]<<" ";
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    bubbleSort(arr,n);
    cout<<"Sorted array :";
    printArray(arr,n);
    return 0;
}