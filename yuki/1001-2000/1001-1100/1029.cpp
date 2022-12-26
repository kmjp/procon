#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,K;
string S[101];
int C[101];
ll dp[303030];
int cnt[101][3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>S[i]>>C[i];
		FORR(c,S[i]) {
			if(c=='J') cnt[i][0]++;
			if(c=='O') cnt[i][1]++;
			if(c=='I') cnt[i][2]++;
		}
	}
	FOR(i,3*K+1) dp[i]=1LL<<60;
	dp[0]=0;
	priority_queue<pair<ll,int>> Q;
	Q.push({0,0});
	while(Q.size()) {
		ll co=-Q.top().first;
		int cur=Q.top().second;
		Q.pop();
		if(co!=dp[cur]) continue;
		if(cur==3*K) return _P("%lld\n",co);
		
		FOR(i,N) {
			int tar=cur;
			if(K-tar%K>=S[i].size()) {
				tar+=cnt[i][tar/K];
			}
			else {
				FORR(c,S[i]) {
					if(c=='J' && tar<K) tar++;
					if(c=='O' && tar>=K && tar<2*K) tar++;
					if(c=='I' && tar>=2*K&&tar<3*K) tar++;
				}
			}
			if(dp[tar]>co+C[i]) {
				dp[tar]=co+C[i];
				Q.push({-dp[tar],tar});
			}
		}
		
		
	}
	cout<<-1<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
