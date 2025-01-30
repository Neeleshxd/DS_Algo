#include<bits/stdc++.h>
using namespace std;
void bs(vector<int>&arr,int i, int n);
void bs(vector<int>&arr,int i, int n){
    if(n==1)return ;
    bs(arr,i+1,n-1);
    if(arr[i]>arr[i+1]){
    swap(arr[i],arr[i+1]);
    }
    bs(arr,i+1,n-1);
}
vector<int> bubbleSort(vector<int>arr){
 bs(arr,0,arr.size());
 return arr;
}
int main() {
    vector<int> input = {1,5,3,2,9,8,4,7};
    vector<int> sorted = bubbleSort(input);

    cout << "Sorted Array: ";
    for (int num : sorted) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}