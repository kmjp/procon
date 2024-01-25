#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N;
ll X[202020],Y[202020];

int ok(ll v, vector<pair<ll,ll>> V) {
	ll Xma=-1LL<<60;
	ll Xmi=1LL<<60;
	ll Yma=-1LL<<60;
	ll Ymi=1LL<<60;
	int i;
	FOR(i,N) {
		int n=0;
		FORR2(a,b,V) if(a<=X[i]&&X[i]<=a+v&&b<=Y[i]&&Y[i]<=b+v) n=1;
		if(n==0) {
			Xmi=min(Xmi,X[i]);
			Xma=max(Xma,X[i]-v);
			Ymi=min(Ymi,Y[i]);
			Yma=max(Yma,Y[i]-v);
		}
	}
	if(Xmi==1LL<<60) return 1;
	if(V.size()==3) return 0;
	if(V.size()==0) {
		V.push_back({Xmi,Ymi});
		if(ok(v,V)) return 1;
		V.pop_back();
		V.push_back({Xmi,Yma});
		if(ok(v,V)) return 1;
		V.pop_back();
		V.push_back({Xma,Ymi});
		if(ok(v,V)) return 1;
		V.pop_back();
		V.push_back({Xma,Yma});
		if(ok(v,V)) return 1;
		V.pop_back();
	}
	else {
		V.push_back({Xmi,Ymi});
		V.push_back({Xma,Yma});
		if(ok(v,V)) return 1;
		V.pop_back();
		V.pop_back();
		V.push_back({Xma,Ymi});
		V.push_back({Xmi,Yma});
		if(ok(v,V)) return 1;
		V.pop_back();
		V.pop_back();
	}
	return 0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x>>y;
		X[i]=x+y;
		Y[i]=x-y;
	}
	ll ret=(1LL<<31)-1;
	for(i=30;i>=0;i--) if(ok(ret-(1LL<<i),{})) ret-=1LL<<i;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
