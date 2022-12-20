#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Stack{
    int front_1=-1, rear_1=-1, front_2=-1, rear_2=-1, *q_1, *q_2, *q_temp;
};
void push(struct Stack *qu, int x){
	qu->rear_2++;
    (qu->q_2)[qu->rear_2] = x;
}
void pop(struct Stack *qu){
    int x = -1;
    if(qu->front_1!=qu->rear_1){
    	qu->front_1++;
    	x = qu->q_1[qu->front_1];
}}
void size(struct Stack qu){
    if(qu.front_1==qu.rear_1) printf("0\n");
    else printf("%d \n", qu.rear_1+1);
}
int main() {
    int n,x,front,rear; cin>>n;
    string f;
    struct Stack st;
    st.q_1 = (int *)malloc(n*sizeof(int));
    st.q_2 = (int *)malloc(n*sizeof(int));
    st.q_temp = (int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        cin>>f;
        if(f=="push"){
            scanf("%d",&x);
            push(&st,x);
            while(st.front_1!=st.rear_1){
                st.front_1++;
                push(&st, st.q_1[st.front_1]);
                pop(&st);
            }
            st.q_temp = st.q_1;
            st.q_1 = st.q_2;
            st.q_2 = st.q_temp;
            front = st.front_1;
            st.front_1 = st.front_2;
            st.front_2=front;
            rear = st.rear_1;
            st.rear_1 = st.rear_2;
            st.rear_2 = rear;
        }else if(f=="pop"){
            if(st.front_1==st.rear_1) printf("stack is empty\n");
            else pop(&st); 
        }else if(f=="size") size(st);
        else if(f=="top"){
            if(st.front_1==st.rear_1) printf("-1\n");
            else printf("%d\n", st.q_1[st.front_1+1]);
        }else if(f=="isempty"){
            if(st.front_1==st.rear_1) printf("1\n");
            else printf("0\n");
        }
    }
	return 0;
}