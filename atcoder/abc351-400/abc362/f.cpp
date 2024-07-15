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

const int NV=202020;
int N;
vector<int> E[NV];
int num[NV];

pair<int,int> dfs_center(int cur,int pre) {
	pair<int,int> res=make_pair(1<<30,-1);
	int ma=0;
	num[cur]=1;
	
	FORR(r,E[cur]) if(r!=pre) {
		res=min(res,dfs_center(r,cur));
		ma=max(ma,num[r]);
		num[cur]+=num[r];
	}
	return min(res,make_pair(max(ma,N-num[cur]),cur));
}

vector<int> V[202020];

void dfs(int cur,int pre,int id) {
	V[id].push_back(cur);
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur,id);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	pair<int,int> p=dfs_center(0,-1);
	int cent=p.second;
	vector<int> D;
	if(N%2==0) D.push_back(cent);
	vector<pair<int,int>> cand;
	FORR(v,E[cent]) {
		dfs(v,cent,v);
		cand.push_back({V[v].size(),v});
	}
	sort(ALL(cand));
	FORR2(a,v,cand) {
		FORR(b,V[v]) D.push_back(b);
	}
	FOR(x,D.size()/2) {
		cout<<D[x]+1<<" "<<D[x+D.size()/2]+1<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
