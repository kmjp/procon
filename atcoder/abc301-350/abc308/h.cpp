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
ll E[303][303];

ll dp[303];
int L[303],pre[3030];

vector<ll> hoge(int i) {
	int j,e;
	FOR(j,N) dp[j]=1LL<<30, L[j]=-1, pre[j]=-1;
	priority_queue<pair<ll,int>> Q;
	dp[i]=0;
	L[i]=i;
	pre[i]=i;
	Q.push({0,i});
	while(Q.size()) {
		ll co=-Q.top().first;
		int cur=Q.top().second;
		Q.pop();
		if(dp[cur]!=co) continue;
		FOR(e,N) if(dp[e]>co+E[cur][e]) {
			dp[e]=co+E[cur][e];
			pre[e]=cur;
			if(cur==i) L[e]=e;
			else L[e]=L[cur];
			Q.push({-dp[e],e});
		}
	}

	int ta=-1,tb=-1;
	ll mco=1LL<<30;
	int a,b;
	FOR(a,N) if(i!=a&&dp[a]<1LL<<30) {
		FOR(b,N) if(L[a]!=L[b]) {
			if(pre[a]==b||pre[b]==a) continue;
			ll co=dp[a]+dp[b]+E[a][b];
			if(co<mco) {
				mco=co;
				ta=a;
				tb=b;
			}
		}
	}
	return {mco,ta,tb};
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N>>M;
	FOR(x,N) FOR(y,N) E[x][y]=1LL<<30;
	FOR(i,M) {
		cin>>x>>y>>k;
		E[x-1][y-1]=E[y-1][x-1]=k;
	}
	ll ret=1LL<<60;
	
	FOR(i,N) {
		vector<ll> V=hoge(i);
		ll mco=V[0];
		int ta=V[1],tb=V[2];
		if(ta>=0) {
			set<int> S;
			
			if(tb==i) {
				x=L[ta];
				y=tb;
			}
			else {
				x=L[ta];
				y=L[tb];
			}
			
			while(ta!=i) S.insert(ta), ta=pre[ta];
			while(tb!=i) S.insert(tb), tb=pre[tb];
			FOR(j,N) if(S.count(j)==0) ret=min(ret,mco+E[i][j]);
			
			k=E[i][x];
			E[i][x]=E[x][i]=1<<30;
			auto W=hoge(i);
			ret=min(ret,W[0]+k);
			E[i][x]=E[x][i]=k;
			
			k=E[i][y];
			E[i][y]=E[y][i]=1<<30;
			W=hoge(i);
			ret=min(ret,W[0]+k);
			E[i][y]=E[y][i]=k;
			
		}
		
	}
	
	
	
	if(ret>=1LL<<30) ret=-1;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
