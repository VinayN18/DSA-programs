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
  int n,x,r,p=0,q=0,cnt=0; cin>>n; cin>>x;
  int weights[n],weightsgreater[n],weightslesser[n];
  for(int i=0;i<n;i++) cin>>weights[i];
  QuickSort(weights,0,n);
  for(int i=0;i<n;i++){
    if(weights[i]>=x){
      weightsgreater[p]=weights[i];
      cnt++;
      p++;
    }
    else{
      weightslesser[q]=weights[i];
      q++;
    }
  }
  p=q;
  r=0;
  for(int i=q-1;i>r;i--){
    if(weightslesser[r]+weightslesser[i]<=x){
      p--;
      r++;  
    }
  }
  cout<<cnt+p;
  return 0;
}