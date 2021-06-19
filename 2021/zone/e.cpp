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
int A[505][505];
int B[505][505];
int D[5050505];
vector<pair<int,int>> E[5050505];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		FOR(x,W-1) {
			cin>>A[y][x];
			E[y*500+x].push_back({y*500+x+1,A[y][x]});
			E[y*500+x+1].push_back({y*500+x,A[y][x]});
		}
	}
	FOR(y,H-1) {
		FOR(x,W) {
			cin>>B[y][x];
			E[y*500+x].push_back({y*500+x+500,B[y][x]});
		}
	}
	
	FOR(y,H) {
		FOR(x,W) {
			for(i=1;i<=y;i++) E[y*500+x].push_back({(y-i)*500+x,1+i});
		}
	}
	FOR(y,H) FOR(x,500) D[y*500+x]=1<<30;
	D[0]=0;
	priority_queue<pair<int,int>> Q;
	Q.push({0,0});
	while(Q.size()) {
		int co=-Q.top().first;
		int cur=Q.top().second;
		Q.pop();
		if(D[cur]!=co) continue;
		if(cur==(H-1)*500+(W-1)) {
			cout<<co<<endl;
			return;
		}
		FORR2(e,c,E[cur]) if(D[e]>co+c) {
			D[e]=co+c;
			Q.push({-D[e],e});
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
