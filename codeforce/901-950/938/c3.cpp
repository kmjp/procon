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

int T,N;
ll K,A[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		ll S=0;
		FOR(i,N) {
			cin>>A[i];
			S+=A[i];
		}
		if(K>=S) {
			cout<<N<<endl;
			continue;
		}
		ll a=(K+1)/2;
		ll b=K-a;
		FOR(i,N) {
			ll v=min(a,A[i]);
			a-=v;
			A[i]-=v;
		}
		a=b;
		for(i=N-1;i>=0;i--) {
			ll v=min(a,A[i]);
			a-=v;
			A[i]-=v;
		}
		int ret=0;
		FOR(i,N) if(A[i]==0) ret++;
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
