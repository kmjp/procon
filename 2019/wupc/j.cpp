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

int N,M;
int A[2020];
int mo=1000000007;

ll dp[2020][2020];
const int NUM_=400001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
ll comb[2020][2020];
ll perm[2020][2020];

ll L[2020],F[2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	FOR(i,2010) FOR(j,i+1) {
		perm[i][j]=fact[i]*factr[i-j]%mo;
		comb[i][j]=perm[i][j]*factr[j]%mo;
	}
	
	dp[0][0]=1;
	int sum=0,f;
	FOR(i,N) {
		cin>>A[i];
		FOR(x,sum+1) if(dp[x][sum-x]) {
			dp[x][sum-x]%=mo;
			FOR(l,min(A[i],sum-x)+1) L[l]=perm[A[i]][l]*comb[sum-x][l]%mo;
			FOR(l,min(A[i],sum-x)+1) {
				FOR(f,min(A[i],sum-x)+1) {
					if(sum-x+A[i]-(f+l)<=M-(sum+A[i])) (dp[x+l+f][sum-x+A[i]-(f+l)]+=dp[x][sum-x]*L[l]%mo*L[f])%=mo;
				}
			}
		}
		sum+=A[i];
	}
	ll ret=dp[M][0];
	FOR(i,N) ret=ret*factr[A[i]]%mo;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
