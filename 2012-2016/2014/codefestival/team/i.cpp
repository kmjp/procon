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

int N,M,S,D;
ll dist[101000];
ll A[101000],B[101000],C[101000];
vector<pair<int,ll> > E[101000];

ll next(int cur,ll v) {
	if(v<C[cur]) return C[cur];
	v-=C[cur];
	ll per=A[cur]+B[cur];
	
	if(v%per>=A[cur]) v=(v+per-1)/per*per;
	return C[cur]+v;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>S>>D;
	FOR(i,N) dist[i+1]=1LL<<60;
	FOR(i,N) cin>>A[i+1]>>B[i+1]>>C[i+1];
	FOR(i,M) {
		cin>>x>>y>>r;
		E[x].emplace_back(y,r);
		E[y].emplace_back(x,r);
	}
	
	dist[S]=0;
	priority_queue<pair<ll,int> > Q;
	Q.push(make_pair(0,S));
	while(Q.size()) {
		auto r = Q.top();
		int cur=r.second;
		Q.pop();
		if(-r.first!=dist[cur]) continue;
		
		ll ne=next(cur,dist[cur]);
		FORR(rr,E[cur]) {
			if(dist[rr.first]>ne+rr.second) {
				dist[rr.first]=ne+rr.second;
				Q.push(make_pair(-dist[rr.first],rr.first));
			}
		}
	}
	
	cout<<dist[D]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
