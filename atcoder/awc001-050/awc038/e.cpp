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
ll M,K;
ll P[40];
ll E[40];

ll dp[1<<20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,N) cin>>P[i];
	FOR(i,K) {
		cin>>x>>y;
		x--,y--;
		E[x]|=1LL<<y;
		E[y]|=1LL<<x;
	}
	
	ll ma=0;
	int mask;
	N=20;
	FOR(mask,1<<N) {
		int ok=0;
		ll sum=0;
		FOR(x,N) if(mask&(1<<x)) {
			if(E[x]&mask) {
				sum=-1LL<<60;
				break;
			}
			sum+=P[x];
		}
		dp[mask]=sum;
	}
	FOR(i,N) FOR(mask,1<<N) if(mask&(1<<i)) dp[mask^(1<<i)]=max(dp[mask^(1<<i)],dp[mask]);
	FOR(mask,1<<N) {
		int ok=0;
		ll sum=0;
		ll okmask=(1<<N)-1;
		FOR(x,N) if(mask&(1<<x)) {
			okmask&=~E[x+N];
			if((E[x+N]>>N)&mask) {
				sum=-1LL<<60;
				break;
			}
			sum+=P[x+N];
		}
		ma=max(ma,dp[okmask]+sum);
	}
	

	
	
	cout<<min(ma,M)<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
