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
string S;

int pre[1<<22];
vector<int> cand[1<<22];
ll dp[1<<22];
const ll mo=998244353;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	int mask;
	FOR(mask,1<<N) {
		pre[mask]=mask;
		FOR(x,N) if(mask&(1<<x)) {
			for(y=x-1;y>=0;y--) {
				if(mask&(1<<y)) break;
				if(S[x]==S[y]) {
					int nmask=mask^(1<<x)^(1<<y);
					pre[mask]=pre[nmask];
				}
			}
		}
		cand[pre[mask]].push_back(mask);
	}
	
	dp[0]=1;
	FOR(mask,1<<N) if(dp[mask]) {
		set<int> S;
		FORR(m,cand[mask]) {
			FOR(i,N) if((m&(1<<i))==0) {
				int nmask=pre[m^(1<<i)];
				if(S.count(nmask)==0) {
					(dp[nmask]+=dp[mask])%=mo;
					S.insert(nmask);
				}
			}
		}
	}
	cout<<dp[(1<<N)-1]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
