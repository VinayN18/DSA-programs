#include<iostream>
using namespace std;
void swap(int *x, int *y){
  int temp=*x;
  *x=*y;
  *y=temp;
}
int partition(int a[], int l, int h){
  int p=a[l];
  int i=l, j=h;
  do{
    do{i++;}while(a[i]<=p);
    do{j--;}while(a[j]>p);
    if(i<j) swap(&a[i],&a[j]);
  }while(i<j);
  swap(&a[l],&a[j]);
  return j;
}
void QuickSort(int a[], int l, int h){
  int j;
  if(l<h){
    j=partition(a,l,h);
    QuickSort(a,l,j);
    QuickSort(a,j+1,h);
  }
}
int main(){
  int n,k,l,r; cin>>n; cin>>k;
  int arr[n];
  for(int i=0;i<n;i++) cin>>arr[i];
  QuickSort(arr,0,n-1);
  l=0;r=n-1;
  while(l<r){
    if(arr[l]+arr[r]==k){
      cout<<"1";
      break;
    }else if(arr[l]+arr[r]>k) {r--;l=0;}
    else l++;
  }
  if(l>=r) cout<<"0";
  return 0;
}