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
int V[101010];
int A[101010];

int S[1<<20];
ll dp[1<<20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	ll sum=0;
	FOR(i,N) {
		cin>>V[i];
		sum+=V[i];
	}
	FOR(i,N) {
		cin>>s;
		FOR(j,M) if(s[j]=='o') A[i]|=1<<j;
		S[((1<<M)-1)^A[i]]+=V[i];
	}
	FOR(i,M) {
		FOR(j,1<<M) if(j&(1<<i)) S[j^(1<<i)]+=S[j];
	}
	FOR(j,1<<M) S[j]=sum-S[j];
	
	int mask;
	FOR(mask,1<<M) if(mask) {
		FOR(i,M) if(mask&(1<<i)) {
			ll a=S[mask]-S[mask^(1<<i)];
			dp[mask]=max(dp[mask],dp[mask^(1<<i)]+a*a);
		}
	}
	
	cout<<dp[(1<<M)-1]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
