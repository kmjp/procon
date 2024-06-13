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

int T,N,H[202020],A[202020];

ll ret[202020];
pair<pair<int,int>,pair<int,int>> dp[18][505050];

ll turn(int s,int i) {
	if(i<0) return 0;
	return 1LL*(A[i]+s-1)/s*H[i];
}

pair<pair<int,int>,pair<int,int>> merge(pair<pair<int,int>,pair<int,int>> L,pair<pair<int,int>,pair<int,int>> R) {
	if(L.first==R.first) R.first={0,0};
	if(L.first==R.second) R.second={0,0};
	if(L.second==R.first) R.first={0,0};
	if(L.second==R.second) R.second={0,0};
	if(R.first>L.first) swap(R.first,L.first);
	if(R.first>L.second) swap(R.first,L.second);
	if(R.second>L.second) swap(R.second,L.second);
	return L;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		ZERO(dp);
		
		cin>>N;
		FOR(i,N) cin>>H[i+1];
		FOR(i,N) cin>>A[i+1];
		
		FOR(i,N) {
			ret[i+1]=0;
			pair<int,int> p={H[i+1],i+1};
			if(p>dp[0][A[i+1]].first) swap(dp[0][A[i+1]].first,p);
			if(p>dp[0][A[i+1]].second) swap(dp[0][A[i+1]].second,p);
		}
		
		FOR(i,17) {
			FOR(j,500000) {
				if(j+(1<<i)<=500000) dp[i+1][j]=merge(dp[i][j],dp[i][j+(1<<i)]);
				else dp[i+1][j]=dp[i][j];
			}
		}
		
		
		x=0;
		for(i=1;i<=200000;i++) {
			while(1<<(x+1)<=i) x++;
			
			pair<ll,int> ma={};
			pair<ll,int> ma2={};
			
			for(j=1;j<=200000;j+=i) {
				auto C=merge(dp[x][j],dp[x][j+i-(1<<x)]);
				pair<ll,int> a={turn(i,C.first.second),C.first.second};
				pair<ll,int> b={turn(i,C.second.second),C.second.second};
				if(a>ma) swap(a,ma);
				if(a>ma2) swap(ma2,a);
				if(b>ma2) swap(b,ma2);
			}
			chmax(ret[ma.second],ma.first-ma2.first);
		}
		
		FOR(i,N) _P("%lld ",ret[i+1]);
		_P("\n");
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
