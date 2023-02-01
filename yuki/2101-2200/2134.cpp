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
const ll mo=998244353;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	vector<vector<int>> V;
	V.resize(1);
	FOR(i,N) V[0].push_back(i);
	FOR(i,M) {
		int dp[1010]={};
		cin>>x;
		while(x--) {
			cin>>y;
			dp[y-1]=1;
		}
		vector<vector<int>> W;
		FORR(v,V) {
			vector<int> A[2];
			FORR(a,v) A[dp[a]].push_back(a);
			FOR(j,2) if(A[j].size()) W.push_back(A[j]);
		}
		V=W;
	}
	ll ret=1;
	FOR(i,V.size()) ret=ret*2%mo;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
