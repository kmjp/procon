#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N;
ll W[202020];
ll WS[202020];
vector<int> E[202020];
set<ll> S[202020];
ll ret;


ll dfs(int cur,int pre) {
	WS[cur]=W[cur];
	FORR(e,E[cur]) if(e!=pre) WS[cur]+=dfs(e,cur);
	return WS[cur];
}

void dfs2(int cur,int pre) {
	
	FORR(e,E[cur]) if(e!=pre) {
		dfs2(e,cur);
		if(S[cur].size()<S[e].size()) swap(S[cur],S[e]);
		vector<ll> C1,C2;
		auto it=S[cur].lower_bound(WS[0]/3);
		if(it!=S[cur].end()) {
			C1.push_back(*it);
			if(next(it)!=S[cur].end()) C1.push_back(*next(it));
		}
		if(it!=S[cur].begin()) C1.push_back(*prev(it));
		it=S[e].lower_bound(WS[0]/3);
		if(it!=S[e].end()) {
			C2.push_back(*it);
			if(next(it)!=S[e].end()) C2.push_back(*next(it));
		}
		if(it!=S[e].begin()) C2.push_back(*prev(it));
		FORR(c,C1) FORR(d,C2) {
			ll V[]={c,d,WS[0]-c-d};
			sort(V,V+3);
			ret=min(ret,V[2]-V[0]);
		}
		FORR(v,S[e]) S[cur].insert(v);
	}
	
	if(S[cur].size()) {
		vector<ll> C1;
		auto it=S[cur].lower_bound(WS[cur]/2);
		if(it!=S[cur].end()) {
			C1.push_back(*it);
			if(next(it)!=S[cur].end()) C1.push_back(*next(it));
		}
		if(it!=S[cur].begin()) C1.push_back(*prev(it));
		FORR(c,C1) {
			ll V[]={c,WS[cur]-c,WS[0]-WS[cur]};
			sort(V,V+3);
			ret=min(ret,V[2]-V[0]);
		}
		
	}
	S[cur].insert(WS[cur]);
	
}

	
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>W[i];
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	dfs(0,0);
	
	ret=WS[0];
	dfs2(0,0);
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
