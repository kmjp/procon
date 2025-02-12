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

int N,M,S;
int A[20];
int ng[20];
int ok[1<<20];
int dp[1<<20];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>S;
	FOR(i,N) cin>>A[i];
	FOR(i,M) {
		cin>>x>>y;
		x--,y--;
		ng[x]|=1<<y;
		ng[y]|=1<<x;
	}
	int mask;
	FOR(mask,1<<N) if(mask) {
		int sum=0;
		int tb=0;
		FOR(i,N) if(mask&(1<<i)) {
			sum+=A[i];
			tb=1<<i;
			if(mask&ng[i]) sum=S+1;
		}
		dp[mask]=1<<20;
		if(sum<=S) {
			dp[mask]=ok[mask]=1;
		}
		else {
			
			for(int sm=(mask-1)&mask;sm>=tb;sm=(sm-1)&mask) {
				if(ok[sm]) chmin(dp[mask],1+dp[mask^sm]);
			}
		}
	}
	cout<<dp[(1<<N)-1]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
