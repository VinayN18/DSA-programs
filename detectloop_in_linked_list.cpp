#include<iostream>
using namespace std;
/*Driver code starts*/
typedef struct Node{
  int data;
  Node *next;
  
}Node;

Node *insert(Node* end, int val){
  Node *n= new Node;
  n->data=val;
  n->next=NULL;
  end->next=n;
  return n;
}

void loopHere(Node *head, Node *tail, int position){
  if(position==0) return;
  Node *walk=head;
  int i=0;
  while(i<position-1){
    walk=walk->next;
    i++;
  }
  // cout<<walk->data<<'\n';
  tail->next=walk;
}
/*Driver code ends*/


Node *solve(Node *head){
  int j,i=1,cnt=0;
  Node *arr[100];
  arr[0]=head;
  Node *p = head;
  Node *q = head;
  Node *loop = new Node;
  Node *temp = loop;
  if(p->next==p){
    p->next = NULL;
    return p;
  }
  p=p->next;
  while(true){
    if(p->next==NULL) return head;
    for(j=0;j<i;j++){
      if(arr[j]==p) break;
    }
    if(arr[j]==p) break;
    arr[i]=p;
    p=p->next;  
    i++;
  }
  loop->data = p->data;
  loop->next = NULL;
  p=p->next;
  while(p!=arr[j]){
    temp = insert(temp,p->data);
    p=p->next;
  }
  while(q->next!=p || cnt==0){
    if(q==p) cnt+=1;
    if(cnt==2) break;
    q=q->next;
  }
  q->next = loop;
  return head;
}


/*Driver code starts*/
int main(){
  int n;cin>>n;
  Node *head= new Node;
  int temp;cin>>temp;
  head->data=temp;
  head->next=NULL;
  Node *end=head;
  for(int i=1;i<n;i++){
    cin>>temp;
    end=insert(end,temp);
  }

  int position;cin>>position;
  loopHere(head,end,position);

  head=solve(head);
  Node *ptr=head;
  
  while(ptr){
    cout<<ptr->data<<' ';
    ptr=ptr->next;
  }
}
/*Driver code ends*/