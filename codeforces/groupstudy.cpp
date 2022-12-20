#include<iostream>
using namespace std;

int main(){
  int t; cin>>t;
  for(int i=0;i<t;i++){
    // int n;
    float n,p1,p2;
    cin>>n>>p1>>p2;
    float p=n-n*(p1+p2);
    cout<<p;
  } 
  return 0;
}