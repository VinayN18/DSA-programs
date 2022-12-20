#include<iostream>
using namespace std;
struct stack{
  int *s, top=-1;
};
void push(struct stack *st, int x){
  st->top++;
  st->s[st->top]=x;
}
void pop(struct stack *st){
    st->top--;
}
int main(){
  int n,m,k,u,v,temp; cin>>n; cin>>m; cin>>k;
  int arr[n][n];
  bool temp1=false;
  struct stack st;
  st.s = (int *)malloc(n*sizeof(int));
  int visited[n]={0};
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++) arr[i][j]=0;
  }
  for(int i=0;i<m;i++){
    cin>>u; cin>>v;
    arr[u-1][v-1]++;
    arr[v-1][u-1]++;
  }
  visited[0]=1;
  push(&st,0);
  while(st.top!=-1){
    temp=st.s[st.top];
    pop(&st);
    if(temp==n-1){
      temp1=true;
      break;
    }
    else if(temp!=k-1){
      for(int i=0;i<n;i++){
        if(arr[temp][i]!=0 && visited[i]==0){
          visited[i]=1;
          push(&st,i);
        }
      }
    }
  }
  temp1 ? cout<<1 : cout<<0;
  return 0;
}