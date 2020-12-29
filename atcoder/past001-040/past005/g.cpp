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


int H,W;
string S[4];
int C;
vector<pair<int,int>> V;
int vis[4][4];

void dfs(int y,int x) {
	V.push_back({y,x});
	if(V.size()==C) {
		cout<<C<<endl;
		FORR(c,V) cout<<c.first+1<<" "<<c.second+1<<endl;
		exit(0);
	}
	vis[y][x]=1;
	int i;
	int d[4]={-1,0,1,0};
	FOR(i,4) {
		int ty=y+d[i];
		int tx=x+d[i^1];
		if(ty<0||ty>=H||tx<0||tx>=W) continue;
		if(S[ty][tx]=='.') continue;
		if(vis[ty][tx]) continue;
		dfs(ty,tx);
	}
	vis[y][x]=0;
	V.pop_back();
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>S[y];
		FORR(c,S[y]) if(c=='#') C++;
	}
	
	FOR(y,H) FOR(x,W) if(S[y][x]=='#') dfs(y,x);
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
