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

const int prime_max = 5000000;
int NP,prime[500000],divp[prime_max];

void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		prime[NP++]=i;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) divp[j]=i;
	}
}

int N,M;
vector<int> E[303030];
vector<ll> V[303030];
ll mo[3]={1000000007,1000000009,1000000021};
int sl[3];
int EU[303030],EV[303030];
map<vector<ll>,int> C;
set<pair<int,int>> S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cprime();
	srand(clock());
	sl[0]=rand()%NP;
	sl[1]=rand()%NP;
	sl[2]=rand()%NP;
	
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		x--,y--;
		if(x>y) swap(x,y);
		if(S.count({x,y})) {
			M--;
			i--;
			continue;
		}
		S.insert({x,y});
		E[x].push_back(y);
		E[y].push_back(x);
		EU[i]=x;
		EV[i]=y;
	}
	ll ret=0;
	FOR(i,N) {
		V[i]={1,1,1};
		FORR(r,E[i]) FOR(x,3) V[i][x] = V[i][x]*prime[(r+sl[x])%NP]%mo[x];
		ret += C[V[i]];
		C[V[i]]++;
	}
	FOR(i,M) {
		auto V2=V[EU[i]];
		auto V3=V[EV[i]];
		FOR(x,3) V2[x] = V2[x]*prime[(EU[i]+sl[x])%NP]%mo[x];
		FOR(x,3) V3[x] = V3[x]*prime[(EV[i]+sl[x])%NP]%mo[x];
		if(V2==V3) ret++;
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
