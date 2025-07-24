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
vector<int> E[202020];
int D[202020];
int ma;

void dfs2(int cur,int pre,int p) {
	vector<int> ds={p};
	FORR(e,E[cur]) if(e!=pre) ds.push_back(D[e]+1);
	sort(ALL(ds));
	reverse(ALL(ds));
	int i;
	FOR(i,ds.size()) ma=max(ma,(i+1)*ds[i]+1);
	
	FORR(e,E[cur]) if(e!=pre) {
		dfs2(e,cur,ds[ds[0]==(D[e]+1)]+1);
	}
}

int dfs(int cur,int pre) {
	D[cur]=0;
	FORR(e,E[cur]) if(e!=pre) D[cur]=max(D[cur],1+dfs(e,cur));
	return D[cur];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	dfs(0,0);
	dfs2(0,0,0);
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
