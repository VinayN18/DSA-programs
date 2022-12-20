/*#include<iostream>
#include<string>
using namespace std;

int main(){
  int n,i=1,p=1,temp,rem,cnt=0,cnt1=0,cnt2=0; cin>>n;
  string temp1;
  while(true){
    temp=n*i;
    temp1=to_string(temp);
    cnt1=cnt2=cnt=0;
    while(temp!=0){
      // cout<<"hello"<<endl;
      rem=temp%10;
      // cout<<rem<<" rem";
      if(rem==0) cnt1+=1;
      else if(rem==1) cnt2+=1;
      temp/=10; 
      cnt+=1;
      p++;
      // cout<<temp<<endl;
    }
    if(cnt1+cnt2==cnt && cnt1!=0 && cnt2!=0) break;
    i++;
  }
  cout<<temp1;
  return 0;
}
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
#include<iostream>
#include<string>
using namespace std;

int main(){
  int n;
  long long i=1,temp,t; 
  cin>>n;
  int rem=0,cnt=0;
  //string temp1;
  while(true){
    temp=n*i;
    t=temp;
    // temp1=to_string(temp);
    cnt=0;
    while(temp!=0){
      rem=temp%10;
      if(rem!=0 && rem!=1) break;
      temp/=10; 
      if(temp==0) cnt=1;
    }
    if(cnt==1){
        //temp1=to_string(t);
        cout<<to_string(t);
        break;
    }
    i++;
  }
  return 0;
}
*/
#include<iostream>
using namespace std;
int l=0;
int b=0;
int main(){
    int a;
    cin>>a;
    int i=0;
    while(true){
        long long int k=a*i;
        string str = to_string(k);
        long long int  y=str.length();
         int u=0;
        for(int j=0;j<y;j++){
            if(str[j]=='0'){
                l=1;
                u++;
            }else if(str[j]=='1'){
                u++;
                b=1;
            }
        }
        if(u==y){
            if(str[0]!='0'){
                if(l==1 && b==1){
                    cout<<str;
                    break;
                }
            }
        }
        i++;
    }
}