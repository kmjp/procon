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
int D[303030];
vector<pair<int,int>> E[303030];
ll sel[303030],no[303030];

void dfs(int cur,int pre) {
	ll pc=0;
	ll sum=0;
	vector<ll> cand(E[cur].size());
	FORR2(e,c,E[cur]) {
		if(e==pre) {
			pc=c;
		}
		else {
			dfs(e,cur);
			sum+=no[e];
			cand.push_back(max(0LL,sel[e]-no[e]));
		}
	}
	sort(ALL(cand));
	reverse(ALL(cand));
	if(D[cur]==0) {
		sel[cur]=-1LL<<60;
		no[cur]=sum;
	}
	else {
		sel[cur]=no[cur]=sum;
		int i;
		FOR(i,D[cur]) no[cur]+=cand[i];
		FOR(i,D[cur]-1) sel[cur]+=cand[i];
		sel[cur]+=pc;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>D[i];
	FOR(i,N-1) {
		cin>>x>>y>>r;
		r=max(r,0);
		E[x-1].push_back({y-1,r});
		E[y-1].push_back({x-1,r});
	}
	
	dfs(0,0);
	cout<<no[0]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
