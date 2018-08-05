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

int N,M;
ll V[101010];
ll E[101010];

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

ll ret;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) V[i]=1;
	FOR(i,M) {
		cin>>x>>y;
		x--,y--;
		if(uf[x]==uf[y]) {
			E[uf[x]]++;
		}
		else {
			V[uf[x]]=V[uf[y]]=V[uf[x]]+V[uf[y]];
			E[uf[x]]=E[uf[y]]=E[uf[x]]+E[uf[y]]+1;
			uf(x,y);
		}
	}
	
	ll cur=max(V[uf[0]],V[uf[1]]);
	FOR(i,N) if(uf[i]==i) {
		ret+=V[i]*(V[i]-1)/2-E[i];
		if(i!=uf[0] && i!=uf[1]) {
			ret+=cur*V[i];
			cur+=V[i];
		}
	}
	cout<<ret<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
