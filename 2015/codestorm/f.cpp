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

int N;
int A[1010101];
ll mo=1000000007;

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
	set<pair<int,int> > S;
	
	for(i=N-1;i>=0;i--) {
		ITR(it,S) {
			if(it->first>A[i]) break;
			if(uf[2*i]==uf[it->second*2+1]) break;
			uf(2*i,it->second*2+1);
			uf(2*i+1,it->second*2);
			if(uf[2*i]==uf[2*i+1]) return _P("0\n");
		}
		S.insert({A[i],i});
	}
	
	int num=0;
	FOR(i,N) {
		if(uf[2*i]==2*i) num++;
		if(uf[2*i+1]==2*i+1) num++;
	}
	
	ll ret=1;
	FOR(i,num/2) ret=ret*2%mo;
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
