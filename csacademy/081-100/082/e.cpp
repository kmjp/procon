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

int T,N,K;
int F[2020],MF[2020];
int C[2020][2020];
int CS[2020][2020];
int TC[2020][2020];
int ok[2020][2020];

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

vector<int> cand;
set<pair<int,pair<int,int>>> S;

void merge(int a,int b) {
	FORR(c,cand) {
		if(ok[a][c]) {
			int x=min(a,c);
			int y=max(a,c);
			S.erase({TC[x][y],{x,y}});
		}
		if(ok[b][c]) {
			int x=min(b,c);
			int y=max(b,c);
			S.erase({TC[x][y],{x,y}});
		}
	}
	if(a>b) swap(a,b);
	S.erase({TC[a][b],{a,b}});
	MF[a]=min(MF[a],MF[b]);
	
	cand.erase(find(ALL(cand),b));
	FORR(c,cand) if(c!=a) {
		if(ok[b][c] || ok[c][b]) {
			ok[a][c]=ok[c][a]=1;
			CS[a][c]=CS[c][a]=CS[b][c];
		}
		if(ok[a][c]) {
			int x=min(a,c);
			int y=max(a,c);
			ll mi=1LL<<60;
			TC[x][y]=-max(MF[x],MF[y])+CS[x][y];
			S.insert({TC[x][y],{x,y}});
		}
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cand.clear();
		S.clear();
		vector<vector<int>> V;
		
		cin>>N>>K;
		
		ll tot=0;
		FOR(i,N) {
			cin>>F[i];
			MF[i]=F[i];
			cand.push_back(i);
			tot+=F[i];
		}
		FOR(y,N) FOR(x,N) {
			ok[y][x]=0;
			cin>>C[y][x];
			CS[y][x]=C[y][x];
			if(x<y) V.push_back({C[y][x],x,y});
		}
		sort(ALL(V));
		UF<2020> uf;
		FORR(v,V) {
			if(uf[v[1]]!=uf[v[2]]) {
				uf(v[1],v[2]);
				ok[v[1]][v[2]]=ok[v[2]][v[1]]=1;
			}
		}
		FOR(y,N) FOR(x,N) if(x<y && ok[x][y]) {
			TC[x][y]=-max(MF[x],MF[y])+C[y][x];
			S.insert({TC[x][y],{x,y}});
		}
		
		ll ret=1LL<<60;
		while(cand.size()>1) {
			if(cand.size()<=K) ret=min(ret,tot);
			
			auto a=*S.begin();
			tot+=a.first;
			merge(a.second.first,a.second.second);
			
		}
		ret=min(ret,tot);
		cout<<ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
