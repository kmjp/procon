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

set<int> NG[202020];

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
vector<pair<int,int> >  V;

int N,M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		x--,y--;
		NG[x].insert(y);
		NG[y].insert(x);
	}
	if(N<=1000) {
		FOR(x,N) FOR(y,N) if(uf[x]!=uf[y] && NG[x].count(y)==0) {
			uf(x,y);
			V.push_back({x,y});
		}
		
		if(uf.count(0)!=N) return _P("No\n");
		_P("Yes\n");
		FORR(r,V) _P("%d %d\n",r.first+1,r.second+1);
	}
	else {
		int st=0;
		FOR(x,N) if(NG[x].size()<NG[st].size()) st=x;
		set<int> L;
		FOR(x,N) if(x!=st) L.insert(x);
		queue<int> Q;
		Q.push(st);
		while(Q.size()) {
			int cur=Q.front();
			Q.pop();
			
			vector<int> R;
			FORR(r,L) if(NG[cur].count(r)==0) R.push_back(r);
			FORR(r,R) {
				L.erase(r);
				V.push_back({cur,r});
				Q.push(r);
			}
		}
		if(L.size()) return _P("No\n");
		_P("Yes\n");
		FORR(r,V) _P("%d %d\n",r.first+1,r.second+1);
		
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
