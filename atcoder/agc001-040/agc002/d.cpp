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

UF<101010> uf;

int N,M,Q;
int A[101010],B[101010];
int X[101010],Y[101010],Z[101010];
int R[101010];
vector<int> cand[20][301010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&M);
	FOR(i,M) scanf("%d%d",&A[i],&B[i]);
	
	scanf("%d",&Q);
	FOR(i,Q) scanf("%d%d%d",&X[i],&Y[i],&Z[i]);
	FOR(i,Q) cand[18][M-1].push_back(i);
	
	for(j=17;j>=0;j--) {
		uf.reinit();
		
		FOR(i,M) {
			x=i+(1<<j);
			uf(A[i],B[i]);
			FORR(r,cand[j+1][x]) {
				if(uf.count(X[r])+((uf[X[r]]==uf[Y[r]])?0:uf.count(Y[r]))>=Z[r]) cand[j][i].push_back(r);
				else cand[j][x].push_back(r);
			}
			if(i<1<<j) {
				FORR(r,cand[j+1][i]) cand[j][i].push_back(r);
			}
		}
	}
	FOR(i,M) FORR(r,cand[0][i]) R[r]=i+1;
	FOR(i,Q) _P("%d\n",R[i]);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
