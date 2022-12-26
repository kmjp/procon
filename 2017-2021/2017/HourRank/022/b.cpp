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
ll sum;
map<int,int> mp;

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
UF<200000> uf,uf2;
int NN;
map<int,vector<pair<int,int>>> E;

void solve() {
	int i,j,k,l,x,y; string s;
	
	cin>>N>>M;
	if(N==1) _P("0 0\n");
	FOR(i,M) {
		cin>>x>>y>>j;
		E[j].push_back({x-1,y-1});
	}
	NN=N;
	
	int mi;
	FORR(e,E) {
		FORR(rr,e.second) {
			if(uf[rr.first]!=uf[rr.second]) {
				uf(rr.first,rr.second);
				sum+=e.first;
				NN--;
			}
		}
		if(NN==1) {
			sum-=e.first;
			mi=e.first;
			break;
		}
	}
	
	int cand=0;
	FORR(e,E) {
		if(e.first<mi) {
			FORR(rr,e.second) uf2(rr.first,rr.second);
		}
		else {
			FORR(rr,e.second) if(uf2[rr.first] != uf2[rr.second]) cand++;
		}
	}
	
	
	cout<<sum<<" "<<cand<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
