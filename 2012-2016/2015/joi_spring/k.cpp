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

int N,M,K;

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
UF<1000> uf[10101];

int R[301010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	vector<vector<int>> V;
	FOR(i,M) {
		cin>>x>>y>>r;
		V.push_back({r,x-1,y-1,i});
	}
	sort(ALL(V));
	reverse(ALL(V));
	FORR(v,V) {
		x=v[1];
		y=v[2];
		if(uf[K-1][x]==uf[K-1][y]) continue;
		int LL=-1,RR=K;
		while(LL+1<RR) {
			int M=(LL+RR)/2;
			if(uf[M][v[1]]==uf[M][v[2]]) LL=M;
			else RR=M;
		}
		R[v[3]]=RR+1;
		uf[RR](v[1],v[2]);
	}
	FOR(i,M) cout<<R[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
