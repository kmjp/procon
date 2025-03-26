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
ll mo;

ll memo[505][505];
ll memo2[505][505];

ll G(int N,int M);
ll F(int N,int M) {  // left most‚ª––”ö‚Ü‚Ås‚­
	if(N==1) return 1;
	if(M==0) return 0;
	if(memo[N][M]>=0) return memo[N][M];
	__int128 ret=F(N,M-1);
	
	int x,y;
	for(x=0;x<=M;x++) if(x*2>M) (ret+=F(N-1,x)*G(N-1,M-x));
	
	return memo[N][M]=ret%mo;
	
}

ll G(int N,int M) {  // ––”ö‚Ü‚Ås‚©‚È‚¢
	if(N==1||M==0) return 1;
	if(memo2[N][M]>=0) return memo2[N][M];
	__int128 ret=G(N,M-1);
	
	int x,y;
	for(x=0;x<=M;x++) (ret+=G(N-1,x)*G(N-1,M-x));
	
	return memo2[N][M]=ret%mo;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>T;
	while(T--) {
		cin>>N>>K>>mo;
		MINUS(memo);
		MINUS(memo2);
		ll ret=F(N,K);
		FOR(i,N-1) ret=ret*2%mo;
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
