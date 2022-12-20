#include<iostream>
using namespace std;
void countsort(int a[], int b[], int n, int max, int min){
  for(int i=0;i<n;i++) b[500+a[i]]++;
  int i=min, j=0;
  while(i<max+1){
    if(b[i]>0){
      a[j]=i-500;
      j++;
      b[i]--;
    }
    else i++;
  }
}
int main(){
  int n; cin>>n;
  int arr[n],temp[1001];
  for(int i=0;i<n;i++) cin>>arr[i];
  for(int i=0;i<1001;i++) temp[i]=0;
  int max=arr[0];
  int min=arr[0];
  for(int i=1;i<n;i++){
    if(max<arr[i]) max=arr[i];
    if(min>arr[i]) min=arr[i];
  }
  countsort(arr,temp,n,max+500,min+500);
  for(int i=0;i<n;i++) cout<<arr[i]<<" ";
  return 0;
}