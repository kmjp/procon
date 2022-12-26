#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int H,W,K;
string T;
string S[1010];
ll nex[201010][4];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

ll D[2020][2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K;
	cin>>T;
	T+=T;
	FOR(i,4) nex[2*K][i]=1LL<<40;
	for(i=2*K-1;i>=0;i--) {
		FOR(j,4) nex[i][j]=nex[i+1][j];
		if(T[i]=='U') nex[i][3]=i;
		if(T[i]=='D') nex[i][1]=i;
		if(T[i]=='L') nex[i][2]=i;
		if(T[i]=='R') nex[i][0]=i;
	}
	
	int SX,SY,GY,GX;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) {
			if(S[y][x]=='S') SX=x,SY=y;
			if(S[y][x]=='G') GX=x,GY=y;
		}
	}
	
	FOR(y,H) FOR(x,W) D[y][x]=1LL<<50;
	priority_queue<pair<ll,int>> Q;
	D[SY][SX]=0;
	Q.push({0,SY*10000+SX});
	
	while(Q.size()) {
		ll co=-Q.top().first;
		if(co>=1LL<<50) break;
		int cy=Q.top().second/10000;
		int cx=Q.top().second%10000;
		Q.pop();
		if(D[cy][cx]!=co) continue;
		
		int id=co%K;
		FOR(i,4) if(nex[id][i]<1LL<<40) {
			int ty=cy+dy[i];
			int tx=cx+dx[i];
			if(ty<0 || ty>=H || tx<0 || tx>=W || S[ty][tx]=='#') continue;
			ll nc=co+(nex[id][i]-id)+1;
			if(D[ty][tx]>nc) {
				D[ty][tx]=nc;
				Q.push({-nc,ty*10000+tx});
			}
		}
	}
	
	ll ret=D[GY][GX];
	if(ret>=1LL<<50) ret=-1;
	cout<<ret<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
