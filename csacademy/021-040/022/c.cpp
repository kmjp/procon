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

int H,W;
int A[1010][1010];
UF<1<<20> uf;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) FOR(x,W) cin>>A[y][x];
	FOR(y,H) {
		FOR(x,W) {
			if(x<W-1 && A[y][x] && A[y][x+1]) uf(y*1000+x,y*1000+x+1);
			if(y<H-1 && A[y][x] && A[y+1][x]) uf(y*1000+x,(y+1)*1000+x);
		}
	}
	
	int ma=0;
	FOR(y,H) FOR(x,W) if(A[y][x]==0) {
		set<int> S;
		if(y && A[y-1][x]) S.insert(uf[(y-1)*1000+x]);
		if(x && A[y][x-1]) S.insert(uf[y*1000+x-1]);
		if(y<H-1 && A[y+1][x]) S.insert(uf[(y+1)*1000+x]);
		if(x<W-1 && A[y][x+1]) S.insert(uf[y*1000+x+1]);
		
		i = 1;
		FORR(s,S) i += uf.count(s);
		ma=max(ma,i);
	}
	cout<<ma<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
