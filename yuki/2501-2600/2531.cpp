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

int N,K;
set<int> E[202020];

ll dp[202020][2];
const ll mo=998244353;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>x>>y;
		x--,y--;
		E[x].insert(y);
		E[y].insert(x);
	}
	queue<int> Q;
	FOR(i,N) if(E[i].size()==1) Q.push(i);
	int num=N;
	while(Q.size()) {
		x=Q.front();
		Q.pop();
		num--;
		FORR(e,E[x]) {
			E[e].erase(x);
			if(E[e].size()==1) Q.push(e);
		}
	}
	
	dp[0][0]=K;
	dp[0][1]=0;
	FOR(i,num-1) {
		dp[i+1][0]=dp[i][1];
		(dp[i+1][1]=dp[i][0]*(K-1)+dp[i][1]*(K-2))%=mo;
	}
	ll ret=dp[num-1][1];
	FOR(i,N-num) ret=ret*(K-1)%mo;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
