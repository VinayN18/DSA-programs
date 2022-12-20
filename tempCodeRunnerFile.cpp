#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
int memo[10000][10000];
 
int lps(string& s1, string& s2, int n1, int n2)
{
    if(n1==0||n2==0)return 0;
    if(memo[n1][n2]!=-1)return memo[n1][n2];
    if(s1[n1-1]==s2[n2-1])return memo[n1][n2] = 1 + lps(s1, s2, n1 - 1, n2 - 1);
    else return memo[n1][n2] = max(lps(s1, s2, n1 - 1, n2),lps(s1, s2, n1, n2 - 1));
}
 
int main()
{
    string s; cin >> s ;
    int l = s.size();
    memo[l][l];
    memset(memo, -1, sizeof(memo));
    string s2 = s;
    reverse(s2.begin(), s2.end());
    cout << lps(s2, s, l, l) << endl;
    return 0;
}