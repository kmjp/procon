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
int U[50505],V[50505],C[50505],W[50505];
vector<pair<int,int>> E;
vector<int> F;
int need[50505];
int Q;
ll A;

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
UF<50505> uf1,uf2;
vector<int> cand;
vector<ll> S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	
	FOR(i,M) {
		cin>>U[i]>>V[i]>>C[i];
		U[i]--;
		V[i]--;
		if(C[i]==0) {
			cin>>W[i];
			E.push_back({W[i],i});
		}
		else {
			cin>>s;
			F.push_back(i);
		}
	}
	
	sort(ALL(E));
	FORR(f,F) uf2(U[f],V[f]);
	
	ll sum=0;
	FORR(e,E) {
		if(uf1[U[e.second]]!=uf1[V[e.second]]) {
			need[e.second]|=1;
			uf1(U[e.second],V[e.second]);
		}
		if(uf2[U[e.second]]!=uf2[V[e.second]]) {
			need[e.second]|=2;
			uf2(U[e.second],V[e.second]);
			sum+=W[e.second];
		}
	}
	int nx=0;
	FORR(f,F) if(uf1[U[f]]!=uf1[V[f]]) {
		nx++;
		uf1(U[f],V[f]);
	}
	
	FOR(i,M) if(need[i]==1) cand.push_back(W[i]);
	sort(ALL(cand));
	S.push_back(0);
	FORR(c,cand) S.push_back(S.back()+c);
	
	cin>>Q;
	while(Q--) {
		cin>>A;
		x=lower_bound(ALL(cand),A)-cand.begin();
		ll ret=sum+nx*A+S[x]+(cand.size()-x)*A;
		cout<<ret<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
