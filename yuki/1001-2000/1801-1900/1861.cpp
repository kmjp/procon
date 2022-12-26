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

int N,K;
ll A[101010];
bitset<1024> L[10101],R[10101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>A[i+1];
	L[0][0]=1,R[N+1][0]=1;
	for(i=1;i<=N;i++) L[i]=L[i-1]|(L[i-1]<<A[i]);
	for(i=N;i>=1;i--) R[i]=R[i+1]|(R[i+1]<<A[i]);
	int ret=0;
	for(i=1;i<=N;i++) {
		x=y=0;
		FOR(j,K+1) if(L[i-1][j]&&R[i+1][K-j]) x=1;
		FOR(j,K-A[i]+1) if(L[i-1][j]&&R[i+1][K-A[i]-j]) y=1;
		if(x==0&&y==1) ret++;
	}
	if(L[N][K]==0) {
		cout<<-1<<endl;
	}
	else {
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
