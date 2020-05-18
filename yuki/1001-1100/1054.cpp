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

int N,Q;
int T[505050],A[505050],B[505050];
int cur[505050];

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
UF<1500000> uf;
vector<int> E[1010101];
int nex;
int id;
int L[1010101],R[1010101];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,21> bt;

void dfs(int cur) {
	if(L[cur]!=-1) return;
	L[cur]=id++;
	FORR(e,E[cur]) dfs(e);
	R[cur]=id;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) cur[i]=i;
	nex=N;
	FOR(i,Q) {
		cin>>T[i]>>A[i]>>B[i];
		A[i]--;
		if(T[i]==1) {
			B[i]--;
			if(uf[A[i]]!=uf[B[i]]) {
				E[nex].push_back(cur[uf[A[i]]]);
				E[nex].push_back(cur[uf[B[i]]]);
				cur[uf[A[i]]]=cur[uf[B[i]]]=nex;
				uf(A[i],B[i]);
				nex++;
			}
		}
	}
	MINUS(L);
	uf.reinit();
	for(i=nex-1;i>=0;i--) dfs(i);
	FOR(i,N) cur[i]=i;
	nex=N;
	FOR(i,Q) {
		if(T[i]==1) {
			if(uf[A[i]]!=uf[B[i]]) {
				cur[uf[A[i]]]=cur[uf[B[i]]]=nex;
				uf(A[i],B[i]);
				nex++;
			}
		}
		else if(T[i]==2) {
			x=cur[uf[A[i]]];
			bt.add(L[x],B[i]);
			bt.add(R[x],-B[i]);
		}
		else {
			cout<<bt(L[A[i]])<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
