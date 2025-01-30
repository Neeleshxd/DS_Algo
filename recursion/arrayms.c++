#include <iostream>
#include <vector>
using namespace std;
void print(int i,int n, vector<int>&result);
void print(int i,int n, vector<int>&result){
    if(i>n)return;
    else print(i+1,n,result);
    result.push_back(i);
    

}
vector<int>printNos(int x){
    int i;
    vector<int>result;
    print(1,x,result);
    return result;
}
int main() {
    int x = 10; // Change this to the desired value of 'x'
    vector<int> numbers = printNos(x);
    
    // Printing the generated numbers
    for (int num : numbers) {
        cout << num << " ";
    }
    
    return 0;
}