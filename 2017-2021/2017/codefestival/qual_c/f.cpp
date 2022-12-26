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
int A[404],B[404];
ll G[404][404];
ll mo=1000000007;
ll F[404][404];
ll H[404][404][144];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	M=N/3;
	FOR(i,N) cin>>A[i], A[i]--;
	FOR(i,N) cin>>B[i], B[i]--;
	
	G[0][0]=1;
	FOR(i,M) {
		FOR(j,N) G[i+1][j+2]=G[i][j];
		for(j=N;j>0;j--) if(G[i+1][j]) (G[i+1][j-1]+=G[i+1][j]*j)%=mo;
	}
	
	FOR(x,N+1) FOR(y,N+1) F[x][y]=101010;
	for(x=1;x<=N;x++) {
		int cnt[404]={};
		int num=x;
		FOR(i,x) cnt[A[i]]=1;
		for(y=1;y<=N;y++) {
			if(B[y-1]==A[x-1]) break;
			if(cnt[B[y-1]]==1) continue;
			num++;
			cnt[B[y-1]]=1;
			F[x][y]=num;
		}
	}
	
	FOR(x,N+1) FOR(y,N+1) H[x][y][0]=1;
	for(int t=1;t<=M;t++) {
		for(x=1;x<=N;x++) for(y=1;y<=N;y++) {
			ll cur=max(0LL,3*t-F[x][y]);
			H[x][y][t]=(cur*H[x-1][y-1][t-1] + H[x-1][y][t] + H[x][y-1][t] - H[x-1][y-1][t] + mo)%mo;
		}
	}
	
	cout<<H[N][N][M]*G[M][0]%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
