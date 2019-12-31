#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int H,N,W;
ll mo=1000000007;
ll memo[70][3000];


ll rev(ll a) {
	ll r=1, n=mo-2;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll comb(int P_,int Q_) {
	static const int N_=2520;
	static ll C_[N_][N_];
	
	if(C_[0][0]==0) {
		int i,j;
		FOR(i,N_) C_[i][0]=C_[i][i]=1;
		for(i=1;i<N_;i++) for(j=1;j<i;j++) C_[i][j]=(C_[i-1][j-1]+C_[i-1][j])%mo;
	}
	if(P_<0 || P_>N_ || Q_<0 || Q_>P_) return 0;
	return C_[P_][Q_];
}

ll dodo(int h,int w) {
	if(h<=0) return w==0;
	if(memo[h][w]>=0) return memo[h][w];
	int i;
	ll& ret=memo[h][w];
	ret=0;
	FOR(i,min(N,w)+1) ret+=comb(w,i)*dodo(h-1,w-i)%mo;
	return ret%=mo;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(memo);
	cin>>H>>N>>W;
	
	ll ret=dodo(H,W);
	cout << ret*(H-1)%mo*rev(H)%mo << endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
