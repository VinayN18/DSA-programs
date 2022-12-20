#include<iostream>
using namespace std;

struct Node{
  struct Node *lchild;
  int data;
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
struct Node * search(int key){
  struct Node *t = root;
  // struct Node *temp2 = root;
  while(t!=NULL){
    if(key==t->data){
      // cout<<t->data;
      return t;
    }else if(key<t->data){
      // cout<<t->data<<" ";
      t=t->lchild;
    }else{
      // cout<<t->data<<" ";
      t=t->rchild;
    }
  }
  return NULL;
}
void print(struct Node *temp, int key){
  struct Node *t = root;
  while(t!=temp){
    if(key==t->data){
      cout<<t->data;
      break;
    }else if(key<t->data){
      cout<<t->data<<" ";
      t=t->lchild;
    }else{
      cout<<t->data<<" ";
      t=t->rchild;
    }
  }cout<<t->data<<endl;
}
int main(){
  int n,q,x; cin>>n; cin>>q;
  struct Node *temp;
  for(int i=0;i<n;i++){
    cin>>x;
    insert(x);
  }
  for(int i=0;i<q;i++){
    cin>>x;
    temp = search(x);
    if(temp==NULL) cout<<"-1"<<endl;
    else print(temp,x);
  }
  return 0;
}