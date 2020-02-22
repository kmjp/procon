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

int N,M,K;
vector<int> E[101];
int G[101];
ll mo=1000000007;
int NE[101];
ll pk[110];

// ìÒè\í∏ì_òAåãê¨ï™ï™â
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
UF<303030> uf;

class SCC_ART {
public:
	static const int MV = 210000;
	int NV,time;
	vector<vector<int> > E;
	vector<int> low,num,isart,gr;
	vector<pair<int,int>> ES;
	vector<vector<int> > SC; // out
	vector<int> ART; // out
	vector<set<pair<int,int>> > BE; // out, Edgeset
	UF<MV> uf;
	
	void init(int NV=MV) { this->NV=NV; E.clear(); E.resize(NV);}
	void add_edge(int x,int y) { E[x].push_back(y); E[y].push_back(x);}
	void dfs(int cur,int pre) {
		low[cur]=num[cur]=++time;
		FORR(e,E[cur]) {
			if(e!=pre && num[e]<num[cur]) ES.push_back({min(e,cur),max(e,cur)});
			if(num[e]) low[cur]=min(low[cur],num[e]);
			else {
				dfs(e,cur);
				low[cur]=min(low[cur],low[e]);
				if((num[cur]==1&&num[e]>2) || (num[cur]!=1&&low[e]>=num[cur])) isart[cur]=1;
				if(low[e]>=num[cur]) {
					BE.push_back(set<pair<int,int>>());
					while(1) {
						pair<int,int> te=ES.back();
						ES.pop_back();
						BE.back().insert(te);
						if(min(cur,e)==te.first && max(cur,e)==te.second) break;
					}
					
				}
			}
		}
		if(isart[cur]) ART.push_back(cur);
	}
	void scc() {
		ART.clear();uf.reinit();SC.clear();BE.clear();ES.clear();
		low=num=isart=gr=vector<int>(NV,0);
		for(int i=0;i<NV;i++) if(!num[i]) time=0,dfs(i,-1);
		sort(ART.begin(),ART.end());
		for(int i=0;i<NV;i++) FORR(r,E[i]) if(isart[i]==0 && isart[r]==0) uf(i,r);
		for(int i=0;i<NV;i++) if(uf[i]==i) gr[i]=SC.size(), SC.push_back(vector<int>());
		for(int i=0;i<NV;i++) gr[i]=gr[uf[i]], SC[gr[uf[i]]].push_back(i);
	}
};


SCC_ART scc;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}
ll combi(ll N_, ll C_) {
	const int NUM_=400001;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}
ll hcomb(int P_,int Q_) { return (P_==0&&Q_==0)?1:combi(P_+Q_-1,Q_);}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	scc.init(N);
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
		scc.add_edge(x-1,y-1);
	}
	scc.scc();
	
	pk[0]=1;
	FOR(i,100) pk[i+1]=pk[i]*K%mo;
	
	ll ret=1;
	FORR(es,scc.BE) {
		set<int> S;
		
		FORR(e,es) S.insert(e.first),S.insert(e.second);
		
		if(es.size()==S.size()) {
			// simple cycle
			ll t=0;
			for(j=1;j<=S.size();j++) t+=pk[__gcd(j,(int)S.size())];
			ret = ret * (t%mo)%mo*modpow(S.size())%mo;
		}
		else {
			ret = ret*hcomb(K,es.size())%mo;
		}
	}
	cout<<ret<<endl;
	
	return;
	/*
	
	
	FOR(i,N) {
		FORR(r,E[i]) if(i<r) {
			if(G[i]!=G[r]) ret=ret*K%mo;
			else NE[G[i]]++;
		}
	}
	
	FOR(i,scc.SC.size()) if(scc.SC[i].size()>1) {
		if(scc.SC[i].size()==NE[i]) {
			// simple cycle
			ll t=0;
			for(j=1;j<=NE[i];j++) t+=pk[__gcd(j,NE[i])];
			ret = ret * (t%mo)%mo*modpow(NE[i])%mo;
		}
		else {
			// complex cycle
			ret = ret*hcomb(NE[i],K)%mo;
		}
	}
	for(i=0;i<=40;i++) _P("%d %lld\n",i,48*48*hcomb(K,i)%mo);
	
	
	cout<<ret<<endl;
	*/
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
