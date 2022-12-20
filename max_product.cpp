#include<iostream>
using namespace std;
int recursive(int arr[],int index,int n,int maxim){int len=1;
   if (index>n-1){
   	return 0;}
   for (int j=index+1;j<n;j++){
       if (arr[j]>maxim){
           int len1=recursive(arr,j,n,maxim);
           maxim=arr[j];
           int len2=1+recursive(arr,j,n,maxim);
           len=max(len1,len2);
           return len;
       }
   }
   return len;}
       
 
int main(){
    int n;cin>>n;
    int arr[n];
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    int len;int max_len=0;
    for (int i=0;i<n;i++){
        len=recursive(arr,i,n,arr[i]);
        if (len>max_len){max_len=len;}
    }cout<<max_len;
}