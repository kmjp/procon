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

ll N;
int P,C;
int A[6]={2,3,5,7,11,13};
int B[6]={4,6,8,9,10,12};
ll mo=1000000007;

ll dp[2][400][4000];
ll dp2[8000];
ll single[8010];

const int MAT=130;
struct Mat { ll v[MAT][MAT]; };

Mat mulmat(Mat& a,Mat& b,int n=MAT) {
	int x,y,z; Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=0;
	FOR(x,n) FOR(z,n) FOR(y,n) r.v[x][y] += (a.v[x][z]*b.v[z][y]) % mo;
	FOR(x,n) FOR(y,n) r.v[x][y]%=mo;
	return r;
}

Mat powmat(ll p,Mat a,int n=MAT) {
	int i,x,y; Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=0;
	FOR(i,n) r.v[i][i]=1;
	while(p) {
		if(p%2) r=mulmat(r,a,n);
		a=mulmat(a,a,n);
		p>>=1;
	}
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>P>>C;
	dp[0][0][0]=dp[1][0][0]=1;
	
	FOR(x,6) FOR(y,P) FOR(i,y*13+1) if(dp[0][y][i]) (dp[0][y+1][i+A[x]] += dp[0][y][i])%=mo;
	FOR(x,6) FOR(y,C) FOR(i,y*12+1) if(dp[1][y][i]) (dp[1][y+1][i+B[x]] += dp[1][y][i])%=mo;
	FOR(x,651) FOR(y,601) (single[x+y] += dp[0][P][x]*dp[1][C][y])%=mo;
	
	int M=P*13+C*12;
	
	Mat mm;
	ZERO(mm.v);
	FOR(i,M-1) mm.v[i][i+1]=1;
	for(i=1;i<=M;i++) mm.v[M-1][M-i]=single[i];
	
	Mat m2=powmat(N+M-1,mm,M);
	
	ll tot=0;
	FOR(i,M) tot += m2.v[0][i];
	cout<<tot%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
