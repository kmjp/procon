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

int N,K;
vector<int> E[101010];
int ma=-1;
int V[101010];
int dp[101010];

void dfs(int cur,int pre) {
	V[cur]=1;
	vector<pair<int,int>> P;
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur);
		V[cur]+=V[e];
		P.push_back({dp[e],V[e]>=K});
	}
	sort(ALL(P));
	reverse(ALL(P));
	if(P.empty()) return;
	// take 1
	int tot=0,i;
	FOR(i,P.size()) {
		if(i==0) tot+=P[i].first;
		else tot+=P[i].second;
	}
	dp[cur]=tot;
	ma=max(ma,tot+((N-V[cur])>=K));

	tot=0;
	FOR(i,P.size()-1) tot+=P[i].second;
	ma=max(ma,tot+((N-V[cur])>=K));
	
	tot=0;
	FOR(i,P.size()) tot+=P[i].second;
	dp[cur]=max(dp[cur],tot);
	
	
	
	
	if(P.size()>=2) {
		tot=(N-V[cur])>=K;
		FOR(i,P.size()) {
			if(i<=1) tot+=P[i].first;
			else tot+=P[i].second;
		}
		ma=max(ma,tot);
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	dfs(0,-1);
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
