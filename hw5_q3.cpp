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
  int n,cnt=0,p=0; cin>>n;
  int arr[n], output[n];
  for(int i=0;i<n;i++) cin>>arr[i];
  for(int i=0;i<n;i++){
    cnt=0;
    for(int j=0;j<n;j++){
      if(arr[i]==arr[j]) cnt+=1;
      if(cnt==3) break;
    }
    if(cnt>=3){
      output[p]=arr[i];
      p++;
    }
  }
  QuickSort(output,0,p);
  cnt=output[0];
  cout<<cnt<<" ";
  for(int i=1;i<p;i++){
    if(cnt!=output[i]){
      cnt=output[i];
      cout<<cnt<<" ";
    }
  }
  return 0;
}