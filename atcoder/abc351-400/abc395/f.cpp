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
ll U[202020],D[202020],X;

int hoge(ll v) {
	ll L=0,R=1LL<<60;
	int i;
	FOR(i,N) {
		L-=X;
		R+=X;
		ll del=U[i]+D[i]-v;
		ll TL=U[i]-min(U[i],del);
		ll TR=U[i]-(del-min(D[i],del));
		L=max(L,TL);
		R=min(R,TR);
		if(L>R) return 0;
	}
	return 1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X;
	ll mi=1LL<<60;
	FOR(i,N) {
		cin>>U[i]>>D[i];
		mi=min(mi,U[i]+D[i]);
	}
	ll ret=0;
	for(i=30;i>=0;i--) if(ret+(1LL<<i)<=mi&&hoge(ret+(1LL<<i))) ret+=1LL<<i;
	ll sum=0;
	FOR(i,N) sum+=U[i]+D[i]-ret;
	cout<<sum<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
