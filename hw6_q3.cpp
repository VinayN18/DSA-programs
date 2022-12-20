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
  int n,cnt1=0,cnt2=0; cin>>n;
  int arr[n], temp[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
    temp[i]=arr[i];
  }
  QuickSort(temp,0,n);
  int i,j;
  for(i=0;i<n;i++){
    if(arr[i]==temp[i]) cnt1+=1;
    else break;
  }
  if(cnt1==n){
    cout<<-1;
    return 0;
  }
  for(j=n-1;j>-1;j--){
    if(arr[j]==temp[j]) cnt2+=1;
    else break;
  }
  cout<<j-i+1;
  return 0;
}