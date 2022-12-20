#include<iostream>
using namespace std;
int arr[500][500];
int visit(int i, int j, int n, int m){
  arr[i][j]=0;
  for(int k=-1;k<=1;k++){
    for(int r=-1;r<=1;r++){
      if((i+k>=0 && j+r>=0) && (i+k<=n-1 && j+r<=m-1) && arr[i+k][j+r]==1) visit(i+k,j+r,n,m);
    }
  }
  return 0;
}
int main(){
  int n,m,cnt=0; cin>>n; cin>>m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++) cin>>arr[i][j];
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(arr[i][j]==1){
        cnt++;
        visit(i,j,n,m);
      }
    }
  }
  cout<<cnt;
  return 0;
}