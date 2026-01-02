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
set<pair<int,int>> NG[202020];
map<int,int> E[202020];
map<int,ll> dp[202020];
int K;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y>>k;
		x--,y--;
		if(E[x].count(y)) E[x][y]=min(E[x][y],k);
		else E[x][y]=k;
	}
	cin>>K;
	FOR(i,K) {
		cin>>x>>y>>k;
		NG[y-1].insert({x-1,k-1});
	}
	dp[0][-1]=0;
	ll ret=1LL<<60;
	FOR(i,N) {
		vector<pair<ll,int>> cand;
		FORR2(a,b,dp[i]) cand.push_back({b,a});
		sort(ALL(cand));
		FORR2(co,from,cand) {
			vector<int> del;
			if(i==N-1) ret=min(ret,co);
			FORR2(e,c,E[i]) {
				if(NG[i].count({from,e})) continue;
				del.push_back(e);
				if(dp[e].count(i)==0||dp[e][i]>co+c) dp[e][i]=co+c;
			}
			FORR(d,del) E[i].erase(d);
		}
	}
	
	if(ret==1LL<<60) ret=-1;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
