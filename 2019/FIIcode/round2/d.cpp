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
vector<int> C[101010];

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
UF<201010> uf,uf2;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	set<vector<int>> S;
	FOR(i,M) {
		cin>>x>>y>>r;
		C[x-1].push_back(r);
		C[y-1].push_back(r);
		S.insert({r,x-1,y-1});
	}
	
	int mi=1<<30;
	FOR(i,N) if(C[i].size()>=2) {
		sort(ALL(C[i]));
		mi=min(mi,C[i][0]+C[i][1]);
	}
	if(mi==1<<30) return _P("-1\n");
	
	FORR(s,S) {
		if(uf[s[1]*2]==uf[s[2]*2]) {
			cout<<min(mi,s[0])<<endl;
			return;
		}
		uf(s[1]*2,s[2]*2+1);
		uf(s[2]*2,s[1]*2+1);
	}
	
	
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
