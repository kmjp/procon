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

int N,M,K;
vector<pair<int,int>> E[1010];
int T[1010],C[1010];

ll dp[1010][1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,M) {
		cin>>x>>y>>k;
		E[x-1].push_back({y-1,k});
		E[y-1].push_back({x-1,k});
	}
	priority_queue<pair<ll,int>> Q;
	
	FOR(i,K) {
		cin>>C[i]>>T[i];
		C[i]--;
		Q.push({-T[i],(1<<20)+C[i]});
	}
	FOR(i,1005) FOR(j,1005) dp[i][j]=1LL<<60;
	dp[0][0]=0;
	Q.push({0,0});
	int ma=0;
	while(Q.size()) {
		ll co=-Q.top().first;
		ll a=Q.top().second;
		Q.pop();
		if(a>=1<<20) {
			a=a-(1<<20);
			int tar=-1;
			FOR(i,K+1) if(dp[a][i]<=co) tar=i;
			if(tar>=0) {
				dp[a][tar+1]=co;
				Q.push({-co,a*1010+(tar+1)});
			}
		}
		else {
			int cur=a/1010;
			int step=a%1010;
			ma=max(ma,step);
			if(dp[cur][step]!=co) continue;
			FORR2(e,c,E[cur]) if(chmin(dp[e][step],co+c)) Q.push({-dp[e][step],e*1010+step});
		}
		
	}
		
	cout<<ma<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
