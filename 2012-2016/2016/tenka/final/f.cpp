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

int N,G;
int P[36];

const int CN=40;
double C[CN][CN];
ll dp[37][37][37*37];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,CN) for(j=0;j<=i;j++) C[i][j]=(j==0||j==i)?1:(C[i-1][j-1]+C[i-1][j]);
	
	cin>>N>>G;
	int sum=0;
	FOR(i,N) cin>>P[i], sum+=P[i];
	if(sum<=N*G) return _P("%d\n",sum);
	
	double ret=0;
	FOR(i,N) {
		ZERO(dp);
		dp[0][0][0]=1;
		FOR(j,N) FOR(x,N) FOR(y,36*36) if(dp[j][x][y]) {
			dp[j+1][x][y]+=dp[j][x][y];
			if(j!=i) dp[j+1][x+1][y+P[j]]+=dp[j][x][y];
		}
		
		double cost=0;
		FOR(x,N) {
			cost+=1.0*G*N/(N-x);
			FOR(y,37*37) if(dp[N][x][y] && y<sum-N*G && y+P[i]>=sum-N*G) {
				ret+=(cost+(sum-y-P[i]))*(dp[N][x][y]/C[N][x+1]/(x+1));
			}
		}
	}
	_P("%.12lf\n",ret);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
