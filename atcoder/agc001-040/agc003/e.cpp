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

int N,Q;
ll V[101010];
map<ll,ll> M;
ll RR[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	V[0]=N;
	FOR(i,Q) cin>>V[i+1];
	
	ll prev=V[Q];
	M[-prev]=1;
	for(i=Q-1;i>=0;i--) if(prev>V[i]) {
		prev = V[i];
		for(auto it=M.begin(); it!=M.end() && -it->first > prev; it=M.erase(it)) {
			M[-prev] += (-it->first)/prev * it->second;
			M[-((-it->first)%prev)] += it->second;
		}
	}
	FORR(r,M) RR[-r.first] += r.second;
	
	for(i=N+1;i>=1;i--) RR[i]+=RR[i+1];
	for(i=1;i<=N;i++) _P("%lld\n",RR[i]);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
