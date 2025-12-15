#include<bits/stdc++.h>
using namespace std;int main(){string l;int p=50,a=0,b=0;while(getline(cin,l)){int n=stoi(l.substr(1));for(int i=0;i<n;i++){p=(p+(l[0]=='L'?-1:1)+100)%100;b+=p==0;}a+=p==0;}cout<<a<<"\n"<<b;}
