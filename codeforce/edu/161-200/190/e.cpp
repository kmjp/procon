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
int P[202020],C[202020];
int MPC[1<<20];
int MCP[1<<20];

int A[402020],B[402020],D[402020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,1<<20) MPC[i]=MCP[i]=1<<30;
	
	cin>>N;
	FOR(i,N) cin>>P[i];
	FOR(i,N) cin>>C[i];
	int mi=1<<30;
	FOR(i,N) {
		mi=min(mi,P[i]+C[i]);
		chmin(MPC[P[i]+1],C[i]);
		chmin(MCP[C[i]+1],P[i]);
	}
	FOR(i,(1<<20)-1) {
		chmin(MPC[i+1],MPC[i]);
		chmin(MCP[i+1],MCP[i]);
	}
	
	cin>>M;
	FOR(i,M) cin>>A[i];
	FOR(i,M) cin>>B[i];
	FOR(i,M) cin>>D[i];
	FOR(i,M) {
		int a=A[i],b=B[i],d=D[i];
		int ret=mi;
		//b‚É‘Î‚µa‚Ì‰e‹¿‚ª0
		if(MPC[a]<b) ret=0;
		//•Ð•û‚ª0‚É—}‚¦‚ç‚ê‚éê‡
		if(MPC[a]<1<<30) ret=min(ret,min(MPC[a],b+d));
		if(MCP[b]<1<<30) ret=min(ret,min(MCP[b],a+d));
		ret=min(ret,a+d+MPC[1010101]);
		ret=min(ret,b+d+MCP[1010101]);
		cout<<ret<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
