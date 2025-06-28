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

int T;
int H,W;
string S[1010101];
vector<int> vis[1<<20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W;
		FOR(y,H) {
			cin>>S[y];
			vis[y].resize(W);
		}
		queue<int> Q;
		FOR(y,H) FOR(x,W) {
			vis[y][x]=0;
			if(S[y][x]=='L'&&x==0) vis[y][x]=1;
			if(S[y][x]=='R'&&x==W-1) vis[y][x]=1;
			if(S[y][x]=='U'&&y==0) vis[y][x]=1;
			if(S[y][x]=='D'&&y==H-1) vis[y][x]=1;
			if(vis[y][x]==1) Q.push(y*W+x);
		}
		while(Q.size()) {
			y=Q.front()/W;
			x=Q.front()%W;
			Q.pop();
			if(y&&S[y-1][x]=='D'&&vis[y-1][x]==0) vis[y-1][x]=1, Q.push((y-1)*W+x);
			if(x&&S[y][x-1]=='R'&&vis[y][x-1]==0) vis[y][x-1]=1, Q.push((y-0)*W+x-1);
			if(y+1<H&&S[y+1][x]=='U'&&vis[y+1][x]==0) vis[y+1][x]=1, Q.push((y+1)*W+x);
			if(x+1<W&&S[y][x+1]=='L'&&vis[y][x+1]==0) vis[y][x+1]=1, Q.push((y-0)*W+x+1);
		}
		int ret=0;
		FOR(y,H) FOR(x,W) {
			if(vis[y][x]==1) continue;
			if(S[y][x]=='?') {
				int ng=0;
				if(y==0||vis[y-1][x]) ng++;
				if(x==0||vis[y][x-1]) ng++;
				if(y==H-1||vis[y+1][x]) ng++;
				if(x==W-1||vis[y][x+1]) ng++;
				if(ng!=4) ret++;
			}
			else {
				ret++;
			}
		}
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
