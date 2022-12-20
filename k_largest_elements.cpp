#include<iostream>
using namespace std;
void remove(int arr[], int n){
  int i,j,x,temp,value;
  if(arr[1]!=0){ 
  value=arr[1];
  x=arr[n];
  arr[1]=arr[n];
  arr[n]=value;
  i=1;j=2*i;
  while(j<n-1){
    if(arr[j+1]>arr[j]) j+=1;
    if(arr[i]<arr[j]){
      temp=arr[i];
      arr[i]=arr[j];
      arr[j]=temp;
      i=j;
      j=2*j;
    }else break;
  }
  }
}
void insert(int arr[], int n){
  int i=n, temp;
  temp=arr[i];
  while(i>1 && temp>arr[i/2]){
    arr[i]=arr[i/2];
    i=i/2;
  }
  arr[i]=temp;
}
int main(){
  int n,k; cin>>n;
  int numbers[n+1];
  numbers[0]=0;
  for(int i=1;i<n+1;i++) cin>>numbers[i];
  cin>>k;
  for(int i=2;i<n+1;i++) insert(numbers, i);
  for(int i=n;i>1;i--) remove(numbers, i);
  for(int i=n;i>n-k;i--) cout<<numbers[i]<<" ";
  return 0;
}