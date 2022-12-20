#include<iostream>
#include<string>
using namespace std;

int main(){
  int cnt=0;
  string s1,s2;
  cin>>s1>>s2;
  for(int i=0;i<s1.size();i++){
    if(s1[i]==s2[i] || int(s1[i])==int(s2[i])-32 || int(s1[i])==int(s2[i])+32)
      cnt+=1;
    else if(tolower(s1[i])-tolower(s2[i])>0){
      cout<<1;
      break;
    }  
    else{
      cout<<-1;
      break;
    }
  }
  if(cnt==s1.size()) cout<<0;
  return 0;
}