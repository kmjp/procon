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

int Y,X;
string S[3];
int vis[9][9];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Y>>X;
	FOR(y,3) cin>>S[y];
	vis[Y-1][X-1]=1;
	queue<pair<int,int>> Q;
	Q.push({Y-1,X-1});
	int ret=0;
	while(Q.size()) {
		auto p=Q.front();
		Q.pop();
		ret++;
		FOR(y,3) FOR(x,3) if(S[y][x]=='#') {
			int ty=p.first-1+y;
			int tx=p.second-1+x;
			if(ty<0||ty>=9||tx<0||tx>=9) continue;
			if(vis[ty][tx]) continue;
			vis[ty][tx]=1;
			Q.push({ty,tx});
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
