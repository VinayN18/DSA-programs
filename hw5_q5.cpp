#include<iostream>
using namespace std;
void swap(float *x, float *y){
  float temp=*x;
  *x=*y;
  *y=temp;
}
int partition(float a[], int l, int h){
  float p=a[l];
  int i=l, j=h;
  do{
    do{i++;}while(a[i]<=p);
    do{j--;}while(a[j]>p);
    if(i<j) swap(&a[i],&a[j]);
  }while(i<j);
  swap(&a[l],&a[j]);
  return j;
}
void QuickSort(float a[], int l, int h){
  int j;
  if(l<h){
    j=partition(a,l,h);
    QuickSort(a,l,j);
    QuickSort(a,j+1,h);
  }
}
int main(){
  int n,k,p=0,q=0,cnt=0; cin>>n;
  float median,t;
  float weights[n],median_wts1[n],median_wts2[n],output[n],temp[2];
  for(int i=0;i<n;i++) cin>>weights[i];
  cin>>k;
  QuickSort(weights,0,n);
  if(n==4) median=weights[2];
  else if(n%2!=0) median=weights[n/2];
  else median=(weights[n/2]+weights[n/2-1])/2;
  t=weights[0];
  for(int i=0;i<n;i++){
    if(weights[i]==t) cnt+=1;
  }
  if(cnt==n){
    for(int i=0;i<k;i++) cout<<weights[i]<<" ";
  }
  else{
  for(int i=0;i<n;i++) median_wts1[i]=median_wts2[i]=abs(weights[i]-median);
  QuickSort(median_wts2,0,n);
  for(int i=n-1;i>n-k-1;i--){
    if(median_wts2[i]!=median_wts2[i-1]){
      for(int j=0;j<n;j++){
        if(median_wts2[i]==median_wts1[j]){
          output[p]=weights[j];
          p++;
          break;
        }
      }
    }else{
      q=0;
      for(int j=0;j<n;j++){
        if(median_wts2[i]==median_wts1[j]){
          temp[q]=j;
          q++;
        }
      }
      q=temp[0];
      int r=temp[1];
      output[p]=(weights[q]>weights[r])?weights[q]:weights[r];
        p++;
    }
  }
  QuickSort(output,0,p);
  for(int i=0;i<k;i++) cout<<output[i]<<" ";
  }
  return 0;
}
/*
#include<iostream>
using namespace std;
void swap(float *x, float *y){
  float temp=*x;
  *x=*y;
  *y=temp;
}
int partition(float a[], int l, int h){
  float p=a[l];
  int i=l, j=h;
  do{
    do{i++;}while(a[i]<=p);
    do{j--;}while(a[j]>p);
    if(i<j) swap(&a[i],&a[j]);
  }while(i<j);
  swap(&a[l],&a[j]);
  return j;
}
void QuickSort(float a[], int l, int h){
  int j;
  if(l<h){
    j=partition(a,l,h);
    QuickSort(a,l,j);
    QuickSort(a,j+1,h);
  }
}
int main(){
  int n,k,p=0,q=0; cin>>n;
  float median;
  float weights[n],median_wts1[n],median_wts2[n],output[n],temp[2];
  for(int i=0;i<n;i++) cin>>weights[i];
  cin>>k;
  QuickSort(weights,0,n);
  if(n%2!=0) median=weights[n/2];
  else median=(weights[n/2]+weights[n/2-1])/2;
  for(int i=0;i<n;i++) median_wts1[i]=median_wts2[i]=abs(weights[i]-median);
  QuickSort(median_wts2,0,n);
  for(int i=n-1;i>n-k-1;i--){
    if(median_wts2[i]!=median_wts2[i-1]){
      for(int j=0;j<n;j++){
        if(median_wts2[i]==median_wts1[j]){
          output[p]=weights[j];
          p++;
          break;
        }
      }
    }else{
      q=0;
      for(int j=0;j<n;j++){
        if(median_wts2[i]==median_wts1[j]){
          temp[q]=j;
          q++;
        }
      }
      q=temp[0];
      int r=temp[1];
      output[p]=(weights[q]>weights[r])?weights[q]:weights[r];
        p++;
    }
  }
  QuickSort(output,0,p);
  for(int i=0;i<k;i++) cout<<output[i]<<" ";
  return 0;
}*/