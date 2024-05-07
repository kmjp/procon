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
int N;
string G[10];
string S;

void dfs(int cy,int cx,set<pair<int,int>>& V) {
	if(V.count({cy,cx})) return;
	if(V.size()==N) {
		cout<<"Yes"<<endl;
		exit(0);
	}
	if(cy<0||cy>=H||cx<0||cx>=W) return;
	if(S[V.size()]!=G[cy][cx]) return;
	
	V.insert({cy,cx});
	int dy[8]={-1,-1,-1,0,0,1,1,1};
	int dx[8]={-1,0,1,-1,1,-1,0,1};
	int i;
	FOR(i,8) {
		dfs(cy+dy[i],cx+dx[i],V);
	}
	V.erase({cy,cx});
		
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) cin>>G[y];
	cin>>N>>S;
	set<pair<int,int>> V;
	FOR(y,H) FOR(x,W) dfs(y,x,V);
	cout<<"No"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
