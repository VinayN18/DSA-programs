#include<iostream>
#include<string>
using namespace std;

bool Operand(char x){
  if(x=='+' || x=='-' || x=='*' || x=='/' || x=='^') return false;
  else return true;
}
int main(){
  string s1,s2; cin>>s1;
  int p=0,top=-1,value=0;
  string temp1,temp2,output;
    string Stack[100];
    p=0;
    while(s1[p]!='\0'){
      if(s1[p]==','){
        if(value!=0){
          top++;
        s2=to_string(value);
        Stack[top] = s2;
        }value=0;
      }
    else if(Operand(s1[p])){
        value = (value*10)+ (s1[p]-'0');
      }
      else if(s1[p]=='^' && top>=0){
        output= '('+Stack[top]+s1[p]+')';
        Stack[top]=output;
    }
      else{
      temp1 = Stack[top];
      // cout<<temp1<<endl;
      top--;
      temp2 = Stack[top];
      // cout<<temp2;
      top--;
      output = '('+temp2+s1[p]+temp1+')';
      top++;
      Stack[top]=output;
    }
   p++;
    }
  if(top==0) cout<<Stack[top];
  else cout<<"error";
  return 0;
}
