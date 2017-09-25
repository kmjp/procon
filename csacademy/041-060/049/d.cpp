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

int T,A;
double P[1010][1010];
double dp[1010][1010];
double prob[1010][1010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T>>A;
	FOR(y,T) FOR(x,A) cin>>i, P[y+1][x]=i/100.0;
	
	prob[T][0]=1;
	for(y=T;y>=1;y--) {
		double left=1;
		
		FOR(x,A) {
			if(prob[y][x]) dp[y][x]/=prob[y][x];
			dp[y-1][(x+1)%A] += (1+dp[y][x])*prob[y][x]*(1-P[y][x]);
			dp[y][x+1]   += (1+dp[y][x])*prob[y][x]*P[y][x];
			prob[y-1][(x+1)%A] += prob[y][x]*(1-P[y][x]);
			prob[y][x+1]   += prob[y][x]*P[y][x];
			
			dp[y][x]=prob[y][x]=0;
			left*=P[y][x];
		}
		dp[y][0]=dp[y][A];
		prob[y][0]=prob[y][A];
		
		FOR(x,A) if(prob[y][x]) {
			dp[y][x] /= prob[y][x];
			dp[y-1][(x+1)%A] += (1+A*left/(1-left)+dp[y][x])*prob[y][x]*(1-P[y][x])/(1-left);
			dp[y][x+1]   += (1+dp[y][x])*prob[y][x]*P[y][x];
			prob[y-1][(x+1)%A] += prob[y][x]*(1-P[y][x])/(1-left);
			prob[y][x+1]   += prob[y][x]*P[y][x];
		}
	}
	double ret=0;
	FOR(i,A) ret+=dp[0][i];
	_P("%.12lf\n",ret);
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
