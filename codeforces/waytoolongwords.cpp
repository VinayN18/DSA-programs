#include<iostream>
using namespace std;

int main(){
  int n; cin>>n;
  for(int i=0;i<n;i++){
    string s,output;
    cin>>s;
    if(s.size()>10){
      int p=s.size()-2;
      output=s[0]+to_string(p)+s[s.size()-1];
    }
    else output=s;
    cout<<output<<endl;
  }
  return 0;
}