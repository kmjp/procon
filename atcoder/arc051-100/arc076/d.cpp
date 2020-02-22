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

int X[101010],Y[101010];
vector<pair<int,int>> XX;
vector<pair<int,int>> YY;
vector<pair<int,pair<int,int>>> ev;
UF<500000> uf;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		XX.push_back({X[i],i});
		YY.push_back({Y[i],i});
	}
	sort(ALL(XX));
	sort(ALL(YY));
	FOR(i,N-1) {
		ev.push_back({XX[i+1].first-XX[i].first,{XX[i].second,XX[i+1].second}});
		ev.push_back({YY[i+1].first-YY[i].first,{YY[i].second,YY[i+1].second}});
	}
	ll ret=0;
	sort(ALL(ev));
	FORR(e,ev) {
		if(uf[e.second.first]!=uf[e.second.second]) {
			uf(e.second.first,e.second.second);
			ret+=e.first;
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
