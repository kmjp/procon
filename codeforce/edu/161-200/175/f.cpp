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

int N,M;
int C[1<<20];
int P[505050];
int X[22];
ll tot[1<<20];
int num_odd[1<<20];
int odd_mask;
ll A[21][1<<20];
ll B[21][1<<20];
ll ret[1<<20];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>s;
		x=0;
		FORR(c,s) x|=1<<(c-'A');
		C[x]++;
	}
	FOR(i,N) {
		cin>>X[i];
		if(X[i]%2) odd_mask |= 1<<i;
	}
	int mask;
	FOR(mask,1<<N) {
		FOR(i,N) if(mask&(1<<i)) {
			tot[mask]+=X[i];
			if(X[i]%2) num_odd[mask]++;
		}
		A[num_odd[mask]][mask]=C[mask];
	}
	int sum=tot[(1<<N)-1];
	
	// ‚‘¬zeta
	FOR(i,N+1) FOR(j,N+1) FOR(mask,1<<N) if(mask&(1<<j)) A[i][mask]+=A[i][mask^(1<<j)];
	// convolution
	FOR(x,N+1) for(y=0;x+y<=N;y++) FOR(mask,1<<N) B[x+y][mask] += A[x][mask]*A[y][mask];
	// ‚‘¬ƒƒrƒEƒX
	FOR(i,N+1) FOR(j,N+1) FOR(mask,1<<N) if(mask&(1<<j)) B[i][mask]-=B[i][mask^(1<<j)];
	
	FOR(mask,1<<N) ret[tot[mask]]+=B[num_odd[mask]][mask];
	// i==j‚Ìê‡‚ðˆø‚­
	FOR(mask,1<<N) if((mask&odd_mask)==0) ret[tot[mask]]-=C[mask];
	FOR(i,sum+1) cout<<ret[sum-i]/2<<" ";
	cout<<endl;

}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
