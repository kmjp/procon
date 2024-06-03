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

int M,N;
int P[5050];
ll dp[5050];
int R[5050];
bitset<5120> NG[5050],E;
vector<int> C[5050];


void solve() {
	int i,j,k,l,r,x,y; string s;
	scanf("%d%d",&M,&N);
	FOR(i,N) {
		scanf("%d",&P[i]);
	}
	FOR(y,M) {
		FOR(x,N) C[x].clear();
		FOR(x,N) {
			scanf("%d",&R[x]);
			C[R[x]-1].push_back(x);
		}
		E.reset();
		for(x=N-1;x>=0;x--) {
			FORR(a,C[x]) E[a]=1;
			FORR(a,C[x]) NG[a]|=E;
		}
	}
	vector<pair<int,int>> V;
	FOR(i,N) V.push_back({R[i],i});
	sort(ALL(V));
	
	ll ma=0;
	FORR2(a,i,V) {
		dp[i]=0;
		FOR(x,N) {
			if(NG[i][x]==0) dp[i]=max(dp[i],dp[x]);
		}
		dp[i]+=P[i];
		ma=max(ma,dp[i]);
	}
	cout<<ma<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
