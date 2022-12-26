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

int N,M,Q;
int A[101010],B[101010];
int X[101010],Y[101010];
int L[101010],R[101010];
vector<int> cand[101010];

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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>A[i]>>B[i];
		A[i]--;
		B[i]--;
	}
	cin>>Q;
	FOR(i,Q) {
		cin>>X[i]>>Y[i];
		X[i]--;
		Y[i]--;
		L[i]=1;
		R[i]=M+1;
	}
	
	FOR(i,20) {
		FOR(x,Q) cand[(L[x]+R[x])/2].push_back(x);
		FOR(x,N) uf.par[x]=x, uf.rank[x]=0;
		FOR(x,M) {
			uf(A[x],B[x]);
			FORR(e,cand[x+1]) {
				if(uf[X[e]]==uf[Y[e]]) {
					R[e]=x+1;
				}
				else {
					L[e]=x+2;
				}
			}
			cand[x+1].clear();
		}
	}
	
	FOR(i,Q) {
		if(L[i]>M) cout<<-1<<endl;
		else cout<<L[i]<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
