#include<iostream>
using namespace std;
struct Stack{
    int top=-1, *S;
};

void push(struct Stack *st, int x){
	st->top++;
    st->S[st->top] = x;
}
void check_right(struct Stack st, int *arr, int i, int n){
    int cnt=0;
    if(i<n-1){
        for(int j=i+1;j<n;j++){
            if(st.S[i]>st.S[j]) cnt+=1;
            else break;
        }}
    arr[i] = cnt;
}
void check_left(struct Stack st, int *arr, int i){
    int cnt=0;
    if(i>0){
        for(int j=i-1;j>=0;j--){
            if(st.S[i]>st.S[j]) cnt+=1;
            else break;
    }}
    arr[i] = cnt;
}
int main(){
    int n,x; cin>>n;
    int arr_l[n], arr_r[n];
    struct Stack st;
    st.S = (int *)malloc(n*sizeof(int));
  for(int i=0;i<n;i++){
      cin>>x;
      push(&st, x);
  }
  for(int i=0;i<n;i++){
    check_left(st,arr_l,i);
    check_right(st,arr_r,i,n);
  }
  for(int i=0;i<n;i++){
    printf("%d ", arr_l[i]+arr_r[i]);
  }
  return 0;
}