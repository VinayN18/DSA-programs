#include<iostream>
using namespace std;
struct Stack{
  int top=-1, *S;
};
struct Node{
  int data;
  struct Node *lchild;
  struct Node *rchild;
}*root=NULL;

void push(struct Stack *st, int x){
	 st->top++;
   st->S[st->top] = x;
}

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
      // push(st,t->lchild->data);
      total += t->lchild->data;
    }
    else total+= leftleafsum(t->lchild);
    //  push(st,leftleafsum(t->lchild,st));
  // push(st,leftleafsum(t->rchild,st));  
  total += leftleafsum(t->rchild);
  }
  return total;
}
int main(){
  int n,x,p=0,cnt=0; cin>>n;
  struct Stack st;
  st.S = (int *)malloc(n*sizeof(int));
  for(int i=0;i<n;i++){
    cin>>x;
    insert(x);
  }
  struct Node *temp=root;
  // leftleafsum(temp, &st);
  // cout<<root->data<<"end"<<endl;
  // for(int i=0;i<st.top+1;i++){
    // if(st.S[i]==root->data) break;
    // cout<<st.S[i]<<endl;
    // cnt += st.S[i];
  // }
  // int arr[st.top];
  // while(st.top!=-1){
  //   arr[p]=st.S[st.top];
  //   st.top--;
  //   cout<<arr[p]<<" vinay"<<endl;
  //   p++;
  // }
  // for(int i=p;i>-1;i--){
  //   if(arr[i]==root->data) break;
  //   cnt+=arr[i];
  // }
  cout<<leftleafsum(root);
  return 0;
}