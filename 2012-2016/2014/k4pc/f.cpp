#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
ll X[100001],K[100001],D[1000001];
map<ll,int> M;
vector<ll> V;
vector<int> num;

template<int MV> class Bellman_Ford {
public:
	int NV;
	ll cost[MV];
	vector<pair<int,ll> > E[MV];
	
	void add_edge(int from,int to,ll cost){ E[from].push_back(make_pair(to,cost));}
	bool calc(int start,int NV) {
		int i,j,k;
		FOR(i,NV) cost[i]=1LL<<61;
		cost[start]=0;
		FOR(i,NV) {
			bool up=false;
			FOR(j,NV) FOR(k,E[j].size()) {
				if(cost[E[j][k].first]>cost[j]+E[j][k].second) {
					cost[E[j][k].first]=cost[j]+E[j][k].second;
					up=true;
				}
			}
			if(!up) return true;
		}
		return false;
	}
};

Bellman_Ford<500010> bf;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	M[1LL<<40]=M[-1LL<<40]=0;
	FOR(i,N) {
		cin>>X[i]>>K[i]>>D[i];
		M[X[i]]=M[X[i]+D[i]]=M[X[i]+D[i]-1]=M[X[i]-D[i]]=M[X[i]-D[i]-1]=0;
	}
	
	ITR(it,M) it->second=V.size(), V.push_back(it->first), num.push_back(0);
	FOR(i,N) num[M[X[i]]]++;
	
	
	for(i=1;i<V.size();i++) bf.add_edge(i,i-1,-num[i]);
	FOR(i,N) bf.add_edge(M[X[i]-D[i]],M[X[i]+D[i]-1],K[i]-1);
	FOR(i,N) bf.add_edge(M[X[i]+D[i]],M[X[i]-D[i]-1],-K[i]);
	if(!bf.calc(V.size()-1,V.size())) return _P("impossible\n");
	if((-bf.cost[0])-N>100000) return _P("too many\n");
	vector<ll> VV;
	for(i=1;i<V.size();i++) {
		x=bf.cost[i]-bf.cost[i-1]-num[i];
		while(x--) VV.push_back(V[i]);
	}
	_P("%d\n",VV.size());
	FOR(i,VV.size()) {
		if(i!=0) _P(" ");
		_P("%lld",VV[i]);
	}
	if(VV.size()) _P("\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
