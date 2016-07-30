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
int P[2020];
ll need[2020],tot[2020];
vector<int> E[2020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N-1) {
		cin>>P[i+1];
		E[P[i+1]].push_back(i+1);
	}
	FOR(i,M) {
		cin>>x>>y;
		need[x]=y;
	}
	
	ll ret=0;
	for(i=N-1;i>=0;i--) if(E[i].size()) {
		ll mi=1<<30;
		FORR(e,E[i]) mi=min(mi,need[e]);
		if(i==0) mi=0;
		FORR(e,E[i]) ret += need[e]-mi;
		need[i]=mi;
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
