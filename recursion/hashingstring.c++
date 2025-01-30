#include<bits/stdc++.h>
using namespace std ;
int main(){
    string n;
    cin>>n;
    int hash[26]={0};
    for(int i=0;i<n.size();i++){
         hash[n[i]-'a']++;
    }
    int q;
    cin>>q;
    while(q--){
        char st;
        cin>>st;
        cout<<hash[st-'a']<<endl;;
    }
    return 0;
}