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
vector<pair<int,ll>> E[201010];
const ll mo=1000000007;
ll pat;
ll C[2];

void dfs(int cur,int pre,int id,int d) {
	C[id]++;
	FORR2(e,c,E[cur]) if(e!=pre) {
		if(c&(1LL<<d)) {
			dfs(e,cur,id^1,d);
		}
		else {
			dfs(e,cur,id,d);
		}
		
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		ll a;
		cin>>x>>y>>a;
		E[x-1].push_back({y-1,a});
		E[y-1].push_back({x-1,a});
	}
	
	ll ret=0;
	FOR(i,60) {
		ZERO(C);
		dfs(0,0,0,i);
		
		(ret+=C[0]*C[1]%mo*((1LL<<i)%mo))%=mo;
		
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
