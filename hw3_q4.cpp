#include<iostream>
using namespace std;

int main(){
  int n,x,p=0,q=0,cnt=0; cin>>n;
  for(int i=0;i<n;i++){
    cin>>x;
    if(x%3==0) cnt++;
    else if(x%3==1) p++;
    else if(x%3==2) q++;
  }
  if(p>q) cout<<cnt+q+(p-q)/3;
  else if(p<q) cout<<cnt+p+(q-p)/3;
  else cout<<cnt+p;
  
}  