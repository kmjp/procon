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
ll R[202020];
vector<int> E[202020];
ll S[202020];
int in[202020];
ll mo=1000000007;

set<int> T;

void dfs1(int cur,int pre) {
	vector<int> rem;
	while(T.size()&&*T.begin()<cur) {
		rem.push_back(*T.begin());
		T.erase(T.begin());
	}
	T.insert(cur);
	FORR(e,E[cur]) if(e!=pre) {
		dfs1(e,cur);
		while(T.size()&&*T.begin()<cur) T.erase(T.begin());
	}
	S[cur]+=T.size();
	FORR(r,rem) T.insert(r);
	
}

void dfs2(int cur,int pre) {
	vector<int> rem;
	while(T.size()&&*T.begin()<cur) {
		rem.push_back(*T.begin());
		T.erase(T.begin());
	}
	S[cur]+=T.size();
	FORR(e,E[cur]) if(e!=pre) {
		dfs2(e,cur);
		while(T.size()&&*T.begin()<cur) T.erase(T.begin());
	}
	FORR(r,rem) T.insert(r);
	T.insert(cur);
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N;
	FOR(i,N) cin>>R[i+1];
	
	
	FOR(i,N-1) {
		cin>>x>>y;
		E[x].push_back(y);
		E[y].push_back(x);
	}
	
	dfs1(1,-1);
	FOR(i,N) reverse(ALL(E[i+1]));
	T.clear();
	dfs2(1,-1);
	T.clear();
	
	ll ret=1;
	for(i=1;i<=N;i++) ret=ret*(R[i]+S[i])%mo;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
