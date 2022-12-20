#include<iostream>
using namespace std;

int main(){
  int n,m;
  int arr[5][5];
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      int x; cin>>x;
      if(x==1){ n=i; m=j; }
      arr[i][j]=x;
    }
  }
  if(n==2 && m==2) cout<<0;
  else cout<<abs(2-n)+abs(2-m);
  
  return 0;
}