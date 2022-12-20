#include<iostream>
using namespace std;

int main(){
  long N,X,Y,total=0,cnt=0; 
  cin>>N; cin>>X; cin>>Y;
  total=X;
  long arr[N];
  for(int j=0;j<N;j++){
    cin>>arr[j];
    total = (total*arr[j])%100000;
    if(total>=Y){
      cout<<"YES";
      break;
    }
    else cnt+=1;
  }
  if(cnt==N) cout<<"NO";
  return 0;
}