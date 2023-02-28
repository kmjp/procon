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

int N,Q;
ll A[1<<17][18],B[1<<17][18],C[1<<17][35];
const ll mo=998244353;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,1<<N) cin>>A[i][__builtin_popcount(i)];
	FOR(i,1<<N) cin>>B[i][__builtin_popcount(i)];
	FOR(i,N+1) {
		FOR(j,N+1) {
			FOR(x,1<<N) if(x&(1<<j)) {
				(A[x][i]+=A[x^(1<<j)][i])%=mo;
				(B[x][i]+=B[x^(1<<j)][i])%=mo;
			}
		}
	}
	FOR(i,N+1) FOR(j,N+1) FOR(x,1<<N) (C[x][i+j]+=A[x][i]*B[x][j])%=mo;
	FOR(i,2*N+1) {
		FOR(j,N+1) {
			FOR(x,1<<N) if(x&(1<<j)) {
				(C[x][i]+=mo-C[x^(1<<j)][i])%=mo;
			}
		}
	}
	
	while(Q--) {
		cin>>x>>y;
		cout<<C[x][y]<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
