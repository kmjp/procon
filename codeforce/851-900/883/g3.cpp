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
int N,M;
int C;
int D[1010],A[1010],B[1010];
int dp[1<<10];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		C=0;
		cin>>s;
		FOR(i,N) {
			if(s[i]=='1') C|=1<<i;
		}
		FOR(i,M) {
			cin>>D[i];
			A[i]=B[i]=0;
			cin>>s;
			FOR(j,N) if(s[j]=='0') A[i]|=1<<j;
			cin>>s;
			FOR(j,N) if(s[j]=='1') B[i]|=1<<j;
		}
		int mask;
		FOR(mask,1<<10) dp[mask]=1<<30;
		dp[C]=0;
		priority_queue<pair<int,int>> Q;
		Q.push({0,C});
		while(Q.size()) {
			int co=-Q.top().first;
			int cur=Q.top().second;
			Q.pop();
			if(dp[cur]!=co) continue;
			FOR(i,M) {
				int nmask=(cur&A[i])|B[i];
				if(chmin(dp[nmask],co+D[i])) {
					Q.push({-dp[nmask],nmask});
				}
			}
		}
		ll ret=dp[0];
		if(ret>=1<<30) ret=-1;
		cout<<ret<<endl;
	}
			
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
