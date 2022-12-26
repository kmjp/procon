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

int N;
vector<int> E[202020];
const ll mo=998244353;
ll dp[202020][3][3];

pair<int,int> farthest(int cur,int pre,int d,vector<int>& D) {
	D[cur]=d;
	pair<int,int> r={d,cur};
	FORR(e,E[cur]) if(e!=pre) r=max(r, farthest(e,cur,d+1,D));
	return r;
}

pair<int,vector<int>> diameter() { // diameter,center
	vector<int> D[2];
	D[0].resize(N);
	D[1].resize(N);
	auto v1=farthest(0,0,0,D[0]);
	auto v2=farthest(v1.second,v1.second,0,D[0]);
	farthest(v2.second,v2.second,0,D[1]);
	pair<int,vector<int>> R;
	R.first = v2.first;
	//dS‚ðŽæ‚éê‡
	for(int i=N-1;i>=0;i--) if(D[0][i]+D[1][i]==R.first && abs(D[0][i]-D[1][i])<=1) R.second.push_back(i);

	return R;
}

void dfs(int cur,int pre,int lef) {
	if(lef==0) {
		dp[cur][1][1]=1;
	}
	else {
		dp[cur][0][0]=1;
	}
	
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur,lef-1);
		ll to[3][3]={};
		int a1,a2,b1,b2;
		FOR(a1,3) FOR(a2,3) FOR(b1,3) FOR(b2,3) {
			// +1
			to[min(a1+b1,2)][a2]+=dp[cur][a1][a2]*dp[e][b1][b2]%mo;
			// 0
			to[a1][a2]+=dp[cur][a1][a2]*dp[e][b1][b2]%mo;
			// -1
			to[a1][min(a2+b2,2)]+=dp[cur][a1][a2]*dp[e][b1][b2]%mo;
		}
		
		FOR(a1,3) FOR(a2,3) dp[cur][a1][a2]=to[a1][a2]%mo;
	}
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	auto R=diameter();
	if(R.second.size()==1) {
		x=R.second[0];
		dfs(x,-1,R.first/2);
		cout<<dp[x][1][1]*((mo+1)/2)%mo<<endl;
	}
	else {
		x=R.second[0];
		y=R.second[1];
		dfs(x,y,R.first/2);
		dfs(y,x,R.first/2);
		ll X=(dp[x][0][1]+dp[x][1][1]+dp[x][2][1])%mo;
		ll Y=(dp[y][0][1]+dp[y][1][1]+dp[y][2][1])%mo;
		cout<<X*Y%mo<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
