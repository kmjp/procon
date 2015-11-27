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

template<int um> class UF {
	public:
	vector<int> par,rank;
	UF() {rank=vector<int>(um,0); for(int i=0;i<um;i++) par.push_back(i);}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};

UF<500000> uf;

int H,W,Q;
int A[201*201];
vector<int> S[201*201];
int id(int y,int x){ return y*W+x;}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) FOR(x,W) {
		cin>>A[id(y,x)];
	}
	FOR(y,H) FOR(x,W) {
		if(y) {
			if(A[id(y,x)]==A[id(y-1,x)]) uf(id(y,x),id(y-1,x));
			else S[id(y,x)].push_back(id(y-1,x));
		}
		if(y<H-1) {
			if(A[id(y,x)]==A[id(y+1,x)]) uf(id(y,x),id(y+1,x));
			else S[id(y,x)].push_back(id(y+1,x));
		}
		if(x) {
			if(A[id(y,x)]==A[id(y,x-1)]) uf(id(y,x),id(y,x-1));
			else S[id(y,x)].push_back(id(y,x-1));
		}
		if(x<W-1) {
			if(A[id(y,x)]==A[id(y,x+1)]) uf(id(y,x),id(y,x+1));
			else S[id(y,x)].push_back(id(y,x+1));
		}
	}
	
	FOR(x,H*W) if(uf[x]!=x) FORR(r,S[x]) S[uf[x]].push_back(r);
	FOR(x,H*W) if(uf[x]==x) {
		sort(ALL(S[x]));
		S[x].erase(unique(ALL(S[x])),S[x].end());
	}
	cin>>Q;
	while(Q--) {
		cin>>y>>x>>k;
		x=uf[id(y-1,x-1)];
		if(A[x]==k) continue;
		
		vector<int> NEW;
		FORR(r,S[x]) if(uf[x]!=uf[r]) {
			FORR(r2,S[uf[r]]) if(uf[r2]!=uf[x]) NEW.push_back(uf[r2]);
			uf(x,r);
		}
		sort(ALL(NEW));
		NEW.erase(unique(ALL(NEW)),NEW.end());
		
		S[uf[x]]=NEW;
		A[uf[x]]=k;
	}
	
	FOR(y,H) FOR(x,W) _P("%d%c",A[uf[id(y,x)]],(x==W-1)?'\n':' ');
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
