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

int H,W,K;
string S[505050];
vector<int> dp[505050];
int R[505050],C[505050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K;
	FOR(y,H) {
		cin>>S[y];
		dp[y].resize(W,1<<20);
		FOR(x,W) {
			if(S[y][x]=='#') {
				R[y]++;
				C[x]++;
			}
		}
	}
	queue<int> Q;
	int ret=0;
	FOR(y,H) FOR(x,W) if(R[y]==0&&C[x]==0) {
		dp[y][x]=0;
		Q.push(y*W+x);
	}
	while(Q.size()) {
		y=Q.front()/W;
		x=Q.front()%W;
		Q.pop();
		if(dp[y][x]>K) break;
		ret++;
		
		FOR(i,4) {
			int d[]={0,1,0,-1};
			int ty=y+d[i];
			int tx=x+d[i^1];
			if(ty>=0&&ty<H&&tx>=0&&tx<W&&S[ty][tx]=='.'&&chmin(dp[ty][tx],dp[y][x]+1)) Q.push(ty*W+tx);
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
