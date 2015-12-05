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

int N,M;
int D[180800],C[180800],T[180800];
vector<int> E[101010];

map<int,ll> CT[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y>>j>>k;
		E[x].push_back(i*2);
		E[y].push_back(i*2+1);
		D[i*2]=y;
		D[i*2+1]=x;
		C[i*2]=C[i*2+1]=j;
		T[i*2]=T[i*2+1]=k;
	}
	
	priority_queue<pair<ll,pair<int,int>>> PQ;
	CT[1][1]=0;
	PQ.push({0,{1,1}});
	ll mi=1LL<<60;
	
	while(PQ.size()) {
		auto k=PQ.top();
		PQ.pop();
		ll cost=-k.first;
		int cur=k.second.first;
		int col=k.second.second;
		if(CT[cur][col]!=cost) continue;
		if(cur==N) return _P("%lld\n",cost);
		FORR(r,E[cur]) {
			ll nc=cost+abs(col-C[r])+T[r];
			
			if(CT[D[r]].count(C[r])==0 || CT[D[r]][C[r]]>nc) {
				CT[D[r]][C[r]] = nc;
				PQ.push({-nc,{D[r],C[r]}});
			}
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
