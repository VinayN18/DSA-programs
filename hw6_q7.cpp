#include<iostream>
using namespace std;

int main(){
  string s,temp="";
  getline(cin, s);
  int k,n=0; cin>>k;
  for(int i=0;i<=s.length();i++){
    if(s[i]==' ') n++;
  }
  string *arr = new string[n+1];
  n=0;
  for(int i=0;i<=s.length();i++){
    if(s[i]==' '){
      arr[n]=temp;
      n++;
      temp="";
    }
    else temp+=s[i];
  }
  arr[n]=temp; n++;
  // for(int i=0;i<n;i++) cout<<arr[i]<<" "<<endl;
  
  return 0;
}