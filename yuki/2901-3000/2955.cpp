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

int N,K;
double X[15],Y[15];

double dp[1<<14][14];
double dp2[1<<14];
double dp3[1<<14];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>X[i]>>Y[i];
	int mask;
	FOR(mask,1<<N) {
		dp2[mask]=dp3[mask]=1e20;
		FOR(i,N) dp[mask][i]=1e20;
	}
	FOR(i,N) dp[1<<i][i]=hypot(X[i],Y[i]);
	FOR(mask,1<<N) FOR(i,N) if(mask&(1<<i)) {
		dp2[mask]=min(dp2[mask],dp[mask][i]+hypot(X[i],Y[i]));
		FOR(j,N) if((mask&(1<<j))==0) {
			chmin(dp[mask|(1<<j)][j],dp[mask][i]+hypot(X[j]-X[i],Y[j]-Y[i]));
		}
	}
	dp3[0]=0;
	FOR(mask,1<<N) {
		for(int sm=mask;sm>=0;--sm) {
			sm=sm&mask;
			if(__builtin_popcount(sm)<=K) {
				chmin(dp3[mask],dp3[mask^sm]+dp2[sm]);
			}
		}
	}
	_P("%.12lf\n",dp3[(1<<N)-1]);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
