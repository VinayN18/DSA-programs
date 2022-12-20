#include<iostream>
using namespace std;

int main(){
  int n,k=0,cnt=0; cin>>n;
  int arr[n];
  for(int i=0;i<n;i++) cin>>arr[i];
  for(int i=0;i<n;i++){
    cnt=0;
    for(int j=0;j<n;j++){
      if(k!=arr[j]) cnt+=1;
      else break;
    }
    if(cnt==n){
      cout<<k;
      break;
    }
    k++;
  }
  return 0;
}