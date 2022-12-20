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
  int total=0;
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
int leftleafsum(struct Node *t){
  int total=0;
  if(t!=NULL){
    if(t->lchild==NULL) total+= leftleafsum(t->lchild);
    else if(t->lchild->lchild==NULL && t->lchild->rchild==NULL){
      total += t->lchild->data;
    }
    else total+= leftleafsum(t->lchild);
  total += leftleafsum(t->rchild);
  }
  return total;
}
int main(){
  int n,x; cin>>n;
  for(int i=0;i<n;i++){
    cin>>x;
    insert(x);
  }
  struct Node *temp=root;
  cout<<leftleafsum(temp);
  return 0;
}