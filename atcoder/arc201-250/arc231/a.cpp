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

int T,N;
ll X[252525],Y[252525],Z[252525];

ll dp[505][505];
ll Yma[505][505];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		
		FOR(y,500) {
			FOR(x,500) dp[y][x]=-1LL<<60;
		}
		dp[0][0]=0;
		FOR(y,500) {
			FOR(x,500) {
				Yma[y][x]=-1LL<<60;
				FOR(k,500) Yma[y][x]=max(Yma[y][x],dp[y][k]-(x-k)*(x-k));
			}
		}
		
		ll sum=0;
		FOR(i,N) {
			cin>>X[i]>>Y[i]>>Z[i];
			sum+=Z[i];
			ll tma=-1LL<<60;
			FOR(y,500) tma=max(tma,Z[i]+Yma[y][X[i]]-(y-Y[i])*(y-Y[i]));
			y=Y[i];
			dp[Y[i]][X[i]]=tma;
			FOR(x,500) {
				Yma[y][x]=max(Yma[y][x],dp[y][X[i]]-(x-X[i])*(x-X[i]));
			}
		}
		ll mi=sum;
		FOR(y,500) FOR(x,500) mi=min(mi,sum-dp[y][x]);
		cout<<mi<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
