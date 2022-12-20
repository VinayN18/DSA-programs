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
int binsearch(int *arr, int k, int low, int high){
  // int mid = (low+high)/2;
  cout<<low<<" LOW"<<endl;
  cout<<high<<" high"<<endl;
  if(high>=low){
    int mid = (low+high)/2;
    cout<<arr[mid]<<" middle"<<endl;
    if(k==arr[mid]) return mid;
    else if(k<arr[mid]){
      return binsearch(arr,k, low, mid-1);
    }else{ 
      return binsearch(arr,k,mid+1,high);
  }}
  return -1;
}
int main(){
  int n,k; cin>>n;
  int arr[n], sortedarr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
    // arr[i]=sortedarr[i];
    cout<<arr[i]<<" array"<<endl;
  }
  cin>>k;
  // QuickSort(sortedarr,0,n);
  int output = binsearch(arr,k,0,n-1);
  cout<<output;
  return 0;
}
/*
#include<iostream>
using namespace std ;

int binarysearch(int* arr , int n , int k){
    if(n==0) return 0;
    int p=n/2;
    if(arr[p]==k) return p;
    else if(arr[p]>k) return binarysearch(arr,p,k);
    else return p+1+binarysearch(arr+p+1, n-p+1, k);
    return 0;
}
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
    int n,k; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cin>>k;
    QuickSort(sortedarr,0,n);
    int p = binarysearch(sortedarr,n,k);
    if(arr[p]==k) cout<<p;
    else cout<<-1;
    return 0;
}*/