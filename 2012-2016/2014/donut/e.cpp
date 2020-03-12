#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,E;
vector<pair<int,int>> V[16];
int dp[1<<16];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>E;
	FOR(i,E) {
		cin>>x>>y>>r;
		V[y-1].push_back({x-1,r});
	}
	FOR(i,1<<N) dp[i]=-1<<30;
	dp[0]=0;
	for(int mask=0;mask<1<<N;mask++) {
		FOR(i,N) if((mask&(1<<i))==0) {
			int tot=dp[mask];
			FORR(v,V[i]) if(mask&(1<<v.first)) tot+=v.second;
			dp[mask|(1<<i)]=max(dp[mask|(1<<i)],tot);
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
