#include<bits/stdc++.h>
using namespace std ;

void qs(vector<int>&arr,int low , int high);
int  f(vector<int>&arr,int low,int high){
int pivot=arr[low];
int i=pivot;
int j=high;
while(i<j){
    while(arr[i]<=pivot && i<=high-1){
        i++;
    }
    while(arr[j]>=pivot&&j>=low+1){
        j--;
    }
    if(i<j){swap(arr[i],arr[j]);
}
}
   swap(arr[low],arr[j]);
   return j;
}

void qs(vector<int>&arr,int low , int high){
    if(low<high){
        int partition=f(arr,low,high);
        qs(arr,low,partition-1);
        qs(arr,partition+1,high);
            }
}
vector<int> quickSort(vector<int>arr){
    qs(arr,0,arr.size()-1);
    return arr;
}
int main() {
    vector<int> input = {4, 2, 7, 1, 9, 5, 3};
    vector<int> sorted = quickSort(input);

    cout << "Sorted Array: ";
    for (int num : sorted) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
