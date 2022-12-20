#include<iostream>
using namespace std;

int main(){
  int n,m,cnt=0,total=0; cin>>n; cin>>m;
  int prices[n], budget[m];
  for(int i=0;i<n;i++) cin>>prices[i];
  for(int i=0;i<m;i++) cin>>budget[i];
  for(int i=0;i<m;i++){
    total=0;cnt=0;
    for(int j=0;j<n;j++){
      total+=prices[j];
      if(total>budget[i]){
        cout<<cnt<<" ";
        break;
      }
      if(j==n-1 && total<=budget[i]) cout<<cnt+1;
      cnt++;
    }
  }
  return 0;
}