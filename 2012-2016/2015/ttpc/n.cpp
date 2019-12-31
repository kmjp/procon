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

template<class V,int MV> class Bellman_Ford {
public:
	int NV;
	V cost[MV];
	vector<pair<int,V> > E[MV];
	
	void add_edge(int from,int to,V cost){ E[from].push_back(make_pair(to,cost));}
	bool calc(int start,int NV) { // true:ok false:cycle
		int i,j,k;
		FOR(i,NV) cost[i]=1e10;
		cost[start]=0;
		FOR(i,NV) {
			bool up=false;
			FOR(j,NV) FOR(k,E[j].size()) {
				if(cost[E[j][k].first]>cost[j]+E[j][k].second) cost[E[j][k].first]=cost[j]+E[j][k].second, up=true;
			}
			if(!up) return true;
		}
		return false;
	}
};

int N,M,K;
int FIX[3030];
int U[3030],V[3030],C[3030];

bool ok(double T) {
	Bellman_Ford<double,3030> bf;
	int i,x,y;
	
	FOR(i,N) if(FIX[i]!=1<<30) {
		bf.add_edge(0,i+1,FIX[i]);
		bf.add_edge(i+1,0,-FIX[i]);
	}
	FOR(i,M) bf.add_edge(V[i],U[i],T-C[i]);
	return bf.calc(0,N+1);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,N) FIX[i]=1<<30;
	FOR(i,K) cin>>x>>y, FIX[x-1]=y;
	FOR(i,M) cin>>U[i]>>V[i]>>C[i];
	
	double L=-1e10,R=1e10;
	while(R-L>1e-8) {
		double M=(L+R)/2;
		if(ok(M)) R=M;
		else L=M;
	}
	
	if(L<-1e9) _P("#\n");
	else _P("%.12lf\n",L);
	
}

int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
