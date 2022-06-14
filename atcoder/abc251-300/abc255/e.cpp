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
ll S[101010];
ll A[101010];
ll X[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	unordered_map<ll,int> C[2];
	FOR(i,N-1) {
		cin>>S[i];
		A[i+1]=S[i]-A[i];
	}
	FOR(i,N) {
		C[i%2][A[i]]++;
	}
	FOR(i,M) cin>>X[i];
	
	ll ma=0;
	FORR2(a,b,C[0]) {
		FOR(i,M) {
			ll v=X[i]-a;
			ll num=0;
			FOR(j,M) {
				if(C[0].count(X[j]-v)) num+=C[0][X[j]-v];
				if(C[1].count(X[j]+v)) num+=C[1][X[j]+v];
			}
			ma=max(ma,num);
		}
	}
	FORR2(a,b,C[1]) {
		FOR(i,M) {
			ll v=X[i]+a;
			ll num=0;
			FOR(j,M) {
				if(C[0].count(X[j]-v)) num+=C[0][X[j]-v];
				if(C[1].count(X[j]+v)) num+=C[1][X[j]+v];
			}
			ma=max(ma,num);
		}
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
