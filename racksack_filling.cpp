#include<iostream>
using namespace std;

int main(){
  int n,max; cin>>n;
  int weights[n],values[n];
  for(int i=0;i<n;i++) cin>>weights[i];
  for(int i=0;i<n;i++) cin>>values[i];
  cin>>max;
  int arr[n+1][max+1];
  for(int i=0;i<n+1;i++){
    for(int j=0;j<max+1;j++){
      if(i==0||j==0) arr[i][j]=0;
      else{
          if(j<weights[i-1]) arr[i][j]=arr[i-1][j];
          else arr[i][j] = arr[i-1][j]>(arr[i-1][j-weights[i-1]]+values[i-1]) ? arr[i-1][j] : arr[i-1][j-weights[i-1]]+values[i-1];
      }
    }
  }
  cout<<arr[n][max];
  return 0;
}