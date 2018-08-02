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
UF<500000> uf,uf2;

set<int> S[101010];
set<pair<int,int>> E;
int N,Q;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) S[i+1].insert(i+1);
	while(Q--) {
		cin>>i>>x>>y;
		if(i==1) {
			E.insert({x,y});
			E.insert({y,x});
			
			x=uf[x];
			y=uf[y];
			if(x!=y) {
				if(S[x].size()<S[y].size()) swap(S[x],S[y]);
				FORR(s,S[y]) S[x].insert(s);
				S[y].clear();
				uf(x,y);
				if(uf[x]==y) swap(S[x],S[y]);
			}
		}
		else if(i==2) {
			x=uf[x];
			FORR(s,S[x]) uf2(s,x);
			S[x].clear();
			S[x].insert(x);
		}
		else if(i==3) {
			if(E.count({x,y}) || uf2[x]==uf2[y]) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
		
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
