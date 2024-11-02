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
ll K;
ll A[2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		FOR(i,N) cin>>A[i];
		sort(A,A+N);
		ll ret;
		if(K>=3) {
			ret=0;
		}
		else {
			ret=A[0];
			FOR(i,N-1) ret=min(ret,A[i+1]-A[i]);
			if(K==2) {
				vector<ll> V;
				FOR(i,N) V.push_back(A[i]);
				FOR(x,N) FOR(y,x) {
					ll a=A[x]-A[y];
					k=lower_bound(A,A+N,a)-A;
					for(i=max(0,k-2);i<min(k+2,N);i++) ret=min(ret,abs(a-A[i]));
				}
			}
		}
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
