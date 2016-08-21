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

int N;
ll S[101010];

const int prime_max = 100000;
int NP,prime[100000],divp[prime_max];
map<int,int> M;

map<ll,int> PV;
set<ll> did;

void cprime() {
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime[NP++]=i;
		for(ll j=1LL*i*i;j>i&&j<prime_max;j+=i) divp[j]=i;
	}
}


ll hoge(ll n) {
	int i;
	FOR(i,NP) {
		ll a=prime[i];
		if(a>1000) break;
		
		while(n % (a*a*a)==0) n /= a*a*a;
	}
	return n;
}

ll rev(ll n) {
	ll nn=n*n;
	int i;
	FOR(i,NP) {
		ll a=prime[i];
		if(a>1000) break;
		
		while(nn % (a*a*a)==0) nn /= a*a*a;
	}
	return nn;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	cprime();
	int cube=0;
	FOR(i,N) {
		cin>>S[i];
		ll v=hoge(S[i]);
		if(v==1) cube++;
		else PV[v]++;
	}
	
	int ret=N;
	if(cube) ret -= (cube-1);
	FORR(r,PV) {
		if(did.count(r.first)) continue;
		ll rr=rev(r.first);
		
		if(PV.count(rr)) ret -= min(r.second,PV[rr]);
		did.insert(rr);
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
