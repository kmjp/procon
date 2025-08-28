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

int T;
int N;
pair<ll,ll> P[3030];

ll dp[3030][4];
ll ret[3030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) {
			cin>>x>>y;
			P[i]={x-y,x+y};
		}
		sort(P,P+N);
		FOR(i,N+2) dp[i][0]=dp[i][1]=dp[i][2]=ret[i]=1LL<<60;
		dp[0][0]=0;
		FOR(i,N) {
			ll A=P[i].second,B=P[i].first;
			for(j=N-1;j>=0;j--) FOR(k,3) if(dp[j][k]<1LL<<59) {
				// 1
				if(j==0) {
					chmin(dp[j+1][k+1],dp[j][k]+A-B);
				}
				else if(k==0) {
					chmin(dp[j+1][k+1],dp[j][k]+A+B);
				}
				else {
					chmin(dp[j+1][k+1],dp[j][k]+A-B);
					if(k==1) chmin(ret[j+1],dp[j][k]+A+B);
				}
				// 2
				if(j==0) {
					chmin(dp[j+1][k],dp[j][k]+A*2-2*B);
				}
				else {
					chmin(dp[j+1][k],dp[j][k]+A*2);
					if(k==2) chmin(ret[j+1],dp[j][k]+A*2+2*B);
				}
			}
		}
		for(i=2;i<=N;i++) cout<<ret[i]/2<<" ";
		cout<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
