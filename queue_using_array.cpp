#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
using namespace std;

struct Queue{
    int front=-1, rear=-1, *q;
};

void push(struct Queue *qu, int x){
	qu->rear++;
    qu->q[qu->rear] = x;
}
void pop(struct Queue *qu){
    int x = -1;
    if(qu->front==qu->rear)
    	printf("queue is empty\n");
    else{
    	qu->front++;
    	x = qu->q[qu->front];
}}
void front(struct Queue qu){
    if(qu.front==qu.rear)
        printf("-1\n");
    else{
    	qu.front++;
        printf("%d \n", qu.q[qu.front]);
}}
void back(struct Queue qu){
	if(qu.front==qu.rear)
        printf("-1\n");
    else
    	printf("%d \n", qu.q[qu.rear]);
}
void size(struct Queue qu){
    if(qu.front==qu.rear)
        printf("0\n");
    else
        printf("%d \n", qu.rear+1);
}
void isempty(struct Queue qu){
    if(qu.front==qu.rear)
        printf("1\n");
    else   
        printf("0\n");    
}
int main() {
    int n,x;
    string f;
    scanf("%d",&n);
    struct Queue qu;
    qu.q = (int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
			cin>>f;
        if(f=="push"){
            scanf("%d",&x);
            push(&qu, x);
        }else if(f=="pop"){
            pop(&qu);
        }else if(f=="front"){
            front(qu);
        }else if(f=="back"){
        	back(qu);
        }else if(f=="size"){
            size(qu);
        }else if(f=="isempty"){
            isempty(qu);
        }
    }
    return 0;
}