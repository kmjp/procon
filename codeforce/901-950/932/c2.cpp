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

int T,N,L;
pair<int,int> P[2020];
ll dp[2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>L;
		int ma=0;
		FOR(i,N) {
			cin>>P[i].second>>P[i].first;
			if(P[i].second<=L) ma=1;
		}
		sort(P,P+N);
		
		FOR(i,N+1) dp[i]=1LL<<60;
		dp[0]=0;
		FOR(i,N) {
			for(x=N;x>=0;x--) {
				if(dp[x]+P[i].first+P[i].second<=L) ma=max(ma,x+1);
				if(x==0) dp[x+1]=min(dp[x+1],dp[x]+P[i].second-P[i].first);
				else dp[x+1]=min(dp[x+1],dp[x]+P[i].second);
			}
		}
		cout<<ma<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
