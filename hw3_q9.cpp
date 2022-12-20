#include<iostream>
using namespace std;
void leftSpecialValue(int n, int arr[], int leftarr[]){
  int p=0,k=0,temp2[n];
  for(int i=0;i<n;i++){
    p=0;k=0;
    for(int j=0;j<i;j++){
      if(arr[j]>arr[i]){
        temp2[p]=j;
        p++;
      }
    }
    for(int j=0;j<p;j++){
      if(k<temp2[j]){
        k = temp2[j];
        }
    }
    leftarr[i]=k;
  }
}
void rightSpecialValue(int n, int arr[], int rightarr[]){
  int p=0,k,temp2[n];
  for(int i=0;i<n;i++){
    p=0;k=n;
    for(int j=i+1;j<n;j++){
      if(arr[j]>arr[i]){
        temp2[p]=j;
        p++;
      }
    }   
    for(int j=0;j<p;j++){
      if(k>temp2[j]){
        k = temp2[j];
        }
    }
    if(k==n) k=0;
    rightarr[i]=k;
  }
}

int main(){
  int n,x,output=0; cin>>n;
  int arr[n], leftarr[n], rightarr[n], product[n];
  for(int i=0;i<n;i++){
    cin>>x;
    arr[i]=x;
  }
  leftSpecialValue(n, arr, leftarr);
  rightSpecialValue(n, arr, rightarr);
  for(int i=0;i<n;i++){
    product[i] = leftarr[i]*rightarr[i];
    if(product[i]>output) output=product[i];
  }
  cout<<output;
  return 0;
}