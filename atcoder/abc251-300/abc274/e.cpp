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

int N,M,V;
ll X[18],Y[18];
long double D[18][18];

long double dp[1<<18][18];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>X[i+1]>>Y[i+1];
	FOR(i,M) cin>>X[N+1+i]>>Y[N+1+i];
	V=N+M+1;
	FOR(x,V) FOR(y,V) D[x][y]=hypot(X[x]-X[y],Y[x]-Y[y]);
	
	int mask;
	FOR(x,V) FOR(mask,1<<V) dp[mask][x]=1e20;
	dp[1][0]=0;
	long double mi=1e20;
	
	FOR(mask,1<<V) FOR(x,V) if(mask&(1<<x)) {
		int speed=1;
		int did=0;
		FOR(i,M) if(mask&(1<<(N+1+i))) speed*=2;
		FOR(i,N) if(mask&(1<<(1+i))) did++;
		if(did==N) mi=min(mi,dp[mask][x]+D[x][0]/speed);
		FOR(y,V) if((mask&(1<<y))==0) {
			chmin(dp[mask|(1<<y)][y],dp[mask][x]+D[x][y]/speed);
		}
	}
	_P("%.12lf\n",(double)mi);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
