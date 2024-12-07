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

int T,N,M;
ll H;
ll L[101010],S[101010];
ll dp[101010];
vector<int> E[101010];

template<class V> V ext_gcd(V p,V q,V& x, V& y) { // get px+qy=gcd(p,q)
	if(q==0) return x=1,y=0,p;
	V g=ext_gcd(q,p%q,y,x);
	y-=p/q*x;
	return g;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M>>H;
		FOR(i,N) {
			cin>>L[i];
			E[i].clear();
			dp[i]=1LL<<60;
		}
		FOR(i,N) cin>>S[i];
		FOR(i,M) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		priority_queue<pair<ll,int>> Q;
		dp[0]=0;
		Q.push({0,0});
		while(Q.size()) {
			ll co=-Q.top().first;
			int cur=Q.top().second;
			Q.pop();
			if(dp[cur]!=co) continue;
			FORR(e,E[cur]) {
				ll dy=(L[e]-L[cur]+H)%H;
				ll dx=(S[cur]-S[e]+H)%H;
				if(dx==0) {
					if(dy) continue;
					if(chmin(dp[e],dp[cur]+1)) Q.push({-dp[e],e});
					continue;
				}
				ll x,y;
				ll g=ext_gcd(H,dx,x,y);
				if(dy%g) continue;
				y*=dy/g;
				ll a=H/g;
				y%=a;
				if(y<dp[cur]) y+=(dp[cur]-y)/a*a;
				if(y<dp[cur]) y+=a;
				if(chmin(dp[e],y+1)) Q.push({-dp[e],e});
			}
		}
		if(dp[N-1]==1LL<<60) dp[N-1]=-1;
		cout<<dp[N-1]<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
