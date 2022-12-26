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

int N;
int A[1010];
ll mo=998244353;
ll dp[1010][1010];

const int NUM_=400001;
ll inv[NUM_+1];
ll combi(ll N, ll C_) {
	static const int N_=1020;
	static ll C[N_][N_];
	int i,j;
	if (fact[0]==0) {
		inv[1]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		
		FOR(i,N_) C[i][0]=C[i][i]=1;
		for(i=1;i<N_;i++) for(j=1;j<i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mo;
	}
	if(C_<0 || C_>N) return 0;
	return C[N][C_];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	combi(1,1);
	
	cin>>N;
	FOR(i,N) cin>>x, A[x]++;
	
	dp[1001][0]=1;
	for(i=1000;i>=1;i--) {
		for(j=0;j<=1000;j++) if(dp[i+1][j]) {
			x=j+A[i];
			
			ll pat=dp[i+1][j];
			int left=x;
			for(y=0;y*i<=x;y++) {
				(dp[i][x-y*i]+=pat)%=mo;
				if(left>=i) {
					pat=pat*combi(left,i)%mo*inv[y+1]%mo;
					left-=i;
				}
			}
		}
	}
	
	cout<<dp[1][0]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
