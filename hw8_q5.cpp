#include<iostream>
using namespace std;

int binsearch(int arr[], int low, int high, int n, int k){
    if(high>=low){
        int middle = (low+high)/2;
        if(arr[middle]==k) return middle;
        else if(arr[middle]<k){
            if(middle+1==n || arr[middle+1]>k) return middle+1;
            else return binsearch(arr,middle+1,high,n,k);
        }
        else return binsearch(arr,low,middle-1,n,k);
    }
    return 0;
}
int main(){
  int n,k; cin>>n;
  int arr[n];
  for(int i=0;i<n;i++) cin>>arr[i];
  cin>>k;
  if(k<arr[0]) cout<<0;
  else cout<<binsearch(arr,0,n-1,n,k);
  return 0;
}