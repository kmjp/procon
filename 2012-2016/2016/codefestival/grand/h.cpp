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

int N,R;

const int MAT=402;
int mat[402][402];
ll dp[303][303][303];
ll p2[101010];
ll mo=1000000007;

int gf2_rank(int A[MAT][MAT],int n) { /* input */
	int i,j,k;
	FOR(i,n) {
		int be=i,mi=n+1;
		for(j=i;j<n;j++) {
			FOR(k,n) if(A[j][k]) break;
			if(k<mi) be=j,mi=k;
		}
		if(mi>=n) break;
		FOR(j,n) swap(A[i][j],A[be][j]);
		
		FOR(j,n) if(i!=j&&A[j][mi]) {
			FOR(k,n) A[j][k] ^= A[i][k];
		}
	}
	return i;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p2[0]=1;
	FOR(i,101000) p2[i+1]=p2[i]*2%mo;
	
	cin>>N;
	FOR(y,N) FOR(x,N) cin>>mat[y][x];
	R=gf2_rank(mat,N);
	dp[0][0][0]=1;
	FOR(i,N) {
		FOR(x,R+1) FOR(y,N-R+1) if(dp[i][x][y]) {
			ll v=dp[i][x][y]*p2[x+y]%mo;
			// no new rank
			(dp[i+1][x][y]+=v)%=mo;
			// common rank
			if(x<R) (dp[i+1][x+1][y]+=v*(p2[R-x]+mo-1))%=mo;
			// single rank
			if(y<N-R) (dp[i+1][x][y+1]+=v*(p2[N-x-y]-p2[R-x]+mo))%=mo;
		}
	}
	
	//FOR(x,R+1) FOR(y,N-R+1) cout<<x<<" "<<y<<" "<<dp[N][x][y]<<endl;
	
	ll ret=0;
	FOR(y,N-R+1) (ret+=dp[N][R][y]*p2[N*(N-R-y)])%=mo;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
