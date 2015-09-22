#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
ll X[303],Y[303];
double ret=1e11;
pair<double,pair<int,int>> P[202];

double dp[301];

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	cin>>N;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		P[i]={atan2(Y[i],X[i]),{X[i],Y[i]}};
	}
	sort(P,P+N);
	FOR(i,N) X[i]=P[i].second.first,Y[i]=P[i].second.second;
	
	FOR(i,N) {
		FOR(x,N+1) dp[x]=1e11;
		dp[0]=0;
		for(y=1;y<=N;y++) {
			FOR(x,y) {
				ll a=(X[(x+i)%N]*Y[(y+i)%N]-X[(y+i)%N]*Y[(x+i)%N]);
				if(a>0) dp[y]=min(dp[y],dp[x]+a/2.0);
			}
		}
		ret=min(ret,dp[N]);
	}
	
	if(ret==1e11) _P("Impossible\n");
	else _P("Possible\n%.12lf\n",ret);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
