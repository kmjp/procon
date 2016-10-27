#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

const int prime_max = 1000005;
int NP,prime[100000],divp[prime_max];

void cprime() {
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		divp[i]=i;
		for(ll j=1LL*i*i;j>i&&j<prime_max;j+=i) divp[j]=i;
	}
}

int T;
int N,M;
int A[505050],B[505050];
int C[1010101];

ll getrev(ll v) {
	ll r=1;
	while(v>1) {
		if(r%divp[v]==0) r/=divp[v];
		else r*=divp[v]*divp[v];
		v /= divp[v];
	}
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cprime();
	
	for(i=1;i<=1000000;i++) C[i]=i;
	for(i=2;i<=100;i++) {
		for(x=i*i*i;x<=1000000;x+=i*i*i) C[x]=x/(i*i*i);
	}
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		map<ll,ll> AM,BM;
		FOR(i,N) cin>>x, AM[C[x]]++;
		FOR(i,M) cin>>x, BM[C[x]]++;
		
		ll ret=-1;
		if(AM.count(1)&&BM.count(1)) ret=AM[1]*AM[1]+BM[1]*BM[1];
		FORR(r,AM) if(r.first>1) {
			ll a=r.first;
			ll b=getrev(a);
			if(BM.count(b)) ret=max(ret,AM[a]*AM[a]+BM[b]*BM[b]);
		}
		
		cout<<ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
