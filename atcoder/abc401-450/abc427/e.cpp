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
string S[12];
int TY,TX;
int memo[25][25][13][13][13][13];

int dfs(int dx,int dy,int ML,int MR,int MU,int MD) {
	int num=0;
	int y,x;
	if(abs(dx)>12||abs(dy)>12) return 0;
	if(memo[dx+12][dy+12][ML][MR][MU][MD]>=0) return memo[dx+12][dy+12][ML][MR][MU][MD];
	
	int ret=1<<30;
	memo[dx+12][dy+12][ML][MR][MU][MD]=1<<30;
	FOR(y,H) FOR(x,W) {
		if(x<ML) continue;
		if(x+MR>=W) continue;
		if(y<MU) continue;
		if(y+MD>=H) continue;
		if(S[y][x]=='#') num++;
	}
	int tx=dx+TX;
	int ty=dy+TY;
	if(tx>=0&&tx<W&&ty>=0&&ty<H&&S[ty][tx]=='#') {
		if(tx>=ML&&tx+MR<W&&ty>=MU&&ty+MD<H) {
			return 1<<30;
		}
	}
	if(num==0) {
		return memo[dx+12][dy+12][ML][MR][MU][MD]=0;
	}
	ret=min(ret,dfs(dx-1,dy,ML,max(MR,-(dx-1)),MU,MD)+1);
	ret=min(ret,dfs(dx+1,dy,max(ML,dx+1),MR,MU,MD)+1);
	ret=min(ret,dfs(dx,dy-1,ML,MR,MU,max(MD,-(dy-1)))+1);
	ret=min(ret,dfs(dx,dy+1,ML,MR,max(MU,dy+1),MD)+1);
	
	
	return memo[dx+12][dy+12][ML][MR][MU][MD]=ret;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	MINUS(memo);
	cin>>H>>W;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) {
			if(S[y][x]=='T') {
				S[y][x]='.';
				TY=y,TX=x;
			}
		}
	}
	int ret=dfs(0,0,0,0,0,0);
	if(ret>=1<<30) ret=-1;
	cout<<ret<<endl;
	
	
	
			
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
