#include<iostream>
using namespace std;

struct Stack{
  int top=-1;
  float *S;
};
void push(struct Stack *st, float x){
    st->top++;
  st->S[st->top] = x;
}
int pop(struct Stack *st){
    return st->S[st->top--];
}
bool Operand(char x){
  if(x=='+' || x=='-' || x=='*' || x=='/' || x=='^') return false;
  else return true;
}
int main(){
  string s; cin>>s;
  struct Stack st;
  float temp1,temp2,value=0,r=0;
  int p=0;
  st.S = (float*)malloc(100*sizeof(float));
    p=0;
    while(s[p]!='\0'){
      if(s[p]==','){
        if(value!=0){ push(&st,value);}
        value=0;}
      else if(Operand(s[p])){
        value = (value*10)+ (s[p]-'0');
      }else{

        if(s[p]=='^'&& st.top!=-1){
          temp1=pop(&st);
          push(&st,temp1*temp1);
        }
        else{
          temp1 = pop(&st);
          temp2 = pop(&st);
          switch(s[p]){
            case '+':r=temp2+temp1;break;
            case '-':r=temp2-temp1;break;
            case '*':r=temp2*temp1;break;
            case '/':{
              r=temp2/temp1;
              if(r>0) r=(float)((int)(r*100+0.5))/100;
              else if(r<0) r=(float)((int)(r*100-0.5))/100;
              break;}
          }
          push(&st,r);
        }
      }
      p++;
    }
  if(st.top==0) cout<<st.S[st.top]; 
  else cout<<"error"; 
  return 0;
}