#include<iostream>
using namespace std;

struct Node{
  int data;
  struct Node *next;
}*first = NULL;

int main(){
  int n,x,pos1,pos2; cin>>n;
    struct Node *temp,*last,*temp1,*last1,*position1,*position2;
    first=(struct Node *)malloc(sizeof(struct Node));
    cin>>x;
    first->data=x;
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++){
      cin>>x;
      temp=(struct Node*)malloc(sizeof(struct Node));
      temp->data=x;
      temp->next=NULL;
      last->next=temp;
      last=temp;
  }
  cin>>pos1; cin>>pos2;
  last=temp=last1=temp1=first;
  while(last){
  cout<<last->data<<" ";
  last=last->next;
  }
  cout<<endl;
  if(n==1){
    cout<<temp->data;
    return 0;
  }
  for(int i=1;i<pos1-1;i++){
    if(temp->next==NULL){
      cout<<"-1";
      return 0;
    }
    else if(temp->next!=NULL) temp=temp->next;}
  for(int i=1;i<pos2-1;i++){
    if(temp1->next==NULL){
      cout<<"-1";
      return 0;
    }
    else if(temp1->next!=NULL) temp1=temp1->next;
    }
    position1 = pos1!=1?temp->next:temp;
  if(position1->next!=NULL){
  last=position1->next;}
  else last=NULL;
  position2 = pos2!=1?temp1->next:temp1;
  temp->next=NULL;
  position1->next=NULL;
  if(position2->next!=NULL){
  last1=position2->next;}
  else last1=NULL;
  temp1->next=NULL;
  position2->next=NULL;
  temp->next=position2;
  if(pos1-pos2==-1 || pos1-pos2==1) position2->next=position1;
  else position2->next=(position2==last)?temp:last;
  temp1->next=(position1==temp1)?last1:position1;
  position1->next=last1;
  last=(pos1==1||pos2==1)?position2:first;
  while(last){
  cout<<last->data<<" ";
  last=last->next;
  }
  return 0;
}