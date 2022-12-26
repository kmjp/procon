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
set<pair<int,ll>> E[101010];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s^=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]^=v,e+=e&-e;}
};
BIT<ll,20> bt;

int id,Q;
int L[101010],R[202020];
int dead[101010];

void dfs(int cur,int pre) {
	L[cur]=id++;
	FORR2(e,c,E[cur]) {
		if(e==pre) {
			bt.add(L[cur],c);
		}
		else {
			dfs(e,cur);
		}
	}
	R[cur]=id;
}

void dfs2(int cur) {
	if(dead[cur]) return;
	dead[cur]=1;
	
	FORR2(e,c,E[cur]) {
		if(L[e]>L[cur]) dfs2(e);
		else {
			bt.add(L[cur],c);
		}
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		ll a;
		cin>>x>>y>>a;
		x--,y--;
		E[x].insert({y,a});
		E[y].insert({x,a});
	}
	
	dfs(0,0);
	
	cin>>Q;
	while(Q--) {
		cin>>y>>x;
		x--;
		if(y==1) {
			dfs2(x);
		}
		else {
			cout<<(bt(R[x]-1)^bt(L[x]))<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
