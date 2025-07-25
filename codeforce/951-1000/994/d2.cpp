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


int T,H,W,K;
ll A[205];
ll from[205];
ll to[205];
ll dp[205];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W>>K;
		FOR(x,W) from[x]=1LL<<60;
		from[0]=0;
		FOR(y,H) {
			FOR(x,W) to[x]=1LL<<60;
			FOR(x,W) cin>>A[x];
			FOR(i,W) {
				FOR(x,W) dp[x]=from[x]+(1LL*i*K)+A[x];
				FOR(x,W-1) dp[x+1]=min(dp[x+1],dp[x]+A[x+1]);
				FOR(x,W) to[x]=min(to[x],dp[x]);
				rotate(A,A+1,A+W);
			}
			swap(from,to);
		}
		cout<<from[W-1]<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
