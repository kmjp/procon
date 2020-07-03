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

int N,M,L;
ll T[2020];
vector<pair<int,int>> E[2020];
ll D[2020][2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>L;
	L--;
	int num=0;
	FOR(i,N) {
		cin>>T[i];
		if(T[i]) num++;
	}
	if(num==1) return _P("0\n");
	
	FOR(x,N) FOR(y,N) D[x][y]=1LL<<60;
	FOR(i,M) {
		cin>>x>>y>>r;
		E[x-1].push_back({y-1,r});
		E[y-1].push_back({x-1,r});
	}
	ll mi=1LL<<60;
	FOR(i,N) {
		D[i][i]=0;
		priority_queue<pair<ll,int>> PQ;
		PQ.push({0,i});
		while(PQ.size()) {
			ll co=-PQ.top().first;
			int cur=PQ.top().second;
			PQ.pop();
			if(D[i][cur]!=co) continue;
			FORR(e,E[cur]) if(D[i][e.first]>D[i][cur]+e.second) {
				D[i][e.first]=D[i][cur]+e.second;
				PQ.push({-D[i][e.first],e.first});
			}
		}
	}
	FOR(i,N) {
		ll tot=0;
		ll del=(1LL<<60);
		FOR(x,N) if(T[x]) {
			tot+=T[x]*D[i][x]*2;
			del=min(del,D[L][x]-D[x][i]);
		}
		mi=min(mi,tot+del);
	}
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
