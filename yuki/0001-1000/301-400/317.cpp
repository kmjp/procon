#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;

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
UF<500000> uf;
map<int,int> E;
int mi[101010],pre[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		uf(x-1,y-1);
	}
	FOR(i,N) if(uf[i]==i) E[uf.cnt[i]]++;
	FOR(i,N+1) mi[i]=N+100;
	mi[0]=0;
	
	FORR(r,E) {
		if(r.first>=100 || r.second<=10) {
			FOR(j,r.second) {
				for(i=N-r.first+1;i>=0;i--) mi[i+r.first]=min(mi[i+r.first],mi[i]+1);
			}
		}
		else {
			set<pair<int,int>> S[100];
			FOR(i,100) S[i].clear();
			
			S[0].insert({0,0});
			for(i=j=1;i<=N;i++,j++) {
				pre[i]=mi[i];
				if(j>=r.first) j=0;
				auto it=S[j].begin();
				
				if(it!=S[j].end()) {
					x=it->first+(it->second-j)/r.first+(i-it->second)/r.first;
					mi[i]=min(mi[i],x);
				}
				if(pre[i]<N) S[j].insert({pre[i]-(i-j)/r.first,i});
				x=i-r.first*r.second;
				if(x>=0) S[j].erase({pre[x]-(x-j)/r.first,x});
			}
			
		}
	}
	
	for(i=1;i<=N;i++) {
		if(mi[i]>N) mi[i]=0;
		_P("%d\n",mi[i]-1);
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
