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

int T;
int N;
int P[303030],D[303030];
vector<int> E[303030];
vector<int> Ds[303030];
ll dp[303030];
const ll mo=998244353;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) E[i].clear(),Ds[i].clear();
		Ds[0].push_back(0);
		for(i=1;i<N;i++) {
			cin>>P[i];
			P[i]--;
			E[P[i]].push_back(i);
			D[i]=D[P[i]]+1;
			Ds[D[i]].push_back(i);
		}
		ll ret=1;
		dp[0]=1;
		for(i=1;i<N;i++) {
			ll par=0;
			FORR(e,Ds[i-1]) (par+=dp[e])%=mo;
			FORR(e,Ds[i]) {
				dp[e]=par;
				if(P[e]!=0) (dp[e]+=mo-dp[P[e]])%=mo;
				ret+=dp[e];
			}
		}
		cout<<ret%mo<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
