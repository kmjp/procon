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

int N,M;
int K,Q;
vector<pair<int,int>> E[101010];
ll D[101010];
int S[101010],T[101010],ret[101010];
vector<int> vcand[101010],ev[101010];

template<int um> class UF {
	public:
	vector<int> par,rank,cnt;
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit() {int i; FOR(i,um) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
UF<101010> uf;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K>>Q;
	FOR(i,M) {
		cin>>x>>y>>r;
		E[x-1].push_back({y-1,r});
		E[y-1].push_back({x-1,r});
	}
	FOR(i,N) D[i]=1LL<<60;
	priority_queue<pair<ll,int>> PQ;
	FOR(i,K) {
		cin>>x;
		x--;
		D[x]=0;
		PQ.push({0,x});
	}
	
	vector<ll> dist;
	while(PQ.size()) {
		ll co=-PQ.top().first;
		int cur=PQ.top().second;
		PQ.pop();
		if(co!=D[cur]) continue;
		dist.push_back(co);
		FORR(e,E[cur]) if(D[e.first]>co+e.second) {
			D[e.first]=co+e.second;
			PQ.push({-D[e.first],e.first});
		}
	}
	sort(ALL(dist));
	dist.erase(unique(ALL(dist)),dist.end());
	FOR(i,N) {
		D[i]=lower_bound(ALL(dist),D[i])-dist.begin();
		vcand[D[i]].push_back(i);
	}
	FOR(i,Q) {
		cin>>S[i]>>T[i];
		S[i]--;
		T[i]--;
	}
	for(i=20;i>=0;i--) {
		FOR(j,Q) if((ret[j]+(1<<i))<dist.size()) ev[ret[j]+(1<<i)].push_back(j);
		uf.reinit();
		for(j=dist.size()-1;j>=0;j--) {
			FORR(v,vcand[j]) FORR(e,E[v]) if(D[e.first]>=j) uf(v,e.first);
			FORR(q,ev[j]) if(uf[S[q]]==uf[T[q]] && D[S[q]]>=j && D[T[q]]>=j) ret[q]+=1<<i;
			ev[j].clear();
		}
	}
	FOR(i,Q) cout<<dist[ret[i]]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
