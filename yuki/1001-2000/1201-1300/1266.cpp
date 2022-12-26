#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M,Q;
int S[101010];
vector<int> E[101010];
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
UF<700000> uf;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>Q;
	FOR(i,N) {
		cin>>s;
		FOR(j,7) if(s[j]=='1') S[i]|=(1<<j)|(1<<(j+7));
		FOR(j,7) if((S[i]&(1<<j))&&(S[i]&(1<<(j+1)))) {
			uf(i*7+j,i*7+(j+1)%7);
		}
	}
	FOR(i,M) {
		cin>>x>>y;
		x--,y--;
		E[x].push_back(y);
		E[y].push_back(x);
		FOR(j,7) if(S[x]&S[y]&(1<<j)) {
			uf(x*7+j,y*7+j);
		}
	}
	FOR(i,Q) {
		cin>>j>>x>>y;
		x--,y--;
		if(j==1) {
			S[x]|=(1<<y)|(1<<(y+7));
			FOR(j,7) {
				if((S[x]&(1<<j))&&(S[x]&(1<<(j+1)))) uf(x*7+j,x*7+(j+1)%7);
				FORR(e,E[x]) if(S[x]&S[e]&(1<<j)) uf(x*7+j,e*7+j);
			}
		}
		else {
			cout<<uf.count(x*7)<<endl;
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
