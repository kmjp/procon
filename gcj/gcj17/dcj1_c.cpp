#include <message.h>
#include <cassert>
#include <cstdio>
#include "weird_editor.h"
#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int TN,MY;
ll N;

ll p10[1010101];
ll mo=1000000007;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void slow() {
	int i,j,k,l,r,x,y; string s;
	if(MY!=0) return;
	
	p10[0]=1;
	FOR(i,1010000) p10[i+1]=p10[i]*10%mo;
	
	vector<int> V;
	FOR(i,N) {
		y=GetDigit(i);
		while(V.size() && V.back()<y) V.pop_back();
		V.push_back(y);
	}
	ll ret=0;
	FOR(i,V.size()) (ret+=V[i]*p10[N-1-i])%=mo;
	
	cout<<ret<<endl;
}
void fast() {
	int i,j,k,l,r,x,y; string s;
	int L=N*MY/TN;
	int R=N*(MY+1)/TN;
	
	vector<pair<int,int>> V;
	for(i=L;i<R;i++) {
		y=GetDigit(i);
		while(V.size() && V.back().first<y) V.pop_back();
		if(V.size() && V.back().first==y) V.back().second++;
		else V.push_back({y,1});
	}
	
	PutInt(0,(int)V.size());
	FORR(e,V) PutInt(0,e.first), PutInt(0,e.second);
	Send(0);
	
	if(MY!=0) return;
	
	V.clear();
	FOR(i,TN) {
		Receive(i);
		x=GetInt(i);
		while(x--) {
			int a=GetInt(i);
			int b=GetInt(i);
			while(V.size() && V.back().first<a) V.pop_back();
			if(V.size() && V.back().first==a) V.back().second+=b;
			else V.push_back({a,b});
		}
	}
	
	ll ret=0;
	int d=N;
	FORR(e,V) {
		d-=e.second;
		ll a=modpow(10,d)*e.first%mo;
		ll b=(modpow(10,e.second)+(mo-1))*modpow(9)%mo;
		(ret += a*b)%=mo;
	}
	
	cout<<ret<<endl;
	
	
}


void solve(){
	
	N=GetNumberLength();
	
	if(N<1000) slow();
	else fast();
	
}


int main(int argc,char** argv){
	
	TN=NumberOfNodes();
	MY=MyNodeId();
	solve();
	return 0;
	
}


