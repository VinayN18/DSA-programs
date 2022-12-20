#include<iostream>
using namespace std;

struct Stack{
  int top=-1,*S;
};

struct Node{
  int data;
  struct Node *lchild;
  struct Node *rchild;
}*root=NULL;

void preorder(struct Node *t,struct Stack *st){
    if(t!=NULL){
      st->top++;
      st->S[st->top] = t->data;
      preorder(t->lchild, st);
      preorder(t->rchild, st);
    }
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

int main(){
  int n,q,x,temp; cin>>n; cin>>q;
  for(int i=0;i<n;i++){
    cin>>x;
    insert(x);
  }
  struct Stack st;
  st.S = (int *)malloc(n*sizeof(int));
  preorder(root,&st);
  for(int i=0;i<q;i++){
    cin>>x;
    int temp=1000000000,k=0;
    for(int j=0;j<st.top+1;j++){
      if(x<=st.S[j]){
        k++;
        temp=(temp>st.S[j])?st.S[j]:temp;
      }
    }
    if(k==0) cout<<"-1"<<endl;
    else cout<<temp<<endl;
  }
  return 0;
}