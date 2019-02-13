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

int H,W;
int A[51];
int S[51];
int BS[51];

ll dp[41][1701];
ll mo=1000000007;

ll comb(ll N_, ll C_) {
	const int NUM_=400001;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(i,W) cin>>A[i];
	sort(A,A+W);
	FOR(i,W) S[i+1]=S[i]+A[i];
	
	FOR(i,H+1) FOR(j,W+1) BS[i]=max(BS[i],S[W]-(S[j]+(W-j)*(H-i)));
	if(BS[0]>0) return _P("\n");
	
	dp[0][0]=1;
	for(int p=0;p<=W;p++) {
		for(x=H;x>=0;x--) for(y=S[W];y>=0;y--) if(dp[x][y]) {
			// put z ps
			for(int z=1;x+z<=H && y+z*p<=S[W];z++) {
				if(y+z*p>=BS[x+z]) {
					(dp[x+z][y+z*p]+=dp[x][y]*comb(H-x,z))%=mo;
				}
			}
		}
	}
	
	cout<<dp[H][S[W]]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
