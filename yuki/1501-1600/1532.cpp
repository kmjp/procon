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

int N;
ll K;

ll L[202][101010];
ll R[202][101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	L[0][1]=1;
	R[N+1][1]=1;
	for(i=N;i>=1;i--) {
		for(j=1;j<=100000;j++) {
			R[i][j]+=R[i+1][j];
			if(j*i<=100000) R[i][j*i]+=R[i+1][j];
			R[i+1][j]+=R[i+1][j-1];
		}
	}
	
	ll ret=0;
	for(i=1;i<=min(100000LL,K);i++) ret+=R[1][i];
	
	for(i=1;i<=N;i++) {
		for(j=1;j<=100000;j++) {
			L[i][j]+=L[i-1][j];
			ll a=1LL*i*j;
			if(a<=100000) {
				L[i][a]+=L[i-1][j];
			}
			else if(a<=K) ret+=L[i-1][j]*R[i+1][K/a];
		}
	}
	ret--;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
