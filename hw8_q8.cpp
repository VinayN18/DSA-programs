#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct queue{
  int front=-1, rear=-1, *q;
};
void push(struct queue *qu, int x){
  qu->rear++;
  qu->q[qu->rear] = x;
}
int detection(int arr[][], int n, int p, int viisited[]){
  struct queue qu;
  qu.q=(int *)malloc(n*sizeof(int));
  visited[p]=1;
  push(&qu,p);
  for()
}
int main(){
  int n,m,u,v,temp; cin>>n; cin>>m;
  int arr[n+1][n+1];
  int visited[n+1]={-1};
  for(int i=0;i<n+1;i++){
    for(int j=0;j<n+1;j++) arr[i][j]=0;
  }
  for(int i=0;i<m;i++){
    cin>>u; cin>>v;
    arr[u][v]=1;
    arr[v][u]=1;
  }
  for(int i=1;i<n+1;i++){
    if(visited[i]==-1){
      temp=detection(arr,n,i,-1,visited);
      if(temp==1) break;
    }
  }
  temp==1 ? cout<<"Yes" : cout<<"No";
  return 0;
}