#include<iostream>
using namespace std;

struct Node{
  int data;
  struct Node *next;
}*first = NULL;

int count(struct Node *p){
  int l=0;
  while(p){
    l++;
    p=p->next;
  }return l;
}
void middle(struct Node *p, int c){
  for(int i=0;i<c;i++){
    p=p->next;
  }cout<<p->data;
}
int main(){
  int n,x; cin>>n;
    cin>>x;
    struct Node *temp,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=x;
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++){
      cin>>x;
      temp=(struct Node*)malloc(sizeof(struct Node));
      temp->data=x;
      temp->next=NULL;
      last->next=temp;
      last=temp;
  }
  int c = count(first);
  middle(first, c/2);
  return 0;
}