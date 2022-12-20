#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Stack{
    int t=-1, *S;
};

void push(struct Stack *st, int x){
	 st->t++;
   st->S[st->t] = x;
}
void pop(struct Stack *st){
    int x = -1;
  if(st->t!=-1)
    x = st->S[st->t--];
}
void top(struct Stack st){
  if(st.t==-1) printf("-1\n");
  else printf("%d \n", st.S[st.t]);
}
void getmin(struct Stack st){
  int temp=st.S[0];
  if(st.t==-1) printf("-1\n");
  else{
    for(int i=0;i<(st.t+1);i++){
      if(temp>st.S[i]) temp=st.S[i];
    }}
    printf("%d\n",temp);
}
int main(){
  int n,x; cin>>n;
  string f;
  struct Stack st;
  st.S = (int *)malloc(n*sizeof(int));
  for(int i=0;i<n;i++){
		cin>>f;
      if(f=="push"){
        scanf("%d",&x);
        push(&st, x);
      }else if(f=="pop"){
        pop(&st);
      }else if(f=="top"){
        top(st);
      }else if(f=="getmin"){
        getmin(st);
      }
  }
  return 0;
}