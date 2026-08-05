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

int H,W,SY,SX,GY,GX;
ll K;
ll E[16][16];
ll dp[16][1<<16][16];
ll dp2[16][16];
const ll mo=998244353;

const int MAT=16;
struct Mat { ll v[MAT][MAT]; Mat(){ZERO(v);};};

Mat mulmat(Mat& a,Mat& b,int n=MAT) {
	ll mo2=4*mo*mo;
	int x,y,z; Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=0;
	FOR(x,n) FOR(z,n) FOR(y,n) {
		r.v[x][y] += a.v[x][z]*b.v[z][y];
		if(r.v[x][y]>mo2) r.v[x][y] -= mo2;
	}
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
	
	cin>>H>>W>>SY>>SX>>GY>>GX>>K;
	FOR(y,H) FOR(x,W) FOR(i,H) FOR(j,W) {
		if(i==y&&j==x) continue;
		if(i==y||x==j||y+x==i+j||y-x==i-j) E[y*W+x][i*W+j]=1;
	}
	int N=H*W;
	int mask;
	Mat A;
	FOR(i,N) {
		dp[i][0][i]=1;
		FOR(mask,1<<N) FOR(x,N) FOR(y,N) if((mask&(1<<y))==0&&E[x][y]) (dp[i][mask|(1<<y)][y]+=dp[i][mask][x])%=mo;
		FOR(x,N) A.v[i][x]=dp[i][(1<<N)-1][x];
	}
	A=powmat(K/N,A,N);
	ll ret=0;
	x=(SY-1)*W+SX-1;
	y=(GY-1)*W+GX-1;
	FOR(mask,1<<N) if(__builtin_popcount(mask)==(K)%N) {
		FOR(j,N) {
			(ret+=A.v[x][j]*dp[j][mask][y])%=mo;
		}
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
