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
int A[20];
ll dp1[17][1<<16];
ll dp3[17][1<<16];
ll mo=1000000007;
const int NUM_=1<<17;
ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	cin>>N>>M;
	
	
	A[0]=1;
	dp1[0][0]=1;
	int mask,U;
	for(i=1;i<=M;i++) {
		cin>>A[i];
		FOR(j,N) FOR(mask,1<<N) if((mask&(1<<j))) (dp1[i-1][mask]+=dp1[i-1][mask^(1<<j)])%=mo;
		FOR(U,1<<N) {
			int t=U-(A[i-1]-1);
			int d=A[i]-A[i-1]-1;
			if(t>=d) dp3[i][U]=fact[t]*factr[t-d]%mo*dp1[i-1][U]%mo;
		}
		
		FOR(j,N) FOR(mask,1<<N) if((mask&(1<<j))) (dp3[i][mask]+=mo-dp3[i][mask^(1<<j)])%=mo;
		FOR(U,1<<N) if(U>=(A[i]-2)) dp1[i][U]=(U-(A[i]-2))*dp3[i][U]%mo;
		
	}
	
	ll ret=0;
	FOR(mask,1<<N) ret+=dp1[M][mask];
	ret=ret%mo*fact[(1<<N)-A[M]]%mo*(1LL<<N)%mo;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
