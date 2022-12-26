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

ll mo=1000000007;
int N,X;
int S[202];
ll memo[201][101010];
ll fact[202];

ll comb(int P_,int Q_) {
	static const int N_=1020;
	static ll C_[N_][N_];
	
	if(C_[0][0]==0) {
		int i,j;
		FOR(i,N_) C_[i][0]=C_[i][i]=1;
		for(i=1;i<N_;i++) for(j=1;j<i;j++) C_[i][j]=(C_[i-1][j-1]+C_[i-1][j])%mo;
	}
	if(P_<0 || P_>N_ || Q_<0 || Q_>P_) return 0;
	return C_[P_][Q_];
}

ll dp(int c,int x) {
	if(c==N) return x;
	if(x<S[N-1]) return fact[N-c]*x%mo;
	if(memo[c][x]>=0) return memo[c][x];
	
	int num=0,el=0;
	int i;
	for(i=c;i<N;i++) if(S[i]>x) num++;
	
	ll ret=0;
	
	for(i=c;i<N;i++) if(S[i]<=x) {
		ret+=comb(N-c-num-1,el)*fact[el]%mo*dp(i+1,x%S[i])%mo;
		el++;
	}
	
	ret%=mo;
	ll pat=comb(N-c,num)*fact[num]%mo;
	return memo[c][x]=ret*pat%mo;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	fact[0]=1;
	for(i=1;i<=201;i++) fact[i]=fact[i-1]*i%mo;
	
	cin>>N>>X;
	FOR(i,N) cin>>S[i];
	MINUS(memo);
	sort(S,S+N);
	reverse(S,S+N);
	
	cout<<dp(0,X)<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
