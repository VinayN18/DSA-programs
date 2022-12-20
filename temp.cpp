#include <iostream>
#include <bits/stdc++.h>
#include<string>
using namespace std;
void is_palindrome(string s,int max[]){
    int n=s.length();
    if (n==0){return;}
    else{
        string str=s;
        reverse(s.begin(), s.end());
        if (str==s && max[0]<n){max[0]=n;}
    }
    return;
}
void palindrome(char vec[],int n ,int ind,string s,int max[]){
    if (ind>n-1){return;}
    is_palindrome(s,max);
    palindrome(vec,n,ind+1,s,max);
    s+=vec[ind];
    is_palindrome(s,max);
    palindrome (vec,n,ind+1,s,max);
    return ;
    
}
int main(){
    string s;cin>>s;
    int n=s.length();
    char arr[n];
    for (int i=0;i<n;i++){
        arr[i]=s[i];
    }int max[1]={0};
    palindrome(arr,n,0,"",max);
    cout<<max[0];
}