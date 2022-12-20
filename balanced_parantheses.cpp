#include<iostream>
using namespace std;
struct Stack{
    int top=-1;
    char *S;
};
void push(struct Stack *st, char x){
	st->top++;
    st->S[st->top] = x;
}
void pop(struct Stack *st){
    char x;
    if(st->top!=-1)
        x = st->S[st->top--];
}
int main(){
  string s; cin>>s;
  int n=s.length();
  struct Stack st;
  st.S = (char *)malloc(n*sizeof(char));
  char temp;
  for(int i=0;i<n;i++){
    if(s[i]=='(' || s[i]=='{' || s[i]=='[') 
        push(&st,s[i]);
    else if(s[i]==')' || s[i]=='}' || s[i]==']'){
        if(st.top==-1){
          printf("0");
          return 0;
        }else{
            temp = st.S[st.top];
            pop(&st);
            if(s[i]==')'&& (temp=='{' || temp=='[')){
              printf("0");
              return 0;
            }else if(s[i]=='}'&& (temp=='(' || temp=='[')){
              printf("0");
              return 0;
            }else if(s[i]=='}'&& (temp=='(' || temp=='[')){
              printf("0");
              return 0;
            }
        }
    }
  }
  if(st.top==-1) printf("1");
  else printf("0");
  return 0;
}