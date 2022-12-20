#include<iostream>
using namespace std;

struct Stack{
    int top_1=-1, top_2=-1;
    char *s_1, *s_2;
};
void push1(struct Stack *st, char x){
	st->top_1++;
    st->s_1[st->top_1] = x;
}
void push2(struct Stack *st, char x){
	st->top_2++;
    st->s_2[st->top_2] = x;
}

int main(){
  int cnt=0;
  char temp;
  string f; cin>>f;
  int n = f.length();
  struct Stack q;
  q.s_1 = (char *)malloc(n*sizeof(char));
  q.s_2 = (char *)malloc(n*sizeof(char));
  for(int i=0;i<n;i++) push1(&q, f[i]);
  while((q.top_1)!=-1){
    temp = q.s_1[q.top_1];
    q.top_1--;
    push2(&q, temp);
  }
  for(int i=0;i<n;i++){
    if(q.s_1[i]==q.s_2[i]) cnt+=1;
  }
  if(cnt==n) printf("1");
  else printf("0");
  return 0;
}