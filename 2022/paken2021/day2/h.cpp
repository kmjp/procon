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

int M;
ll P,S;

ll pat(ll P,ll N) {
	ll ret=0;
	while(N) {
		ret+=N/P;
		N/=P;
	}
	return ret;
}

pair<ll,ll> hoge(ll P,ll S) {
	ll a=1LL<<60;
	if(pat(P,a)<S) return {1LL,-1LL};
	int i;
	for(i=59;i>=0;i--) if(pat(P,a-(1LL<<i))>=S) a-=1LL<<i;
	ll b=1LL<<60;
	if(pat(P,b)>=S+1) {
		b=a;
		for(i=59;i>=0;i--) if(pat(P,b+(1LL<<i))==S) b+=1LL<<i;
	}
	return {a,b};
	
	
	
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	ll L=1,R=1000000000000000000LL;
	cin>>M;
	FOR(i,M) {
		cin>>P>>S;
		auto p=hoge(P,S);
		L=max(L,p.first);
		R=min(R,p.second);
	}
	
	if(L>R) {
		cout<<-1<<endl;
	}
	else {
		cout<<L<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
