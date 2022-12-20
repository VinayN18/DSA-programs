#include<iostream>
using namespace std;

struct Node{
  int data;
  struct Node *lchild;
  struct Node *rchild;
}*root=NULL;

void insert(int key){
  struct Node *t=root;
  struct Node *r=NULL,*p;
  if(root==NULL){
    p=(struct Node *)malloc(sizeof(struct Node));
    p->data=key;
    p->lchild=p->rchild=NULL;
    root=p;
    return;
  }
  while(t!=NULL){
    r=t;
    if(key<t->data) t=t->lchild;
    else if(key>t->data) t=t->rchild;
    else return;
  }
  p=(struct Node *)malloc(sizeof(struct Node));
  p->data=key;
  p->lchild=p->rchild=NULL;

  if(key<r->data) r->lchild=p;
  else r->rchild=p;
}

int main(){
  int n,x,p=-1; cin>>n;
  struct Node *arr[n];
  for(int i=0;i<n;i++){
    cin>>x;
    insert(x);
  }
  struct Node *temp=root;
  while(temp!=NULL || p!=-1){
    if(temp!=NULL){
      cout<<temp->data<<" ";
      p++;
      arr[p]=temp;
      temp=temp->lchild;
    }else{
      temp=arr[p];
      p--;
      temp=temp->rchild;
    }
  }
  return 0;
}