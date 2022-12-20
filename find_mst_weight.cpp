#include<iostream>
#include <climits>
using namespace std;
int I=INT_MAX;
void MST(void *x, int n){
  int u,v,min=I,total=0;
  int (*arr)[n+1] = (int (*)[n+1])x;
  int track[n+1], T[2][n-1]={0};
  for(int i=1;i<n+1;i++){
    track[i]=I;
    for(int j=1;j<n+1;j++){
      if(arr[i][j]<min){
        min=arr[i][j];
        u=i;
        v=j;
      }
    }
  }
  T[0][0]=u;
  T[1][0]=v;
  track[u]=track[v]=0;
  for(int i=1;i<n+1;i++){
    if(track[i]!=0){
      if(arr[i][u]<arr[i][v]) track[i]=u;
      else track[i]=v;
    }
  }
  for(int i=1;i<n-1;i++){
    int k;
    min=I;
    for(int j=1;j<n+1;j++){
      if(track[j]!=0 && arr[j][track[j]]<min){
        k=j;
        min=arr[j][track[j]];
      }
    }
    T[0][i]=k;
    T[1][i]=track[k];
    track[k]=0;
    for(int j=1;j<n+1;j++){
      if(track[j]!=0 && arr[j][k]<arr[j][track[j]]) track[j]=k;
    }
  }
  for(int i=0;i<n-1;i++) total+=arr[T[0][i]][T[1][i]];
  cout<<total;
}

int main(){
  int n,m,u,v,w; cin>>n; cin>>m;
  int arr[n+1][n+1];
  for(int i=0;i<=n;i++){
    for(int j=0;j<=n;j++) arr[i][j]=I;
  }
  for(int i=1;i<=m;i++){
    cin>>u; cin>>v; cin>>w;
    arr[u][v]=w;
    arr[v][u]=w;
  }
  MST(arr,n);
  return 0;
}