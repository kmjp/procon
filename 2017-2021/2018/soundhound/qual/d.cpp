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

int N,M,S,T;
int U[101010],V[101010],A[2][101010];
vector<pair<int,int>> E[101010];

ll D[2][101010];
ll ret[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>S>>T;
	FOR(i,M) {
		cin>>U[i]>>V[i]>>A[0][i]>>A[1][i];
		E[U[i]-1].push_back({V[i]-1,i});
		E[V[i]-1].push_back({U[i]-1,i});
	}
	
	S--,T--;
	FOR(i,N) D[0][i]=D[1][i]=1LL<<60;
	FOR(i,2) {
		priority_queue<pair<ll,int>> PQ;
		if(i==0) {
			D[0][S]=0;
			PQ.push({0,S});
		}
		else {
			D[1][T]=0;
			PQ.push({0,T});
		}
		while(PQ.size()) {
			ll co=-PQ.top().first;
			int cur=PQ.top().second;
			PQ.pop();
			if(D[i][cur]!=co) continue;
			FORR(e,E[cur]) {
				ll nc=co+A[i][e.second];
				if(nc<D[i][e.first]) {
					D[i][e.first]=nc;
					PQ.push({-nc,e.first});
				}
			}
		}
	}
	
	ll mi=1LL<<60;
	for(i=N-1;i>=0;i--) {
		mi=min(mi,D[0][i]+D[1][i]);
		ret[i]=mi;
	}
	FOR(i,N) cout<<1000000000000000LL-ret[i]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
