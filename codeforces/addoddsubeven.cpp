#include<iostream>
using namespace std;

int main(){
  int n; cin>>n;
  for(int i=0;i<n;i++){
    int a,b; cin>>a>>b;
    int x=1,y=2;
    while(a!=b){
      if(a<b){
        a+=x;
        x+=2;
      }
      else if(a>b){
        a-=y;
        y+=2;
      }
    }
  }
  return 0;
}