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
vector<int> E[101010];
int P[101010];
vector<pair<int,int>> Es;
int ret[101010];

int vis[101010];
int NV[101010];

int dfs(int cur,int pre) {
	NV[cur]=1;
	FORR(e,E[cur]) if(e!=pre && vis[e]==0) NV[cur]+=dfs(e,cur);
	return NV[cur];
}

int dfs2(int cur,int pre,int TNV) {
	int tot=1;
	int ok=1;
	FORR(e,E[cur]) if(e!=pre && vis[e]==0) {
		int c = dfs2(e,cur,TNV);
		if(c!=-1) return c;
		tot += NV[e];
		if(NV[e]*2>TNV) ok=0;
	}
	if((TNV-tot)*2>TNV) ok=0;
	if(ok) return cur;
	return -1;
}

int split(int cur,int id) {
	int TNV = dfs(cur,-1);
	if(TNV==0) return -1;
	int center=dfs2(cur,-1,TNV);
	ret[center]=id;
	vis[center]=1;
	FORR(e,E[center]) if(vis[e]==0) {
		P[split(e,id+1)]=center+1;
	}
	return center;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	MINUS(P);
	split(0,0);
	FOR(i,N) cout<<P[i]<<" ";
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
