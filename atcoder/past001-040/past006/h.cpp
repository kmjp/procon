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

int N,M,K,Q;
vector<int> A[2];
vector<ll> S[2];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K>>Q;
	FOR(i,N) {
		cin>>x>>y;
		A[y].push_back(x);
	}
	FOR(i,2) {
		sort(ALL(A[i]));
		S[i].push_back(0);
		FORR(a,A[i]) S[i].push_back(S[i].back()+a);
	}
	ll ret=1LL<<60;
	for(i=0;i<=min((int)A[0].size(),M);i++) {
		j=M-i;
		if(j>A[1].size()) continue;
		ll sum=S[0][i]+S[1][j]+1LL*(j+K-1)/K*Q;
		ret=min(ret,sum);
	}
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
