#include <bits/stdc++.h>
using namespace std;
int main(){int p1=50,p2=50,r1=0,r2=0;string i;while(cin>>i){char c=i[0];int r=stoi(i.substr(1)),p=(c=='R'?r:-r);if((p1=((p1+p)+100)%100)==0)++r1;int q=p2+p;if(q<=0&&p2)++r2;p2=((q%100)+100)%100;r2+=abs(q)/100;}cout<<"p1: "<<r1<<" p2: "<<r2<<'\n';}
