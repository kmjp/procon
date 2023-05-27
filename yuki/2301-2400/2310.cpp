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

int N,Q;
int X[500][500];
ll S[500][500];
const ll mo=998244353;
ll Y[35][35];
ll dp[55];
int K;
int A[55],B[55],C[55];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	N++;
	FOR(y,N) FOR(x,N) cin>>X[y][x];
	FOR(i,N) {
		S[i][i]=1;
		FOR(x,N) FOR(y,N) (S[i][y]+=S[i][x]*X[x][y])%=mo;
	}
	cin>>Q;
	while(Q--) {
		cin>>K;
		FOR(i,K) {
			cin>>A[i]>>B[i]>>C[i];
		}
		FOR(x,K) FOR(y,K-1) if(A[y]>A[y+1]) {
			swap(A[y],A[y+1]);
			swap(B[y],B[y+1]);
			swap(C[y],C[y+1]);
		}
		ZERO(Y);
		Y[0][K+1]=S[0][N-1];
		FOR(i,K) {
			Y[0][i+1]=S[0][A[i]];
			Y[i+1][K+1]=C[i]*S[B[i]][N-1]%mo;
			FOR(x,K) {
				Y[i+1][x+1]=C[i]*S[B[i]][A[x]]%mo;
			}
		}
		ZERO(dp);
		dp[0]=1;
		FOR(i,K+2) {
			for(x=i+1;x<K+2;x++) (dp[x]+=dp[i]*Y[i][x])%=mo;
		}
		cout<<dp[K+1]<<endl;
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
