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
vector<pair<int,int>> E[202020];
vector<ll> C[202020];

ll A[202020];
ll ret[202020];

ll dfs(int cur,int pre) {
	
	FORR2(e,c,E[cur]) if(e!=pre) {
		C[cur].push_back(dfs(e,cur)+c);
		ret[cur]=max(ret[cur],C[cur].back());
	}
	return max(ret[cur],A[cur]);
}

void dfs2(int cur,int pre,ll par) {
	FORR2(e,c,E[cur]) if(e==pre) C[cur].push_back(par+c);
	sort(ALL(C[cur]));
	ret[cur]=max(ret[cur],C[cur].back());
	C[cur].push_back(A[cur]);
	sort(ALL(C[cur]));
	
	FORR2(e,c,E[cur]) if(e!=pre) {
		if(C[cur].back()==max(ret[e],A[e])+c) {
			dfs2(e,cur,C[cur][C[cur].size()-2]);
		}
		else {
			dfs2(e,cur,C[cur].back());
		}
		
	}
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y>>k;
		E[x-1].push_back({y-1,k});
		E[y-1].push_back({x-1,k});
	}
	FOR(i,N) cin>>A[i];
	
	dfs(0,0);
	dfs2(0,0,0);
	FOR(i,N) cout<<ret[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
