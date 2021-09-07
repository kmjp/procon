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
vector<vector<int>> E;
ll vis[202020];
int have[202020];

ll id=1;
pair<int,int> farthest(vector<vector<int>>& E, int cur,int pre,int d,vector<int>& D) {
	D[cur]=d;
	pair<int,int> r={d,cur};
	FORR(e,E[cur]) if(e!=pre) r=max(r, farthest(E,e,cur,d+1,D));
	return r;
}

pair<int,vector<int>> diameter(vector<vector<int>>& E) { // diameter,center
	vector<int> D[2];
	D[0].resize(E.size());
	D[1].resize(E.size());
	auto v1=farthest(E,0,0,0,D[0]);
	auto v2=farthest(E,v1.second,v1.second,0,D[0]);
	farthest(E,v2.second,v2.second,0,D[1]);
	pair<int,vector<int>> R;
	R.first = v2.first;
	//—¼’[‚ðŽæ‚éê‡
	R.second.push_back(v1.second);
	R.second.push_back(v2.second);

	return R;
}

int dfs1(int cur,int pre,int tar) {
	if(cur==tar) have[cur]=1;
	vis[cur]=id;
	FORR(e,E[cur]) if(e!=pre) {
		have[cur]|=dfs1(e,cur,tar);
	}
	return have[cur];
}
void dfs2(int cur,int pre) {
	
	vis[cur]=id;
	FORR(e,E[cur]) if(e!=pre) {
		if(have[e]==0) {
			id++;
			dfs2(e,cur);
		}
	}
	FORR(e,E[cur]) if(e!=pre) {
		if(have[e]) {
			id++;
			dfs2(e,cur);
		}
	}
	id++;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	E.resize(N);
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	auto a=diameter(E);
	
	x=a.second[0];
	y=a.second[1];
	dfs1(x,x,y);
	dfs2(x,x);
	FOR(i,N) cout<<vis[i]<<" ";
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
