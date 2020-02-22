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
UF<2000> uf;

int in[2000];
int out[2000];

int N,H;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>H;
	FOR(i,N) {
		int A,B,C,D,L,R;
		cin>>A>>B>>C>>D;
		if(C>0) L=C;
		else L=-A;
		if(D==0) R=B;
		else R=-D;
		
		out[L+1000]++;
		in[R+1000]++;
		uf(L+1000,R+1000);
	}
	
	for(i=-200;i<=-1;i++) {
		if(in[i+1000]>out[i+1000]) return _P("NO\n");
		if(in[i+1000]<out[i+1000]) uf(1000,i+1000);
	}
	for(i=1;i<=200;i++) {
		if(in[i+1000]<out[i+1000]) return _P("NO\n");
		if(in[i+1000]>out[i+1000]) uf(1000,i+1000);
	}
	
	for(i=1000-200;i<=1000+200;i++) if((in[i]||out[i]) && uf[i]!=uf[1000]) return _P("NO\n");
	_P("YES\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
