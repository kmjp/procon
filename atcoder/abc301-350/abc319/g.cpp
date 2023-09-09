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
set<int> E[202020];
const ll mo=998244353;
ll dp[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].insert(y-1);
		E[y-1].insert(x-1);
	}
	set<int> alive,nex;
	FOR(i,N) if(i) alive.insert(i);
	nex.insert(0);
	dp[0]=1;
	while(nex.size()) {
		if(nex.count(N-1)) {
			cout<<dp[N-1]<<endl;
			return;
		}
		set<int> nex2;
		swap(nex,nex2);
		ll sum=0;
		FORR(c,nex2) sum+=dp[c];
		sum%=mo;
		FORR(a,alive) {
			int ok=0;
			FORR(b,nex2) {
				if(E[b].count(a)==0) {
					ok=1;
					break;
				}
			}
			if(ok) {
				nex.insert(a);
				dp[a]=sum;
				FORR(b,E[a]) if(nex2.count(b)) dp[a]+=mo-dp[b];
				dp[a]%=mo;
			}
		}
		FORR(n,nex) alive.erase(n);
	}
	cout<<-1<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
