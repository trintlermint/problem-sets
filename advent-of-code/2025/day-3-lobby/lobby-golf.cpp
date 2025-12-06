/*
//pt1
#include<bits/stdc++.h>
using namespace std;int main(){int r=0;string s;while(getline(cin,s)){if(s.size()>=2){auto i=max_element(s.begin(),s.end()-1);r+=stoi(string{*i,*max_element(i+1,s.end())});}}cout<<r<<'\n';}
*/
/*
p1+2
#include<bits/stdc++.h>
using namespace std;using ll=long long;int main(){ll a=0,b=0;string s;while(cin>>s){auto i=max_element(s.begin(),s.end()-1);a+=stoll(string{*i,*max_element(i+1,s.end())});int k=s.size()-12;string t;for(char c:s){while(k&&t.size()&&t.back()<c)k--,t.pop_back();t+=c;}t.resize(12);b+=stoll(t);}cout<<a<<' '<<b<<'\n';}
*/
/*
#include<bits/stdc++.h>
using namespace std;int main(){long a=0,b=0;string s,t;for(;cin>>s;b+=stoll(t)){auto i=max_element(s.begin(),s.end()-1);a+=*i*10+*max_element(i+1,s.end())-528;int k=s.size()-12;t="";for(char c:s){while(k&&t.size()&&t.back()<c)k--,t.pop_back();t+=c;}t.resize(12);}cout<<a<<' '<<b;}
*/
// peak
#include<bits/stdc++.h>
using namespace std;long a,b,k;int main(){for(string s,t;cin>>s;b+=stoll(t)){auto i=max_element(s.begin(),s.end()-1);a+=*i*10+*max_element(i+1,s.end())-528;k=s.size()-12;t="";for(char c:s){for(;k&&t.size()&&t.back()<c;k--)t.pop_back();t+=c;}t.resize(12);}cout<<a<<' '<<b;}
