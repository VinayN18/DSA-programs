#include<iostream>
using namespace std;
/*Driver code starts*/
typedef struct Node{
    int data;
    struct Node *next;

    Node (int x){
        data = x;
        next = NULL;
    }
}Node;
/*Driver code ends*/

Node *solve(Node *head1, Node *head2, int n, int m){
  Node *p = head1;
  Node *q = head2;  
  if(n>m){
  for(int i=0;i<n;i++){
    q = head2;
    for(int j=0;j<m;j++){
      if(p!=q){
        q=q->next;
      }else break;
    }
    if(p==q) break;
    p=p->next;
  }
  Node *p1 = head1;
  Node *q1 = head2;
  while(p1->next!=p) p1=p1->next;
  p1->next=q1;
  return head1;
  }
  else{
    for(int i=0;i<m;i++){
    p = head1;
    for(int j=0;j<n;j++){
      if(p!=q){
        p=p->next;
      }else break;
    }
    if(p==q) break;
    q=q->next;
  }
  Node *p1 = head1;
  Node *q1 = head2;
  while(q1->next!=q) q1=q1->next;
  q1->next=p1;
  return head2;
  }
}

/*Driver code starts*/
Node *insertAtEnd(Node *end,int x){
    Node *n=new Node(x);
    end->next=n;
    return n;
}
int main(){
    int n,m;cin>>n>>m;
    int commonElements;cin>>commonElements;

    Node *head1=NULL;
    Node *end1=NULL;

    int temp;cin>>temp;
    head1=new Node(temp);
    end1=head1;
    for(int i=1;i<n-commonElements;i++){
        cin>>temp;
        end1=insertAtEnd(end1,temp);
    }
    cin>>temp;
   
    Node *head2=NULL;
    Node *end2=NULL;
    head2=new Node(temp);
    end2=head2;

    for(int i=1;i<m-commonElements;i++){
        cin>>temp;
        end2=insertAtEnd(end2,temp);
    }


    for(int i=0;i<commonElements;i++){
        cin>>temp;
        Node *temp1=new Node(temp);
        end1->next=temp1;
        end1=temp1;
        end2->next=temp1;
        end2=temp1;
    }

    Node *head=solve(head1,head2,n,m);
  
  while(head){
    cout<<head->data<<' ';
    head=head->next;
  }
    return 0;
}
/*Driver code ends*/
