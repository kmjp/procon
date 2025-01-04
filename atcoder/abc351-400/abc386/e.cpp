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
ll A[202020];

ll ma=0;
ll sum=0;
void dfs(int cur,int K,ll v) {
	if(K==0) {
		ma=max(ma,sum^v);
		return;
	}
	if(cur>=N) return;
	for(int i=cur;i<N;i++) dfs(i+1,K-1,v^A[i]);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	
	FOR(i,N) cin>>A[i];
	if(K*2>N) {
		K=N-K;
		FOR(i,N) sum=sum^A[i];
	}
	dfs(0,K,0);
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
