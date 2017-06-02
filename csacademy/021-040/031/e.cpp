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
int P[202020],V[202020];
vector<int> E[202020];

ll mo=1000000007;
ll tot;

map<int,ll> M[202020];
ll sum[202020];

void dfs(int cur) {
	
	FORR(e,E[cur]) {
		dfs(e);
		if(M[cur].size()<M[e].size()) {
			swap(M[cur],M[e]);
			swap(sum[cur],sum[e]);
		}
		
		FORR(m,M[e]) {
			if(M[cur].count(m.first)) {
				(sum[cur] += M[cur][m.first]*(mo+m.second-1)) %= mo;
				M[cur][m.first] = M[cur][m.first]*m.second % mo;
			}
			else {
				M[cur][m.first] = m.second;
				(sum[cur] += m.second) %= mo;
			}
		}
	}
	
	ll pat = (1+sum[cur]+mo-M[cur].size())%mo;
	(tot += pat)%=mo;
	if(M[cur].count(V[cur])) {
		(sum[cur] += 0+pat)%=mo;
		(M[cur][V[cur]] += 0+pat)%=mo;
	}
	else {
		(sum[cur] += 1+pat)%=mo;
		(M[cur][V[cur]] += 1+pat)%=mo;
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>P[i]>>V[i];
		if(i) {
			P[i]--;
			E[P[i]].push_back(i);
		}
	}
	
	dfs(0);
	
	cout<<tot<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
