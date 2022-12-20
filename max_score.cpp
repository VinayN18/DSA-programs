#include<iostream>
using namespace std;
int maximize(int arr[],int n,int front,int back){
    if (back<front){return 0;}
    int score1,score2,score3,score4;
    score1=arr[front]+maximize(arr,n,front+2,back);
    score3=arr[front]+maximize(arr,n,front+1,back-1);
    score2=arr[back]+maximize(arr,n,front,back-2);
    score4=arr[back]+maximize(arr,n,front+1,back-1);
    int a=min(score1,score3);
    int b=min(score2,score4);
    return max(a,b);
}
int main(){
    int n;cin>>n;
    int arr[n];
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<maximize(arr,n,0,n-1);
}