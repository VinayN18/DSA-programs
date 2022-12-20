#include<iostream>
using namespace std;
void swap(double *x1, double *y1, int *x2, int *y2, int *x3, int *y3){
  double temp1=*x1;
  *x1=*y1;
  *y1=temp1;
  int temp2=*x2;
  *x2=*y2;
  *y2=temp2;
  int temp3=*x3;
  *x3=*y3;
  *y3=temp3;
}
int partition(double a[],int weights[], int values[], int l, int h){
  double p=a[l];
  int i=l, j=h;
  do{
    do{i++;}while(a[i]<=p);
    do{j--;}while(a[j]>p);
    if(i<j) swap(&a[i],&a[j],&weights[i],&weights[j],&values[i],&values[j]);
  }while(i<j);
  swap(&a[l],&a[j],&weights[l],&weights[j],&values[l],&values[j]);
  return j;
}
void QuickSort(double a[], int weights[], int values[], int l, int h){
  int j;
  if(l<h){
    j=partition(a,weights,values,l,h);
    QuickSort(a,weights,values,l,j);
    QuickSort(a,weights,values,j+1,h);
  }
}
int main(){
  int n,max; cin>>n;
  double cnt=0;
  int weights[n],values[n];
  double pw[n];
  for(int i=0;i<n;i++) cin>>weights[i];
  for(int i=0;i<n;i++) cin>>values[i];
  cin>>max;
  for(int i=0;i<n;i++) pw[i]= (double)values[i]/(double)weights[i];
  QuickSort(pw,weights,values,0,n);
  for(int i=0;i<n;i++){
    if(weights[n-i-1]<=max){
      max-=weights[n-i-1];
      cnt+=values[n-i-1];
    }else{
      cnt+=(pw[n-i-1]*max);
      break;
    }
  }
  cout<<(int)cnt;
  return 0;
}