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
int A[101010];
double dp[101010];
int ave(double v) {
	dp[0]=0;
	dp[1]=A[0]-v;
	int i;
	for(i=2;i<=N;i++) {
		dp[i]=max(dp[i-2],dp[i-1])+A[i-1]-v;
	}
	return dp[N]>=0||dp[N-1]>=0;
}

int med(int v) {
	dp[0]=0;
	dp[1]=(A[0]>=v)?1:-1;
	int i;
	for(i=2;i<=N;i++) {
		dp[i]=max(dp[i-2],dp[i-1])+((A[i-1]>=v)?1:-1);
	}
	return dp[N]>=1||dp[N-1]>=1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	
	double L=0,R=1e9;
	FOR(i,100) {
		double M=(L+R)/2;
		if(ave(M)) L=M;
		else R=M;
	}
	_P("%.12lf\n",L);
	int ret=0;
	for(i=29;i>=0;i--) if(med(ret+(1<<i))) ret+=1<<i;
	_P("%d\n",ret);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
