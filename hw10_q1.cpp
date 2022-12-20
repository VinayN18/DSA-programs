#include<iostream>
using namespace std;
int I=INT_MAX;
void MST(void *x, int distance[], int track[], int n){
  int temp=1;
  int (*arr)[n+1] = (int (*)[n+1])x;
  while(0!=1){
    track[temp]=1;
    for(int i=1;i<n+1;i++){
      if(arr[temp][i]!=0){
        if(distance[i]>distance[temp]+arr[temp][i]) distance[i]=distance[temp]+arr[temp][i];
      }
    }
    int min=I,temp1=1;
    for(int i=1;i<n+1;i++){
      if(track[i]==0 && distance[i]<min){
        min=distance[i];
        temp1=i;
      }
    }
    if(min==I) break;
    temp=temp1;
  } 
}
int main(){
  int n,m,u,v,w; cin>>n; cin>>m;
  int arr[n+1][n+1],distance[n+1],track[n+1]={0};
  for(int i=0;i<n+1;i++){
    for(int j=0;j<n+1;j++) arr[i][j]=0;
  }
  for(int i=1;i<=m;i++){
    cin>>u; cin>>v; cin>>w;
    arr[u][v]=w;
    arr[v][u]=w;
  }
  distance[0]=distance[1]=0;
  for(int i=2;i<n+1;i++) distance[i]=I;
  MST(arr,distance,track,n);
  for(int i=1;i<n+1;i++){
    distance[i]==I ? cout<<-1<<" " : cout<<distance[i]<<" ";
  }
  return 0;
}