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


const int MAT=105;
long double mat[MAT][MAT],V[MAT],R[MAT];
// M*r+v=0‚Æ‚È‚ér
int Gauss(int n,long double mat_[MAT][MAT],long double v_[MAT],long double r[MAT]) {
	int i,j,k;
	long double mat[MAT][MAT],v[MAT];
	memmove(mat,mat_,sizeof(mat));
	memmove(v,v_,sizeof(v));
	
	FOR(i,n) {
		if(mat[i][i]==0) {
			for(j=i+1;j<n;j++) if(mat[j][i]) break;
			if(j>=n) return -1;
			FOR(k,n) swap(mat[i][k],mat[j][k]);
			swap(v[i],v[k]);
		}
		v[i]/=mat[i][i];
		for(k=n-1;k>=i;k--) mat[i][k]/=mat[i][i];
		for(j=i+1;j<n;j++) {
			v[j]-=v[i]*mat[j][i];
			for(k=n-1;k>=i;k--) mat[j][k]-=mat[i][k]*mat[j][i];
		}
	}
	
	for(i=n-1;i>=0;i--) {
		for(j=n-1;j>i;j--) v[i]-=mat[i][j]*v[j],mat[i][j]=0;
		r[i]=v[i];
	}
	return 0;
}

int N,M;
int C[101010];
long double dp[1010];
long double dp2[1010];

long double dpdp(int cur) {
	if(cur==N-1) return 0;
	if(dp2[cur]>=0) return dp2[cur];
	
	if(cur+M>=N-1) return C[cur];
	
	long double mi=1e20;
	int i;
	for(i=1;i<=M;i++) mi=min(mi,dp[cur+i]);
	
	long double ave=0;
	for(i=1;i<=M;i++) ave+=dpdp(cur+i)/M;
	return dp2[cur]=C[cur]+min(mi,ave);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N-2) cin>>C[i+1];
	FOR(y,N-1) {
		for(x=1;x<=M;x++) {
			if(y+x<N-1) mat[y][y+x]+=1.0/M;
			if(y+x>N-1) mat[y][(N-1)-((y+x)-(N-1))]+=1.0/M;
		}
		mat[y][y]-=1;
		mat[y][N-1]=C[y];
	}
	mat[N-1][N-1]=1;
	V[N-1]=1;
	Gauss(N,mat,V,R);
	FOR(i,N-1) dp[i]=R[i];
	FOR(i,N) dp2[i]=-1;
	_P("%.12lf\n",(double)dpdp(0));
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
