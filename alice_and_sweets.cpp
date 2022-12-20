#include<iostream>
using namespace std;

int main(){
  int n,k,x,p,q; cin>>n; cin>>k;
  int arr[n],max=0,total=0;
  for(int i=0;i<n;i++){
    cin>>x;
    arr[i]=x;
  }
  p=k-1;q=n-1;
  for(int i=0;i<k;i++){
      total+=arr[i];
    }
    max = total;
  for(int j=0;j<k;j++){
    total = total-arr[p-j]+arr[q-j];
    if(total>max) max=total;
  }  
  cout<<max;
  return 0;
}