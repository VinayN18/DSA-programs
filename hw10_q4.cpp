#include<iostream>
using namespace std;
void schedule(void *x, int n, int m){
  int cnt=0;
  int (*arr)[n+1] = (int (*)[n+1])x;
  int track[n+1]={0};
  for(int i=1;i<n+1;i++){
    track[i]=1;
    for(int j=1;j<n+1;j++){
      if(arr[i][j]==1 && track[j]==0){
        track[j]=1;
        cnt++;
      }
    }
  }
  if(cnt==m) cout<<"Yes";
  else cout<<"No";
}
int main(){
  int n,m,u,v; cin>>n; cin>>m;
  int arr[n+1][n+1];
  for(int i=0;i<n+1;i++){
    for(int j=0;j<n+1;j++) arr[i][j]=0;
  }
  for(int i=0;i<m;i++){
    cin>>u; cin>>v;
    arr[u][v]=1;
    arr[v][u]=1;
  }
  schedule(arr,n,m);
  return 0;
}