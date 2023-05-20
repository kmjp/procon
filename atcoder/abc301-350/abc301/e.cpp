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

int H,W,T,A;
string S[303];
int D[20][20];
int X[20],Y[20];
int CD[303][303];

ll dp[1<<20][20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>T;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) {
			if(S[y][x]=='S') X[0]=x,Y[0]=y,S[y][x]='.';
			if(S[y][x]=='G') X[1]=x,Y[1]=y,S[y][x]='.';
			if(S[y][x]=='o') {
				X[A+2]=x,Y[A+2]=y,S[y][x]='.';
				A++;
			}
		}
	}
	A+=2;
	FOR(i,A) {
		FOR(y,H) FOR(x,W) CD[y][x]=1<<30;
		CD[Y[i]][X[i]]=0;
		queue<int> Q;
		Q.push(Y[i]*W+X[i]);
		while(Q.size()) {
			int cy=Q.front()/W;
			int cx=Q.front()%W;
			Q.pop();
			FOR(j,4) {
				int d[4]={1,0,-1,0};
				int ty=cy+d[j];
				int tx=cx+d[j^1];
				if(ty<0||ty>=H||tx<0||tx>=W||S[ty][tx]=='#') continue;
				if(CD[ty][tx]==1<<30) {
					CD[ty][tx]=CD[cy][cx]+1;
					Q.push(ty*W+tx);
				}
			}
		}
		FOR(j,A) {
			D[i][j]=CD[Y[j]][X[j]];
		}
	}
	int mask;
	FOR(mask,1<<A) FOR(i,A) dp[mask][i]=1LL<<60;
	dp[1][0]=0;
	FOR(mask,1<<A) FOR(i,A) if(dp[mask][i]<1LL<<60) {
		FOR(j,A) if((mask&(1<<j))==0) chmin(dp[mask|(1<<j)][j],dp[mask][i]+D[i][j]);
	}
	int ma=-1;
	FOR(mask,1<<A) if(dp[mask][1]<=T) ma=max(ma,__builtin_popcount(mask)-2);
	cout<<ma<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
