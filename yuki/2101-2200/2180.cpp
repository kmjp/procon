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

int N;
int X[12],Y[12];
int dp[1<<12][12][12];

int on(int a,int b,int c) {
	int dx=X[b]-X[a];
	int dy=Y[b]-Y[a];
	int ex=X[c]-X[b];
	int ey=Y[c]-Y[b];
	int g=__gcd(abs(dx),abs(dy));
	dx/=g;
	dy/=g;
	g=__gcd(abs(ex),abs(ey));
	ex/=g;
	ey/=g;
	return dx==ex&&dy==ey;
}
int sgn(int a,int b,int c,int d) {
	int dx=X[b]-X[a];
	int dy=Y[b]-Y[a];
	int ex=X[d]-X[c];
	int ey=Y[d]-Y[c];
	int z=dx*ey-dy*ex;
	if(z<0) return -1;
	if(z>0) return 1;
	return 0;
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
	}
	if(N==1) {
		cout<<1<<endl;
		return;
	}
	int mask,mask2;
	FOR(mask,1<<N) {
		FOR(x,N) FOR(y,N) dp[mask][x][y]=100;
	}
	FOR(x,N) FOR(y,N) if(x!=y) dp[(1<<x)|(1<<y)][x][y]=1;
	FOR(mask,1<<N) {
		FOR(x,N) FOR(y,N) if(x!=y&&(mask&(1<<x))&&(mask&(1<<y))) {
			FOR(i,N) if((mask&(1<<i))==0) {
				chmin(dp[mask^(1<<i)][y][i],dp[mask][x][y]+(on(x,y,i)^1));
				FOR(j,N) if((mask&(1<<j))==0&&i!=j) {
					if(on(x,y,i)&&on(y,i,j)) chmin(dp[mask^(1<<i)^(1<<j)][i][j],dp[mask][x][y]);
					if(on(x,y,i)) chmin(dp[mask^(1<<i)^(1<<j)][i][j],dp[mask][x][y]+1);
					if(on(y,i,j)) chmin(dp[mask^(1<<i)^(1<<j)][i][j],dp[mask][x][y]+1);
					if(!on(x,y,i)&&!on(y,i,j)&&sgn(x,y,y,i)==sgn(y,i,i,j)&&sgn(x,y,y,i)==sgn(x,y,i,j)) {
						chmin(dp[mask^(1<<i)^(1<<j)][i][j],dp[mask][x][y]+1);
					}
					chmin(dp[mask^(1<<i)^(1<<j)][i][j],dp[mask][x][y]+2);
				}
			}
		}
	}
	int ret=100;
	FOR(x,N) FOR(y,N) ret=min(ret,dp[(1<<N)-1][x][y]);
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
