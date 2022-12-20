#include<iostream>
using namespace std;

struct Queue{
    int top_1=-1, top_2=-1, *s_1, *s_2;
};
void push1(struct Queue *st, int x){
	st->top_1++;
    st->s_1[st->top_1] = x;
}
void push2(struct Queue *st, int x){
	st->top_2++;
    st->s_2[st->top_2] = x;
}
void pop1(struct Queue *st){
    int x = -1;
    if(st->top_1==-1)
    	printf("stack is empty\n");
    else x = st->s_1[st->top_1--];
}
void pop2(struct Queue *st){
    int x = -1;
    if(st->top_2==-1)
    	printf("stack is empty\n");
    else x = st->s_2[st->top_2--];
}
int main(){
    int n,x,temp;
    string f;
    scanf("%d",&n);
    Queue q;
    q.s_1 = (int *)malloc(n*sizeof(int));
    q.s_2 = (int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
		cin>>f;
        if(f=="push"){
            scanf("%d",&x);
            push1(&q, x);
        }else if(f=="pop"){
            if((q.top_1)==-1) printf("empty\n");
            else{ 
                while((q.top_1)!=-1){
                temp = q.s_1[q.top_1];
                push2(&q, temp);
                pop1(&q); 
                }printf("%d\n",(q.s_2)[q.top_2]);
                pop2(&q);
                while((q.top_2)!=-1){
                    temp = q.s_2[q.top_2];
                    push1(&q, temp);
                    pop2(&q);
        }}}}
    return 0;
}