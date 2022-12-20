#include<iostream>
using namespace std;

int total[1000000];
int p=0;
typedef struct Node{
  int data;
  Node *lchild;
  Node *rchild;
}Node;
Node *Newnode(int data) {
  Node *n = new Node;
  n->lchild = NULL;
  n->data = data;
  n->rchild = NULL;
  return n;
}
int search(int preorder[], int inorder[], int start, int n){
    for (int i=start;i<=n;i++){
        if(preorder[start]==inorder[i]) return i;
    }
    return 0;
}
Node *gettree(int preorder[], int inorder[], int start1, int start2,int n){
  cout<<"moksha";
    int i = 0;
    if(n==0 || n<0) return NULL;
    Node* node = new Node;
    node = Newnode(preorder[start1]);
    // if(start==end) return node;
    int split = search(preorder,inorder, start1, n);
    node->lchild = gettree(preorder, inorder, start1+1, start2, split);
    node->rchild = gettree(preorder, inorder, start1+1+split, start2+1+split, n-split-1);
    return node;
}
void DFS(Node *temp, int sum){
  if(temp==NULL) return;
  sum+=temp->data;
  if(temp->lchild==NULL && temp->rchild==NULL){
    total[p]=sum;
    cout<<sum<<" hello";
    p++;
    return;
  }
  DFS(temp->lchild,sum);
  DFS(temp->rchild,sum);
}
void traversal(Node *temp,int t, int n){
  int cnt=0;
  cout<<"vinay";
  DFS(temp,0);
  for(int j=0;j<=p;j++){
    if(total[j]==t){
      cnt+=1;
      break;
    }
  }
  if(cnt>=1) cout<<"true";
  else cout<<"false";
}
int main(){
  int n,t; cin>>n; cin>>t;
  int preorder[n], inorder[n];
  for(int j=0;j<n;j++) cin>>preorder[j];
  for(int j=0;j<n;j++) cin>>inorder[j];
  Node *tree = new Node;
  tree = gettree(preorder, inorder, 0, 0,n);
  traversal(tree,t,n);
  return 0;
}