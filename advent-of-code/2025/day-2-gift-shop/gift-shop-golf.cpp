#include<bits/stdc++.h>
using namespace std;using ll=long long;int main(){
	ll a=0,b=0,x,y;char c;vector<ll>v;string s;
	if(!(cin>>s))return 0;
	replace(s.begin(),s.end(),'-',',');
	stringstream ss(s);
	while(ss>>x){v.push_back(x);if(ss.peek()==',')ss.get();}
	for(int i=0;i+1<v.size();i+=2){
		x=v[i];y=v[i+1];
		for(;x<=y;x++){
			string t=to_string(x);
			int n=t.size();
			string d=t+t;
			int A=0;
			for(int k=1;k<n;k++)if(d.find(t,k)<n){A=n/k;break;}
			if(A&&A%2==0)a+=x;else if(A&&A%2)b+=x;
		}
	}
	cout<<a<<' '<<b;
}
