#include <iostream>
using namespace std;

int main(){
  int n,k,skip=2,cnt=0; cin>>n;
  int arr[n];
  for(int i=0;i<n;i++) cin>>arr[i];
  cin>>k;
  for(int i=0;i<n;i=i+skip){
    if(arr[i]==k){
      cout<<i;
      cnt++;
      break;
    }
    else if(arr[i]>k){
      for(int j=i-skip;j<i;j++){
        if(arr[j]==k){
          cout<<j;
          cnt++;
          break;
        }
      }
    }
  }
  if(cnt==0) cout<<-1;
  return 0;
}