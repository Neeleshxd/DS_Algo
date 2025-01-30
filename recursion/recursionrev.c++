#include<bits/stdc++.h>
using namespace std;
 bool f(int i,string &s);
int main(){
   string s;
   cin>>s;
  f(0,s);
  if(f(0,s)==1)cout<<"The string is palindrome ";
  else cout<<"Not palindrome ";
  
   return 0;
}
 bool f(int i,string & s){
  if(i>=s.size()/2)return true;
  if(s[i]!=s[s.size()-i-1]) return false;
  return f(i+1,s);
}
