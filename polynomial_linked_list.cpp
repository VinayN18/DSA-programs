#include<iostream>
using namespace std;

typedef struct Node{
    int data,pow;
    Node *next;
}Node;
Node *insert(Node* end,int val, int p){
  Node *n= new Node;
  n->data=val;
  n->pow=p;
  n->next=NULL;
  end->next=n;
  return n;
}
int power(int x, int p){
  int pow = 1;
  for(int i=0;i<p;i++) pow*=x;
  return pow;
}
int main(){
  int n,p1,p2,a,x,sum_1=0,sum_2=0,sum_3=0,sum_4=0; cin>>n;
  for(int i=0;i<n;i++){
    cin>>p1; cin>>p2;
    sum_1=0;sum_2=0;sum_3=0;sum_4=0;
    Node *head1=new Node;
    head1->data=0;
    head1->pow=p1;
    head1->next=NULL;
    Node *end1=head1;
    Node *head2=new Node;
    head2->data=0;
    head2->pow=p2;
    head2->next=NULL;
    Node *end2=head2;
    cin>>a;
    end1->data=a;
    for(int j=p1-1;j>-1;j--){
      cin>>a;
      end1=insert(end1,a,j);
    }
    cin>>a;
    end2->data=a;
    for(int j=p2-1;j>-1;j--){
      cin>>a;
      end2=insert(end2,a,j);
    }
    cin>>x;
    Node *walk1 = head1;
    Node *walk2 = head2;
    for(int j=0;j<p1+1;j++){
      sum_1+= (walk1->data)*power(x,walk1->pow);
      walk1 = walk1->next;
    }
    for(int j=0;j<p2+1;j++){
      sum_2+= (walk2->data)*power(x,walk2->pow);
      walk2 = walk2->next;
    }
    sum_3 = sum_1+sum_2;
    sum_4 = 5*(sum_2);
    cout<<sum_1<<' '<<sum_2<<' '<<sum_3<<' '<<sum_4;
  }
  return 0;
}