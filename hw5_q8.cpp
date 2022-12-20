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
  int n,k,cnt=1,p=1,q=0; cin>>n;
  int arr[n],arr1[n],count[n];
  for(int i=0;i<n;i++) cin>>arr[i];
  QuickSort(arr,0,n);
  arr1[0]=k=arr[0];
  for(int i=1;i<n;i++){
    if(k!=arr[i]){
      arr1[p]=arr[i];
      p++;
    }
  }
  for(int i=0;i<p-1;i++){
    if(arr1[i]-arr1[i+1]==1 || arr1[i]-arr1[i+1]==-1) cnt+=1;
    else{
      count[q]=cnt;
      cnt=1;
      q++;
    }
  }
  count[q]=cnt;
  q++;
  k=count[0];
  for(int i=1;i<q;i++){
    if(k<count[i]) k=count[i];
  }
  cout<<k;
  return 0;
}