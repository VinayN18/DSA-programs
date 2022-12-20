#include <iostream>
#include<stdlib.h>
#include<string>
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
    if(st->top==-1)
    	printf("stack is empty\n");
    else x = st->S[st->top--];
}
void peek(struct Stack st){
    if(st.top==-1)
        printf("-1\n");
    else
        printf("%d \n", st.S[st.top]);
}
void size(struct Stack st){
    if(st.top==-1)
        printf("0\n");
    else
        printf("%d \n", st.top+1);
}
void isempty(struct Stack st){
    if(st.top==-1)
        printf("1\n");
    else   
        printf("0\n");    
}
int main() {
    int n,x;
    string f;
    scanf("%d",&n);
    struct Stack st;
    st.S = (int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
			cin>>f;
        if(f=="push"){
            scanf("%d",&x);
            push(&st, x);
        }else if(f=="pop"){
            pop(&st);
        }else if(f=="peek"){
            peek(st);
        }else if(f=="size"){
            size(st);
        }else if(f=="isempty"){
            isempty(st);
        }
    }
    return 0;
}