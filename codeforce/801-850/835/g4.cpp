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

int T;
int N,A,B;
vector<pair<int,int>> E[202020];
set<int> X[2];
void dfs(int cur,int pre,int v,int id) {
	if(id==0&&cur==B) {
		if(v) return;
	}
	
	if(id==1&&cur==pre) {
		;
	}
	else {
		X[id].insert(v);
	}
	FORR2(e,c,E[cur]) if(e!=pre) dfs(e,cur,v^c,id);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>A>>B;
		FOR(i,N) E[i].clear();
		A--,B--;
		FOR(i,N-1) {
			cin>>x>>y>>k;
			E[x-1].push_back({y-1,k});
			E[y-1].push_back({x-1,k});
		}
		X[0].clear();
		X[1].clear();
		dfs(A,A,0,0);
		dfs(B,B,0,1);
		int ok=0;
		FORR(a,X[0]) if(X[1].count(a)) ok=1;
		if(ok) {
			cout<<"Yes"<<endl;
		}
		else {
			cout<<"No"<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
