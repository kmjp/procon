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

int T;
int N;
ll L,R;
int A[402020];
int P[402020];
int E[402020];
int O[402020];

ll val(ll m) {
	if(m<=2*N) return A[m];
	if((m/2)%2) return P[N];
	return P[N]^val(m/2);
}

pair<ll,ll> hoge(ll v) {
	if(v<=2*N) return {E[v],O[v]};
	if(v%4!=1) {
		auto p=hoge(v-1);
		if(v%2) p.second+=val(v);
		else p.first+=val(v);
		return p;
	}
	auto p=hoge(v/2);
	ll e=p.first-E[N];
	
	ll both=P[N]?v/2-N+1-e:e;
	return {E[2*N-1]+both,O[2*N-1]+both};
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>L>>R;
		for(i=1;i<=N;i++) {
			cin>>A[i];
			P[i]=P[i-1]^A[i];
			E[i]=E[i-1]+((i%2)?0:A[i]);
			O[i]=O[i-1]+((i%2)?A[i]:0);
		}
		for(i=N+1;i<=2*N+2;i++) {
			A[i]=P[i/2];
			P[i]=P[i-1]^A[i];
			E[i]=E[i-1]+((i%2)?0:A[i]);
			O[i]=O[i-1]+((i%2)?A[i]:0);
		}
		if(N%2==0) N++;
		
		auto r=hoge(R);
		auto l=hoge(L-1);
		cout<<(r.first+r.second-l.first-l.second)<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
