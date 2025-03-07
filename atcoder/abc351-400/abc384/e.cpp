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

int H,W,R,C;
ll X,S[555][555];
int vis[555][555];
ll cur;

priority_queue<pair<ll,int>> Q;
void add(int y,int x) {
	cur+=S[y][x];
	int i;
	int d[]={0,1,0,-1};
	FOR(i,4) {
		int ty=y+d[i];
		int tx=x+d[i^1];
		if(ty<0||ty>=H||tx<0||tx>=W||vis[ty][tx]) continue;
		vis[ty][tx]=1;
		Q.push({-S[ty][tx],ty*1000+tx});
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>X;
	cin>>R>>C;
	R--,C--;
	FOR(y,H) FOR(x,W) cin>>S[y][x];
	
	add(R,C);
	vis[R][C]=1;
	while(Q.size()) {
		ll co=-Q.top().first;
		y=Q.top().second/1000;
		x=Q.top().second%1000;
		Q.pop();
		if((__int128)co*X>=cur) break;
		add(y,x);
		
	}
	cout<<cur<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
