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

int N,M,K;
vector<int> E[202020];
int A[202020];
int B[202020];
int dp[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	FOR(i,N) {
		cin>>A[i];
		A[i]--;
	}
	FOR(i,K) {
		cin>>B[i];
		B[i]--;
	}
	
	FOR(i,N) dp[i]=1<<20;
	dp[0]=(A[0]==B[0]?1:0);
	priority_queue<pair<int,int>> Q;
	Q.push({-dp[0],0});
	while(Q.size()) {
		int cur=Q.top().second;
		int sc=-Q.top().first;
		Q.pop();
		if(sc!=dp[cur]) continue;
		if(cur==N-1&&sc<K) {
			cout<<"No"<<endl;
			return;
		}
		FORR(e,E[cur]) {
			int nsc=sc;
			if(nsc<K&&A[e]==B[nsc]) nsc++;
			if(nsc<dp[e]) {
				dp[e]=nsc;
				Q.push({-nsc,e});
			}
		}
		
	}
	cout<<"Yes"<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
