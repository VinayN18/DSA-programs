#include <iostream>
using namespace std;

struct Queue{
  int front=-1, rear=-1, *q;
};
void push(struct Queue *qu, int x){
  qu->rear++;
  qu->q[qu->rear]=x;
}
int pop(struct Queue *qu){
  int x;
  if(qu->front!=qu->rear){
    qu->front++;
    x=qu->q[qu->front];
  }
  return x;
}

int main(){
  int n,u,k=0; cin>>n;
  int arr[n][n], visited[n]={0};
  struct Queue qu;
  qu.q = (int *)malloc(n*sizeof(int));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++) cin>>arr[j][i];
  }
  cout<<k<<" ";
  visited[k]=1;
  push(&qu,k);
  while(qu.front!=qu.rear){
    u=pop(&qu);
    for(int j=0;j<n;j++){
      if(arr[u][j]==1 && visited[j]==0){
        cout<<j<<" ";
        visited[j]=1;
        push(&qu,j);
      }
    }
  }
  return 0;
}