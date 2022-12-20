#include<iostream>
using namespace std;
void CountSort(int a[], int b[], int n, int max){
  for(int i=0;i<n;i++) b[a[i]]++;
  int i=0, j=0;
  while(i<max+1){
    if(b[i]>0){
      a[j]=i;
      j++;
      b[i]--;
    }
    else i++;
  }
}
int main(){
  int n,p=1,max; cin>>n;
  int arr[n],temp[n]={0};
  for(int i=0;i<n;i++) cin>>arr[i];
  cout<<arr[0]<<" ";
  temp[0]=max=arr[0];
  for(int i=1;i<n;i++){
    temp[p]=arr[i];
    if(max<temp[p]) max=temp[p];
    p++;
    int temp1[max+1]={0};
    CountSort(temp,temp1,p,max);
    if(p%2==0) cout<<temp[p/2-1]<<" ";
    else cout<<temp[(p+1)/2-1]<<" ";
  }
  return 0;
}