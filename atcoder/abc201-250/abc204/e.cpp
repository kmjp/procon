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
int M;
vector<pair<int,int>> E[101010];
int A[101010],B[101010],C[101010],D[101010];


ll dp[101010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>A[i]>>B[i]>>C[i]>>D[i];
		E[A[i]-1].push_back({B[i]-1,i});
		E[B[i]-1].push_back({A[i]-1,i});
	}
	FOR(i,N) dp[i]=1LL<<60;
	dp[0]=0;
	priority_queue<pair<ll,int>> Q;
	Q.push({0,0});
	while(Q.size()) {
		ll co=-Q.top().first;
		int cur=Q.top().second;
		Q.pop();
		if(dp[cur]!=co) continue;
		if(cur==N-1) {
			cout<<co<<endl;
			return;
		}
		FORR2(e,i,E[cur]) {
			ll to=co+C[i]+D[i]/(co+1);
			
			ll a;
			for(a=co;a<=33000;a+=50) {
				if(a+C[i]+D[i]/(a+1)>to) break;
				to=min(to,a+C[i]+D[i]/(a+1));
			}
			for(ll b=max(co,a-500);b<=a;b++) {
				to=min(to,b+C[i]+D[i]/(b+1));
			}
			if(dp[e]>to) {
				dp[e]=to;
				Q.push({-dp[e],e});
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
