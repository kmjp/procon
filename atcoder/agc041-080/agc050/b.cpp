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

int N;
int A[504];
int dp[505][505];

int hoge(int L,int R) {
	if(L>=R) return 0;
	if(dp[L][R]>-1<<30) return dp[L][R];
	int ret=0;
	for(int M=L+1;M<R;M++) ret=max(ret,hoge(L,M)+hoge(M,R));
	
	for(int M=L+1;M<R-1;M++) {
		if((M-L-1)%3==0&&((R-1)-M-1)%3==0) {
			ret=max(ret,A[L]+A[M]+A[R-1]+hoge(L+1,M)+hoge(M+1,R-1));
		}
	}
	return dp[L][R]=ret;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	FOR(x,N+1) FOR(y,N+1) dp[x][y]=-1<<30;
	cout<<hoge(0,N)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
