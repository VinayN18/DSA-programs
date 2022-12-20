#include<iostream>
using namespace std;

struct Queue{
  int front=-1, rear=-1, *q;
};
void push(struct Queue *qu, int x){
  qu->rear++;
  qu->q[qu->rear] = x;
}
int pop(struct Queue *qu){
  qu->front++;
  return qu->q[qu->front];
}
int main(){
  int n,p=0,cnt=0,max=0,temp1,temp2; cin>>n;
  int arr[n];
  struct Queue qu;
  qu.q = (int *)malloc(n*sizeof(int));
  for(int i=0;i<n;i++){
    cin>>arr[i];
    // cin>>x;
    push(&qu,arr[i]);
  }
  while(qu.front!=qu.rear){
    cnt=0;
    temp1=temp2=pop(&qu);
    for(int i=p;i<n;i++){
      if(temp1<=arr[i] && temp2<=arr[i]){
        temp2=arr[i];
        cnt++;
      }
    }
    p++;
    if(max<=cnt) max=cnt;
  }
  cout<<max;
  return 0;
}
