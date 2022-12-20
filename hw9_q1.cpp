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
struct Node *binarynode(struct Node *t,int x, int y){
  if(t==NULL) return t;
  else if(t->data<x && t->data<y) return binarynode(t->rchild,x,y);
  else if(t->data>x && t->data>y) return binarynode(t->lchild,x,y);
  else return t;
}
int path(struct Node *head ,int x){
  int temp=0;
  if (x<head->data){
    temp=path(head->lchild,x);
    temp=temp^head->data;
  }
  if (x>head->data){
    temp=path(head->rchild,x);
    temp=temp^head->data;
  }
  if(x==head->data) temp=temp^head->data;
  return temp;
}
int main(){
  int n,q,x,y,temp,temp2,temp3; cin>>n; 
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
    insert(arr[i]);
  }
  cin>>q;
  for(int i=0;i<q;i++){
    cin>>x; cin>>y;
    Node *temp1=binarynode(root,arr[x],arr[y]);
    temp=path(temp1,arr[y]);
    if (temp1->data==arr[x]) temp2=0;
    else if (temp1->data>arr[x]) temp2=path(temp1->lchild,arr[x]);
    else temp2=path(temp1->rchild,arr[x]);
    temp3=(temp^temp2);
    cout<<(temp3^temp1->data)<<"\n";
  }
  return 0;
}