#include<iostream>
using namespace std;

struct Node{
  int data;
  struct Node *next;
}*first = NULL;

void middle(struct Node *p, int c){
  struct Node *q=p;
  struct Node *output = p;
  if(c!=0&&c!=1){
  for(int i=0;i<c-1;i++){
    p=p->next;
    q=q->next;
  }
  q=q->next->next;
  p->next = NULL;
  while(q!=NULL){
    p->next = q;
    q=q->next;
    p=p->next;
  } 
  while(output!=NULL){
    cout<<output->data<<' ';
    output=output->next;
  }
  printf("\n");
}else if(c==1){
    cout<<q->data;
    printf("\n");
}
}
int main(){
  int n,x,a; cin>>n;
    struct Node *temp,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    if(n==0) return 0;
    for(int i=0;i<n;i++){
      cin>>x;
      if(x!=0){
    cin>>a;
    first->data=a;
    first->next=NULL;
    last=first;
    for(int i=1;i<x;i++){
      cin>>a;
      temp=(struct Node*)malloc(sizeof(struct Node));
      temp->data=a;
      temp->next=NULL;
      last->next=temp;
      last=temp;
  }
  middle(first, x/2);
 }}
 return 0;
}