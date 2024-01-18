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

int T,N,K;
int A[402020],B[402020];
ll S[402020];
int nex[404040][20];
ll C[404040][20];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&N,&K);
		FOR(i,N) scanf("%d",&A[i]);
		FOR(i,N) scanf("%d",&B[i]);
		FOR(i,N) {
			A[i+N]=A[i];
			B[i+N]=B[i];
		}
		FOR(i,2*N) S[i+1]=S[i]+A[i%N];
		nex[2*N][0]=2*N;
		int n=2*N;
		for(i=2*N-1;i>=0;i--) {
			nex[i][0]=n;
			if(B[i]==1) n=i;
		}
		if(nex[0][0]>N) {
			ll a=S[N]*2;
			FOR(i,N) _P("%lld ",a);
			_P("\n");
			continue;
		}
		FOR(i,N) {
			C[i][0]=C[i+N][0]=max(0LL,S[nex[i][0]]-S[i]-K);
			nex[i+N][0]=nex[i][0]+N;
		}
		FOR(j,18) {
			FOR(i,N) {
				nex[i][j+1]=(nex[i][j]>=2*N?2*N:nex[nex[i][j]][j]);
				nex[i+N][j+1]=min(nex[i][j+1]+N,2*N);
				C[i][j+1]=C[i+N][j+1]=C[i][j]+C[nex[i][j]][j];
			}
			nex[2*N][j+1]=2*N;
		}
		FOR(i,N) {
			ll sum;
			if(B[i]==1) {
				x=i;
				sum=S[N];
			}
			else {
				x=nex[i][0];
				sum=S[N]+S[x]-S[i];
			}
			for(j=18;j>=0;j--) if(nex[x][j]<=i+N) {
				sum+=C[x][j];
				x=nex[x][j];
			}
			sum+=max(0LL,S[i+N]-S[x]-K);
			_P("%lld ",sum);
		}
		_P("\n");
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
