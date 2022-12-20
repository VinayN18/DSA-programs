/*#include<iostream>
using namespace std;

struct Stack{
  int top=-1, *S;
}
void push(struct Stack *st, int x){
	st->top++;
    st->S[st->top] = x;
}
int main(){
  int n,x,cnt=0; cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>x;
    arr[i]=x;
  }
  for(int i=0; i<n;i++){
      cnt=0;
      for(int j=i-1;j>-1;j--){
          if(arr[i]<arr[j]){
            cnt+=1;
            break;
            }
          cnt+=1;  
      }
      if(i==0) printf("1 ");
      else printf("%d ",cnt);   
  }
}
*/
#include<iostream>
using namespace std;

struct Stack{
  int top=-1, *S;
};
void push(struct Stack *st, int x){
	st->top++;
  st->S[st->top] = x;
}
void pop(struct Stack *st){
  int x = -1;
  if(st->top!=-1) x=st->S[st->top--];
}
int main(){
  int n,x; cin>>n;
  int arr[n],s[n];
  struct Stack st;
  st.S = (int *)malloc(n*sizeof(int));
  for(int j=0;j<n;j++){
    cin>>x;
    arr[j]=x;
  }
  push(&st, 0);
  s[0]=1;
  for(int i=1;i<n;i++){
    while(st.top!=-1 && arr[st.S[st.top]]<=arr[i]) pop(&st);
    if(st.top==-1) s[i]=i+1;
    else s[i]=i-st.S[st.top];
    push(&st,i);
  }
  for(int j=0;j<n;j++) cout<<s[j]<<endl;
  return 0;
}