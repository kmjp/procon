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


ll N,M;
map<ll,vector<pair<ll,ll>>> E;
map<ll,ll> D;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	E[1]=E[N]={};
	FOR(i,M) {
		ll a,b,c;
		cin>>a>>b>>c;
		E[a].push_back({b,c});
		E[b].push_back({a,c});
	}
	ll pre=-1;
	FORR2(a,b,E) {
		D[a]=1LL<<60;
		if(pre>=1) {
			E[a].push_back({pre,a-pre});
			E[pre].push_back({a,a-pre});
		}
		pre=a;
	}
	priority_queue<pair<ll,ll>> Q;
	D[1]=0;
	Q.push({0,1});
	while(Q.size()) {
		ll co=-Q.top().first;
		ll cur=Q.top().second;
		Q.pop();
		if(D[cur]!=co) continue;
		FORR2(e,c,E[cur]) {
			if(D[e]>co+c) {
				D[e]=co+c;
				Q.push({-D[e],e});
			}
		}
	}
	cout<<D[N]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
