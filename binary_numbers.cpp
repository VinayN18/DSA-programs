#include<iostream>
#include<string>
using namespace std;

int main(){
  int n;
  long long i=1,temp,t; 
  cin>>n;
  int rem=0;
  bool cnt=false;
  while(true){
    temp=n*i;
    t=temp;
    while(temp!=0){
      rem=temp%10;
      if(rem!=0 && rem!=1) break;
      temp/=10; 
      if(temp==0) cnt=true;
    }
    if(cnt){
        cout<<to_string(t);
        break;
    }
    i++;
  }
  return 0;
}