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
  int n,out,cnt=0,temp; cin>>n;
  int intime[n],outtime1[n], outtime2[n], number[n], total[n-1];
  for(int i=0;i<n;i++){
    cin>>intime[i];
    cin>>out;
    outtime1[i]=outtime2[i]=out;
    cin>>number[i];
  }
  QuickSort(outtime2,0,n-1);
  for(int i=0;i<n;i++){
    cnt=0;
    for(int j=0;j<n;j++){
      if(outtime2[i]>intime[j] && outtime2[i]<=outtime1[j]) cnt+=number[j];
    }
    total[i]=cnt;
  }
  temp=1;
  for(int i=0;i<n;i++){
    if(temp<total[i]) temp=total[i];
  }
  cout<<temp;
  return 0;
}