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

int N,A[404];
int dp[404][404][404];

int hoge(int L,int R,int C) {
	L=max(0,L);
	R=min(N+1,R);
	if(dp[L][R][C]>=0) return dp[L][R][C];
	if(L==0&&R==N+1) return 0;
	
	int ret=0;
	
	if(C) {
		if(L>0) ret=max(ret,A[L]+hoge(L-1,R,C-1));
		if(R<N+1) ret=max(ret,A[R]+hoge(L,R+1,C-1));
	}
	
	
	if(L==0) ret=max(ret,hoge(L,R+1,C+1));
	else if(R==N+1) ret=max(ret,hoge(L-1,R,C+1));
	else {
		if(A[L]>A[R]) {
			ret=max(ret,hoge(L-1,R,C+1));
		}
		else{
			ret=max(ret,hoge(L,R+1,C+1));
		}
	}
	
	return dp[L][R][C]=ret;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(dp);
	cin>>N;
	FOR(i,N) cin>>A[i+1];
	
	FOR(i,N+1) {
		cout<<hoge(i,i+1,1)<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
