#include<iostream>
using namespace std;

struct Node{
  int data;
  struct Node *lchild;
  struct Node *rchild;
}*root=NULL;

int search(int key){
  struct Node *t = root;
  while(t!=NULL){
    if(key==t->data){ 
      return 1;
    }else if(key<t->data) t=t->lchild;
    else t=t->rchild;
  }
  return 0;
}
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
struct Node *binarynode(struct Node *t,int x, int y){
  if(t==NULL) return t;
  else if(t->data<x && t->data<y) return binarynode(t->rchild,x,y);
  else if(t->data>x && t->data>y) return binarynode(t->lchild,x,y);
  else return t;
}
int main(){
  int n,q,x,y,temp; cin>>n; cin>>q;
  for(int i=0;i<n;i++){
    cin>>x;
    insert(x);
  }
  for(int i=0;i<q;i++){
    cin>>x; cin>>y;
    if(search(x)==1 && search(y)==1){
      Node *temp1=binarynode(root,x,y);
      cout<<temp1->data<<endl;
    }else cout<<"-1"<<endl;
  }
}