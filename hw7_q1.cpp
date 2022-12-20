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
  int n,k,cnt=0,p=0,q; cin>>n;
  string s;
  int arr[n],temp[n];
  for(int i=0;i<n;i++) cin>>arr[i];
  cin>>k;
  cin>>s;
  QuickSort(arr,0,n);
  for(int i=0;i<n;i++) cout<<arr[i]<<endl;
  int i;
  for(i=0;i<n;i++){
    if(arr[i]==k){
      if(cnt==0) q=i;
      cnt+=1;
    }
  }
  if(cnt>=1){
    if(s=="UP"){
      for(int j=q;j<n;j++) cout<<arr[j]<<" ";
      if(cnt>1){
        for(int j=1;j<cnt;j++) cout<<k<<" ";
      }
      for(int j=q-1;j>-1;j--) cout<<arr[j]<<" ";
    }else if(s=="Down"){
      for(int j=q;j>-1;j--) cout<<arr[j]<<" ";
      for(int j=q+1;j<n;j++) cout<<arr[j]<<" ";
    }
  }
  else{
    if(s=="UP"){
      for(int j=0;j<n;j++){
        if(k<arr[j]) cout<<arr[j]<<" ";
        else{
          temp[p]=arr[j];
          p++;
        }
      }
      for(int j=p-1;j>-1;j--) cout<<temp[j]<<" ";
    }else if(s=="Down"){
      for(int j=n-1;j>-1;j++){
        if(k>arr[j]) cout<<arr[j]<<" ";
      }
    }
  }
  return 0;
}