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

int N,M[3];
vector<int> E[3][101010];
const ll mo=998244353;
ll p10[20];
ll pv[303030];

int ok[3][303030];

ll from[1010];
ll dp[1010];
ll to[1010];



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll sum=0;

	p10[0]=1;
	FOR(i,19) p10[i+1]=p10[i]*10%mo;
	pv[0]=1;
	FOR(i,302020) pv[i+1]=pv[i]*p10[18]%mo;
	
	from[0]=1;
	FOR(i,3) {
		cin>>M[i];
		FOR(j,M[i]) {
			cin>>x>>y;
			E[i][x-1].push_back(y-1);
			E[i][y-1].push_back(x-1);
		}
		ZERO(dp);
		for(j=N-1;j>=0;j--) {
			set<int> S;
			FORR(e,E[i][j]) if(e>j) S.insert(ok[i][e]);
			while(S.count(ok[i][j])) ok[i][j]++;
			(dp[ok[i][j]]+=pv[j+1])%=mo;
		}
		ZERO(to);
		FOR(x,1000) FOR(y,1000) {
			(to[x^y]+=from[x]*dp[y])%=mo;
		}
		swap(from,to);
	}
	
	cout<<from[0]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
