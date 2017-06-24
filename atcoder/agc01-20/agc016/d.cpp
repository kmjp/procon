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

int N;
int A[101010];
int B[101010];
map<int,int> M[2];
map<int,int> T;
int is[101010];

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
	
	cin>>N;
	
	FOR(i,N) cin>>A[i];
	FOR(i,N) cin>>B[i];
	int cur[2]={};
	FOR(i,N) {
		cur[0] ^= A[i];
		cur[1] ^= B[i];
		M[0][A[i]]++;
		M[1][B[i]]++;
		T[A[i]]=T[B[i]]=0;
	}
	M[0][cur[0]]++;
	M[1][cur[1]]++;
	if(M[0]!=M[1]) return _P("-1\n");
	T[cur[0]]=T[cur[1]]=0;
	x=0;
	FORR(r,T) r.second=x++;
	
	is[T[cur[0]]]=is[T[cur[1]]]=1;
	uf(T[cur[0]],T[cur[1]]);
	int ns=0;
	FOR(i,N) if(A[i]!=B[i]) {
		ns++;
		is[T[A[i]]]=is[T[B[i]]]=1;
		uf(T[A[i]],T[B[i]]);
	}
	
	FOR(i,T.size()) if(is[i]&&uf[i]==i) ns++;
	ns--;
	cout<<ns<<endl;
	
	
	
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
