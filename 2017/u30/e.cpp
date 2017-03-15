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

int N,K,Q;
string S[1010];
int num[1010][1010];
int ok[1010][1010];

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
UF<1100000> uf;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>Q;
	FOR(y,N) {
		cin>>S[y];
		FOR(x,N) num[y+1][x+1]=(S[y][x]=='#')+num[y][x+1]+num[y+1][x]-num[y][x];
	}
	FOR(y,N-(K-1)) FOR(x,N-(K-1)) {
		if(num[y+K][x+K]-num[y][x+K]-num[y+K][x]+num[y][x]==0) ok[y][x]=1;
	}
	
	FOR(y,N) FOR(x,N) {
		if(ok[y][x] && ok[y+1][x]) uf(y*1010+x,(y+1)*1010+x);
		if(ok[y][x] && ok[y][x+1]) uf(y*1010+x,y*1010+x+1);
	}
	
	while(Q--) {
		int y1,x1,y2,x2;
		cin>>y1>>x1>>y2>>x2;
		if(uf[(y1-1)*1010+(x1-1)]==uf[(y2-1)*1010+(x2-1)]) _P("Yes\n");
		else _P("No\n");
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
