#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct queue{
  int front=-1,rear=-1;
  string *q;
};
void push(struct queue *qu, string s){
  qu->rear++;
  qu->q[qu->rear]=s;
}
string pop(struct queue *qu){
  qu->front++;
  return qu->q[qu->front];
}
int main(){
  string s,temp=""; cin>>s;
  int p=0,l=s.size();
  int arr[l];
  struct queue qu;
  qu.q=(string *)malloc(l*sizeof(string));
  for(int i=0;s[i]!='\0';i++){
    if(s[i]>='0'&&s[i]<='9'){
      arr[p]=s[i]-'0';
      p++;
    }
    else if(s[i]=='[') temp='';
    else if(s[i]==']') push(&qu,temp);
    else temp+=s[i];
  }
  for(int i=0;i<p;i++){
    for(int j=0;j<arr[i];j++){
      cout<<pop(&qu);
    }
  }
  return 0;
}