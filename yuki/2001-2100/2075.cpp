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

ll N;
ll dp[1000001];
int pat[1010101];
const ll mo=998244353;
set<ll> enumpr(ll n) {
	set<ll> V;
	for(ll i=2;i*i<=n;i++) while(n%i==0) V.insert(i),n/=i;
	if(n>1) V.insert(n);
	return V;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll ret=0;
	while(N--) {
		cin>>x;
		if(x==1) {
			ret++;
			continue;
		}
		set<ll> S=enumpr(x);
		vector<int> V;
		FORR(s,S) V.push_back(s);
		ll ret=1;
		int M=V.size();
		for(int mask=0;mask<1<<M;mask++) if(mask) {
			int v=-1;
			FOR(i,M) if(mask&(1<<i)) v=-v*V[i];
			if(v>0) {
				ret+=dp[v];
				pat[v]=1;
			}
			else {
				ret+=mo-dp[-v];
				pat[-v]=-1;
			}
		}
		ret%=mo;
		for(int mask=0;mask<1<<M;mask++) if(mask) {
			int v=1;
			FOR(i,M) if(mask&(1<<i)) v=v*V[i];
			(dp[v]+=ret)%=mo;
		}
	}
	FOR(i,1000001) ret+=dp[i]*pat[i];
	cout<<(ret%mo+mo)%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
