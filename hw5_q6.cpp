#include<iostream>
using namespace std;

struct Node{
  int data;
  struct Node *next;
}*first = NULL;

// int count(struct Node *p){
//   int l=0;
//   while(p){
//     l++;
//     p=p->next;
//   }return l;
// }
void middle(struct Node *current, struct Node **firsthalf, struct Node **secondhalf, int c){
  struct Node *p=current;
  for(int i=0;i<c;i++){
    p=p->next;
  }
  *firsthalf = current;
  *secondhalf = p->next;
  p->next=NULL;
}
struct Node *Merging(struct Node *firsthalf, struct Node *secondhalf){
  struct Node *output=NULL;
  if(firsthalf==NULL) return secondhalf;
  else if(secondhalf==NULL) return firsthalf;
  if(firsthalf->data <= secondhalf->data){
    output = firsthalf;
    output->next = Merging(firsthalf->next, secondhalf);
  }else{
    output=secondhalf;
    output->next = Merging(firsthalf,secondhalf->next);
  }
  return output;
}
struct Node *MergeSort(struct Node **head, int n){
  struct Node *current = *head;
  struct Node *firsthalf, *secondhalf;
  if(current==NULL || current->next==NULL) return current;
  middle(current,&firsthalf,&secondhalf,n/2);
  firsthalf = MergeSort(&firsthalf, n/2);
  secondhalf = MergeSort(&secondhalf, n/2);
  *head = Merging(firsthalf,secondhalf);
  return *head;
}
int main(){
  int n,x; cin>>n; cin>>x;
    struct Node *temp,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
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
  MergeSort(&first,n);
  for(int i=0;i<n;i++){
    cout<<first->data<<" ";
    first=first->next;
  }
  return 0;
}