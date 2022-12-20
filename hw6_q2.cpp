#include<iostream>
using namespace std;

int main(){
  int n,k,cnt=0; cin>>n;cin>>k;
  int arr1[n]={0},arr2[n]={0};
  long long p,q;
  long long arr[n];
  for(int i=0;i<n;i++) cin>>arr[i];
  for(int i=0;i<n;i++){
    p=arr[i]%n;
    q=(k*arr[i])%n;
    arr1[p]++;
    arr2[q]++;
  }
  cnt=arr1[0]*arr2[0];
  for(int i=1;i<n;i++){
    for(int j=1;j<n;j++){
      if(i+j==n) cnt+=arr1[i]*arr2[j];
    }
  } 
  cout<<cnt;
  return 0;
}
/*
#include<iostream>
using namespace std;
int main(){
    int p,q;
    cin>>p>>q;
    int ar[p];
    int a[p];
    long long arr[p];
    for(int i=0;i<p;i++){
        int x;
        cin>>x;
        arr[i]=x;
        ar[i]=0;
        a[i]=0;
    }
    for(int i=0;i<p;i++){
        ar[arr[i]%p]++;
        a[(q*arr[i])%p]++;
    }
    int l=ar[0]*a[0];
    for(int i=1;i<p;i++){
        l+=ar[i]*a[p-i];
    }
    cout<<l;
    return 0;
}

*/