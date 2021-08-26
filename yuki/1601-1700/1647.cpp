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

int H,W,N;
int X[202020],Y[202020];

vector<pair<int,int>> E[402020];
vector<pair<int,int>> path;
int vis[404040];

void dfs(int cur,int pre) {
	
	if(vis[cur]) {
		vector<int> ret;
		int ok=0;
		FORR2(e,i,path) {
			if(ok) ret.push_back(i+1);
			if(e==cur) ok++;
		}
		if(cur>=H) {
			reverse(ret.begin(),ret.end()-1);
		}
		
		cout<<ret.size()<<endl;
		FORR(r,ret) cout<<r<<" ";
		cout<<endl;
		exit(0);
		
	}
	vis[cur]=1;
	FORR2(e,i,E[cur]) if(e!=pre) {
		path.push_back({e,i});
		dfs(e,cur);
		path.pop_back();
		
	}
	
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>N;
	FOR(i,N) {
		cin>>Y[i]>>X[i];
		Y[i]--,X[i]--;
		E[Y[i]].push_back({H+X[i],i});
		E[H+X[i]].push_back({Y[i],i});
	}
	
	FOR(y,H) if(vis[y]==0) {
		path.push_back({y,-1});
		dfs(y,-1);
		path.pop_back();
	}
	
	cout<<-1<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
