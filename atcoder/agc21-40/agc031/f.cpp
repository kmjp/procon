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
int mo;
int A[101010],B[101010],C[101010];

int ok[1010101][2];

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
UF<303030> uf;
int id(int v,int p,int par) { return v*6+p%3*2+par;}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>Q>>mo;
	int G=0;
	FOR(i,M) {
		cin>>A[i]>>B[i]>>C[i];
		A[i]--;
		B[i]--;
		if(i) G=__gcd(G,abs(C[i]-C[0]));
	}
	if(G==0) G=mo;
	mo=__gcd(mo,3*G);
	int c=C[0]%(3*G);
	
	ll a=c;
	FOR(i,2*mo) {
		ok[a][i%2]=1;
		a=a*2%mo;
	}
	
	FOR(i,M) {
		C[i]=(C[i]-c+3*G)/G%3;
		FOR(x,3) {
			uf(id(A[i],x,0),id(B[i],2*x+C[i],1));
			uf(id(A[i],x,1),id(B[i],2*x+C[i],0));
			uf(id(B[i],x,0),id(A[i],2*x+C[i],1));
			uf(id(B[i],x,1),id(A[i],2*x+C[i],0));
		}
	}
	
	FOR(i,Q) {
		cin>>x>>y>>r;
		x--,y--;
		int ret=0;
		FOR(j,3) FOR(k,2) if(uf[id(y,0,0)]==uf[id(x,j,k)]) {
			int dif=(r+c-j*G+3*G+3*mo)%mo;
			if(ok[dif][k]) ret=1;
		}
		if(ret) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
