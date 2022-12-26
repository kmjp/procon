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
int C[101010];

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
int prec[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int a=1,b=1;
	cin>>N>>M>>K;
	MINUS(prec);
	FOR(i,N) {
		cin>>C[i];
		if(C[i]) {
			if(prec[C[i]]>=0) uf(prec[C[i]],i);
			prec[C[i]]=i;
		}
	}
	
	
	priority_queue<pair<int,pair<int,int>>> PQ;
	FOR(i,M) {
		cin>>x>>y>>j;
		PQ.push({-j,{x-1,y-1}});
	}
	
	ll ret=0;
	K--;
	while(PQ.size()&&K) {
		auto e=PQ.top();
		PQ.pop();
		if(uf[e.second.first]!=uf[e.second.second]) {
			K--;
			uf(e.second.first,e.second.second);
			ret+=-e.first;
		}
	}
	if(K) cout<<-1<<endl;
	else cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
