#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin>>s;
	int n=s.length();
	vector<string>num;
	vector<string>S;
	int r=0;
	int l=0;
	string str="";
	string NUM="";
	for(int i=0;i<n;i++){
		if(s[i]==']')
		l=1;
		if(s[i]=='[')
		r=1;
		if(r==0)
		NUM+=s[i];
	   if(l==0&&r!=0&&s[i]!='[')
	   str+=s[i];
	   if(l!=0&&r!=0){
	   	l=0;r=0;
	   	S.push_back(str);
	   	str="";
	   	num.push_back(NUM);
	   	NUM="";
	   }
	}
	vector<int>a;
	for(int i=0;i<num.size();i++){
		int p=stoi(num[i]);
		a.push_back(p);
	}
	for(int i=0;i<a.size();i++){
		for(int j=0;j<a[i];j++){
			cout<<S[i];
		}
	}
	return 0;
}