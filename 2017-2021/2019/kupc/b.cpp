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

int N,M,W;
int A[101],B[101];

ll dp[10101];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>W;
	FOR(i,N) {
		cin>>A[i]>>B[i];
	}
	FOR(i,M) {
		cin>>x>>y;
		x=uf[x-1];
		y=uf[y-1];
		if(x!=y) {
			A[x]=A[y]=A[x]+A[y];
			B[x]=B[y]=B[x]+B[y];
			uf(x,y);
		}
	}
	
	FOR(i,N) if(uf[i]==i) {
		for(x=W-A[i];x>=0;x--) dp[x+A[i]]=max(dp[x+A[i]],dp[x]+B[i]);
	}
	
	cout<<*max_element(dp,dp+W+1)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
