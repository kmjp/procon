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
string S[1515];
int M[2][1515][1515];

int id[1515][1515];
ll mo=998244353;
int V[1500],E[1500],P[1500];

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

ll hoge(int t,int N) {
	int a,b;
	ll pat=1;
	if(N%2==0) {
		FOR(b,N) FOR(a,b) pat=pat*(2-__builtin_popcount(M[t][a][b]))%mo;
	}
	else {
		UF<1510> uf;
		FOR(b,N) FOR(a,b) {
			if(M[t][a][b]==3) return 0;
			if(M[t][a][b]==0) uf(a,b);
		}
		ZERO(V);
		ZERO(E);
		ZERO(P);
		FOR(a,N) {
			V[uf[a]]++;
			FOR(b,a) if(M[t][b][a]==0) E[uf[a]]++;
		}
		FOR(a,N) FOR(b,a) if(M[t][b][a]==2) {
			P[uf[a]]^=1;
			P[uf[b]]^=1;
		}
		FOR(a,N) if(uf[a]==a) {
			FOR(b,E[a]-(V[a]-1)) pat=pat*2%mo;
			if(P[a]) return 0;
		}
		
	}
	return pat;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	for(y=1;y<=N-1;y++) {
		cin>>S[y];
		for(x=1;x<=N-1;x++) {
			int a=abs(x-y);
			int b=x+y;
			if(b>N) b=2*N-b;
			assert(a<=b && (a%2==b%2));
			if(S[y][x-1]=='o') M[a%2][a/2][b/2]|=1;
			if(S[y][x-1]=='x') M[a%2][a/2][b/2]|=2;
		}
	}
	
	ll ret=hoge(0,1+N/2)*hoge(1,(N+1)/2)%mo;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
