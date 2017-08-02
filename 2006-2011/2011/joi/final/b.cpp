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

int N,K;
vector<int> G[10];
vector<ll> S[10];

ll from[3030],to[3030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>x>>y;
		G[y-1].push_back(x);
	}
	FOR(i,10) {
		sort(ALL(G[i]));
		G[i].push_back(0);
		reverse(ALL(G[i]));
		ll tot=0;
		FOR(x,G[i].size()) {
			tot+=G[i][x];
			S[i].push_back(tot+x*(x-1));
		}
	}
	
	FOR(i,N+1) from[i]=-1LL<<30;
	from[0]=0;
	FOR(i,10) {
		FOR(x,N+1) to[i]=-1LL<<30;
		FOR(x,N+1) {
			for(y=0;y<S[i].size() && x+y<=K; y++) {
				to[x+y]=max(to[x+y],from[x]+S[i][y]);
			}
		}
		swap(from,to);
	}
	cout<<from[K]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
