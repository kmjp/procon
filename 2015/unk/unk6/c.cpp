#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int X[20],Y[20];
int dp[1<<16];
int mi=64;

int dodo(int mask) {
	int i;
	int L=1010,R=-1010;
	int T=1010,B=-1010;
	FOR(i,N) if(mask&(1<<i)) {
		L=min(L,X[i]);
		R=max(R,X[i]);
		T=min(T,Y[i]);
		B=max(B,Y[i]);
	}
	return min(64, 2*((R-L+1)+(B-T+1)));
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	int mask2;
	
	cin>>N;
	FOR(i,N) cin>>X[i]>>Y[i];
	FOR(i,1<<N) dp[i]=10000;
	dp[0]=0;
	for(int mask=1;mask<1<<N;mask++) {
		dp[mask]=dodo(mask);
		int d=__builtin_popcount(mask);
		if(d<=1) continue;
		
		vector<int> v;
		FOR(i,N) if(mask&(1<<i)) v.push_back(i);
		FOR(mask2,1<<(d-1)) {
			int mask22=0;
			FOR(i,d) if(mask2&(1<<i)) mask22|=1<<v[i];
			dp[mask]=min(dp[mask],dp[mask22] + dp[mask ^ mask22]);
		}
	}
	cout<<dp[(1<<N)-1]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
